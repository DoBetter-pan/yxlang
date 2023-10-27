/** 
 * @file scanner.h
 * @brief 
 * @author yingxue
 * @date 2023-10-26
 */

%{ /*** C/C++ Declarations ***/

#include <string>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef yxlang::Parser::token token;
typedef yxlang::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++ on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "YxlangFlexLexer" */
%option prefix="Yxlang"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN EXAMPLE - Change the yxlang lexer rules below ***/

"+" |
"-" |
"*" |
"/" |
"%" |
"=" |
"|" |
"," |
";" |
"(" |
")"    { return static_cast<token_type>(*yytext); }

">"    { yylval->fn = 1; return token::CMP; }
"<"    { yylval->fn = 2; return token::CMP; }
"<>"   { yylval->fn = 3; return token::CMP; }
"=="   { yylval->fn = 4; return token::CMP; }
">="   { yylval->fn = 5; return token::CMP; }
"<="   { yylval->fn = 6; return token::CMP; }

"if"   { return token::IF; }
"then" { return token::THEN; }
"else" { return token::ELSE; }
"fi"   { return token::FI; }
"let"  { return token::LET; }

"sqrt"  { yylval->fn = 1; return token::UNARYFUNC; }
"exp"   { yylval->fn = 2; return token::UNARYFUNC; }
"log"   { yylval->fn = 3; return token::UNARYFUNC; }
"print" { yylval->fn = 4; return token::UNARYFUNC; }
"pow"   { yylval->fn = 1; return token::BINARYFUNC; }

[0-9]+ { yylval->integerVal = atoi(yytext); return token::INTEGER; }

[0-9]+"."[0-9]* { yylval->doubleVal = atof(yytext); return token::DOUBLE; }

 /* [A-Za-z][A-Za-z0-9_,.-]* { yylval->stringVal = new std::string(yytext, yyleng); return token::STRING; } */
[A-Za-z][A-Za-z0-9_.-]* { yylval->stringVal = new std::string(yytext, yyleng); return token::STRING; }

 /* gobble up white-spaces */
[ \t\r]+ { yylloc->step(); }

 /* gobble up end-of-lines */
\n { yylloc->lines(yyleng); yylloc->step(); return token::EOL; }

 /* pass all other characters up to bison */
. { return static_cast<token_type>(*yytext); }

 /*** END EXAMPLE - Change the yxlang lexer rules above ***/

%% /*** Additional Code ***/

namespace yxlang {

Scanner::Scanner(std::istream* in, std::ostream* out) : YxlangFlexLexer(in, out) {
}

Scanner::~Scanner() {
}

void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
}

}

/* This implementation of YxlangFlexLexer::yylex() is required to fill the
 * vtable of the class YxlangFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int YxlangFlexLexer::yylex() {
    std::cerr << "in YxlangFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int YxlangFlexLexer::yywrap() {
    return 1;
}
