/** 
 * @file parser.yy
 * @brief calc expression 
 * @author yingxue
 * @date 2023-10-26
 */

%{

#include <stdio.h>
#include <string>
#include <vector>

#include "expression.h"

%}

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release * versions. */
%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%define api.prefix {yxlang}

/* set the parser's class identifier */
%define api.parser.class {Parser}

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%define parse.error verbose
/* %error-verbose */

/*** BEGIN YXLANG - Change the yxlang grammar's tokens below ***/

%union {
    int  			    integerVal;
    double 			    doubleVal;
    std::string*		stringVal;
    class YxlangNode*	yxlangnode;
    int                 fn;
}

%token IF THEN ELSE FI LET

%token			     END	    0	"end of file"
%token			     EOL		"end of line"
%token <integerVal>  INTEGER	"integer"
%token <doubleVal> 	 DOUBLE		"double"
%token <stringVal> 	 STRING		"string"

%type <yxlangnode>	    constant variable
%type <yxlangnode>	    atomexpr expr exprlist assignment ifstmt paramlist funcstmt stmt sentencelist stmtlist

%destructor { delete $$; } STRING
%destructor { delete $$; } constant variable
%destructor { delete $$; } atomexpr expr exprlist assignment ifstmt funcstmt stmt sentencelist stmtlist

%nonassoc <fn> CMP UNARYFUNC BINARYFUNC
%right '='
%left '+' '-'
%left '*' '/' '%'

/*** END YXLANG - Change the yxlang grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN YXLANG - Change the yxlang grammar rules below ***/

constant : INTEGER {
	       $$ = new CNConstant($1);
	     }
         | DOUBLE {
	       $$ = new CNConstant($1);
	     }

variable : STRING {
           $$ = new CNVariable($1);
	     }

atomexpr : constant {
	       $$ = $1;
	     }
         | variable {
	       $$ = $1;
	     }
         | '(' expr ')' {
	       $$ = $2;
	     }

expr : expr '+' expr {
	   $$ = new CNAdd($1, $3);
     }
     | expr '-' expr {
	   $$ = new CNSubtract($1, $3);
     }
     | expr '*' expr {
	   $$ = new CNMultiply($1, $3);
     }
     | expr '/' expr {
	   $$ = new CNDivide($1, $3);
     }
     | expr '%' expr {
	   $$ = new CNModulo($1, $3);
     }
     | expr CMP expr {
	   $$ = new CNCompare($2, $1, $3);
     }
     | UNARYFUNC '(' expr ')' {
	   $$ = new CNUnaryFunction($1, $3);
     }
     | BINARYFUNC '(' expr ',' expr ')' {
	   $$ = new CNBinaryFunction($1, $3, $5);
     }
     | STRING '(' exprlist ')' {
	   $$ = new CNCallUDF($1, $3);
     }
     | atomexpr

exprlist : expr {
           $$ = new CNExprlist($1, NULL);
         }
         | expr ',' exprlist {
           $$ = new CNExprlist($1, $3);
         }

assignment : STRING '=' expr {
           $$ = new CNAssignment($1, $3);
	     }

ifstmt : IF expr THEN sentencelist FI  {
         $$ = new CNCondition($2, $4, NULL);
       }
       | IF expr THEN sentencelist ELSE sentencelist FI {
         $$ = new CNCondition($2, $4, $6);
       }

funcstmt : LET STRING '(' paramlist ')' '=' sentencelist {
           $$ = new CNCustomFunction($2, $4, $7);
         }

paramlist : STRING {
            $$ = new CNParamlist($1, NULL);
          }
          | STRING ',' paramlist {
            $$ = new CNParamlist($1, $3);
          }

stmt   : expr
       | ifstmt
       | assignment
       | funcstmt

sentencelist : { $$ = NULL; }
         | stmt ';' sentencelist {
           if ($3 == NULL) {
             $$ = $1;
           } else {
             $$ = new CNStatement($1, $3);
           }
         }

stmtlist : { $$ = NULL; }
         | stmt EOL stmtlist {
           if ($3 == NULL) {
             $$ = $1;
           } else {
             $$ = new CNStatement($1, $3);
           }
         }
         | stmt END stmtlist {
           if ($3 == NULL) {
             $$ = $1;
           } else {
             $$ = new CNStatement($1, $3);
           }
         }

start : 
      stmtlist { driver.calc.expressions.push_back($1); }      

 /*** END YXLANG - Change the yxlang grammar rules above ***/

%% /*** Additional Code ***/

void yxlang::Parser::error(const Parser::location_type& l, const std::string& m) {
    driver.error(l, m);
}
