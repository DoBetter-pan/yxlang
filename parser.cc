// A Bison parser, made by GNU Bison 3.8.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   yxlanglex

// First part of user prologue.
#line 8 "parser.yy"


#include <stdio.h>
#include <string>
#include <vector>

#include "expression.h"


#line 53 "parser.cc"


#include "parser.h"

// Second part of user prologue.
#line 88 "parser.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 72 "parser.cc"



#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YXLANGDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YXLANGDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YXLANGDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yxlang {
#line 165 "parser.cc"

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
#if YXLANGDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.kind ())
    {
      case symbol_kind::S_STRING: // "string"
#line 77 "parser.yy"
                    { delete (yysym.value.stringVal); }
#line 371 "parser.cc"
        break;

      case symbol_kind::S_constant: // constant
#line 78 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 377 "parser.cc"
        break;

      case symbol_kind::S_variable: // variable
#line 78 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 383 "parser.cc"
        break;

      case symbol_kind::S_atomexpr: // atomexpr
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 389 "parser.cc"
        break;

      case symbol_kind::S_expr: // expr
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 395 "parser.cc"
        break;

      case symbol_kind::S_exprlist: // exprlist
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 401 "parser.cc"
        break;

      case symbol_kind::S_assignment: // assignment
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 407 "parser.cc"
        break;

      case symbol_kind::S_ifstmt: // ifstmt
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 413 "parser.cc"
        break;

      case symbol_kind::S_funcstmt: // funcstmt
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 419 "parser.cc"
        break;

      case symbol_kind::S_stmt: // stmt
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 425 "parser.cc"
        break;

      case symbol_kind::S_sentencelist: // sentencelist
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 431 "parser.cc"
        break;

      case symbol_kind::S_stmtlist: // stmtlist
#line 79 "parser.yy"
                    { delete (yysym.value.yxlangnode); }
#line 437 "parser.cc"
        break;

      default:
        break;
    }
  }

#if YXLANGDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YXLANGDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YXLANGDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 42 "parser.yy"
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 580 "parser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // constant: "integer"
#line 105 "parser.yy"
                   {
	       (yylhs.value.yxlangnode) = new CNConstant((yystack_[0].value.integerVal));
	     }
#line 720 "parser.cc"
    break;

  case 3: // constant: "double"
#line 108 "parser.yy"
                  {
	       (yylhs.value.yxlangnode) = new CNConstant((yystack_[0].value.doubleVal));
	     }
#line 728 "parser.cc"
    break;

  case 4: // variable: "string"
#line 112 "parser.yy"
                  {
           (yylhs.value.yxlangnode) = new CNVariable((yystack_[0].value.stringVal));
	     }
#line 736 "parser.cc"
    break;

  case 5: // atomexpr: constant
#line 116 "parser.yy"
                    {
	       (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode);
	     }
#line 744 "parser.cc"
    break;

  case 6: // atomexpr: variable
#line 119 "parser.yy"
                    {
	       (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode);
	     }
#line 752 "parser.cc"
    break;

  case 7: // atomexpr: '(' expr ')'
#line 122 "parser.yy"
                        {
	       (yylhs.value.yxlangnode) = (yystack_[1].value.yxlangnode);
	     }
#line 760 "parser.cc"
    break;

  case 8: // expr: expr '+' expr
#line 126 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNAdd((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 768 "parser.cc"
    break;

  case 9: // expr: expr '-' expr
#line 129 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNSubtract((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 776 "parser.cc"
    break;

  case 10: // expr: expr '*' expr
#line 132 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNMultiply((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 784 "parser.cc"
    break;

  case 11: // expr: expr '/' expr
#line 135 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNDivide((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 792 "parser.cc"
    break;

  case 12: // expr: expr '%' expr
#line 138 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNModulo((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 800 "parser.cc"
    break;

  case 13: // expr: expr CMP expr
#line 141 "parser.yy"
                     {
	   (yylhs.value.yxlangnode) = new CNCompare((yystack_[1].value.fn), (yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
     }
#line 808 "parser.cc"
    break;

  case 14: // expr: UNARYFUNC '(' expr ')'
#line 144 "parser.yy"
                              {
	   (yylhs.value.yxlangnode) = new CNUnaryFunction((yystack_[3].value.fn), (yystack_[1].value.yxlangnode));
     }
#line 816 "parser.cc"
    break;

  case 15: // expr: BINARYFUNC '(' expr ',' expr ')'
#line 147 "parser.yy"
                                        {
	   (yylhs.value.yxlangnode) = new CNBinaryFunction((yystack_[5].value.fn), (yystack_[3].value.yxlangnode), (yystack_[1].value.yxlangnode));
     }
#line 824 "parser.cc"
    break;

  case 16: // expr: "string" '(' exprlist ')'
#line 150 "parser.yy"
                               {
	   (yylhs.value.yxlangnode) = new CNCallUDF((yystack_[3].value.stringVal), (yystack_[1].value.yxlangnode));
     }
#line 832 "parser.cc"
    break;

  case 17: // expr: atomexpr
#line 153 "parser.yy"
       { (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode); }
#line 838 "parser.cc"
    break;

  case 18: // exprlist: expr
#line 155 "parser.yy"
                {
           (yylhs.value.yxlangnode) = new CNExprlist((yystack_[0].value.yxlangnode), NULL);
         }
#line 846 "parser.cc"
    break;

  case 19: // exprlist: expr ',' exprlist
#line 158 "parser.yy"
                             {
           (yylhs.value.yxlangnode) = new CNExprlist((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
         }
#line 854 "parser.cc"
    break;

  case 20: // assignment: "string" '=' expr
#line 162 "parser.yy"
                             {
           (yylhs.value.yxlangnode) = new CNAssignment((yystack_[2].value.stringVal), (yystack_[0].value.yxlangnode));
	     }
#line 862 "parser.cc"
    break;

  case 21: // ifstmt: IF expr THEN sentencelist FI
#line 166 "parser.yy"
                                       {
         (yylhs.value.yxlangnode) = new CNCondition((yystack_[3].value.yxlangnode), (yystack_[1].value.yxlangnode), NULL);
       }
#line 870 "parser.cc"
    break;

  case 22: // ifstmt: IF expr THEN sentencelist ELSE sentencelist FI
#line 169 "parser.yy"
                                                        {
         (yylhs.value.yxlangnode) = new CNCondition((yystack_[5].value.yxlangnode), (yystack_[3].value.yxlangnode), (yystack_[1].value.yxlangnode));
       }
#line 878 "parser.cc"
    break;

  case 23: // funcstmt: LET "string" '(' paramlist ')' '=' sentencelist
#line 173 "parser.yy"
                                                         {
           (yylhs.value.yxlangnode) = new CNCustomFunction((yystack_[5].value.stringVal), (yystack_[3].value.yxlangnode), (yystack_[0].value.yxlangnode));
         }
#line 886 "parser.cc"
    break;

  case 24: // paramlist: "string"
#line 177 "parser.yy"
                   {
            (yylhs.value.yxlangnode) = new CNParamlist((yystack_[0].value.stringVal), NULL);
          }
#line 894 "parser.cc"
    break;

  case 25: // paramlist: "string" ',' paramlist
#line 180 "parser.yy"
                                 {
            (yylhs.value.yxlangnode) = new CNParamlist((yystack_[2].value.stringVal), (yystack_[0].value.yxlangnode));
          }
#line 902 "parser.cc"
    break;

  case 26: // stmt: expr
#line 184 "parser.yy"
         { (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode); }
#line 908 "parser.cc"
    break;

  case 27: // stmt: ifstmt
#line 185 "parser.yy"
         { (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode); }
#line 914 "parser.cc"
    break;

  case 28: // stmt: assignment
#line 186 "parser.yy"
         { (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode); }
#line 920 "parser.cc"
    break;

  case 29: // stmt: funcstmt
#line 187 "parser.yy"
         { (yylhs.value.yxlangnode) = (yystack_[0].value.yxlangnode); }
#line 926 "parser.cc"
    break;

  case 30: // sentencelist: %empty
#line 189 "parser.yy"
               { (yylhs.value.yxlangnode) = NULL; }
#line 932 "parser.cc"
    break;

  case 31: // sentencelist: stmt ';' sentencelist
#line 190 "parser.yy"
                                 {
           if ((yystack_[0].value.yxlangnode) == NULL) {
             (yylhs.value.yxlangnode) = (yystack_[2].value.yxlangnode);
           } else {
             (yylhs.value.yxlangnode) = new CNStatement((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
           }
         }
#line 944 "parser.cc"
    break;

  case 32: // stmtlist: %empty
#line 198 "parser.yy"
           { (yylhs.value.yxlangnode) = NULL; }
#line 950 "parser.cc"
    break;

  case 33: // stmtlist: stmt "end of line" stmtlist
#line 199 "parser.yy"
                             {
           if ((yystack_[0].value.yxlangnode) == NULL) {
             (yylhs.value.yxlangnode) = (yystack_[2].value.yxlangnode);
           } else {
             (yylhs.value.yxlangnode) = new CNStatement((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
           }
         }
#line 962 "parser.cc"
    break;

  case 34: // stmtlist: stmt "end of file" stmtlist
#line 206 "parser.yy"
                             {
           if ((yystack_[0].value.yxlangnode) == NULL) {
             (yylhs.value.yxlangnode) = (yystack_[2].value.yxlangnode);
           } else {
             (yylhs.value.yxlangnode) = new CNStatement((yystack_[2].value.yxlangnode), (yystack_[0].value.yxlangnode));
           }
         }
#line 974 "parser.cc"
    break;

  case 35: // start: stmtlist
#line 215 "parser.yy"
               { driver.calc.expressions.push_back((yystack_[0].value.yxlangnode)); }
#line 980 "parser.cc"
    break;


#line 984 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -58;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      29,    35,    -6,   -58,   -58,    -9,     4,    12,    35,   -58,
     -58,   -58,    90,   -58,   -58,   -58,    11,   -58,    20,    16,
      -2,    46,    35,    35,    35,    35,    63,    35,    35,    35,
      35,    35,    35,    29,    29,   -58,    29,    30,    90,    45,
      25,    72,    54,   -58,    99,    33,    33,   -58,   -58,   -58,
     -58,   -58,    52,     3,    31,    47,    35,   -58,   -58,    35,
      29,    29,   -58,    30,    71,   -58,    81,   -58,    89,   -58,
      29,   -58,   -58,   -58
  };

  const signed char
  Parser::yydefact_[] =
  {
      32,     0,     0,     2,     3,     4,     0,     0,     0,     5,
       6,    17,    26,    28,    27,    29,     0,    35,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    32,     1,    30,     0,    20,    18,
       0,     0,     0,     7,    13,     8,     9,    10,    11,    12,
      34,    33,     0,     0,    24,     0,     0,    16,    14,     0,
      30,    30,    21,     0,     0,    19,     0,    31,     0,    25,
      30,    15,    22,    23
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -58,   -58,   -58,   -58,    -1,    22,   -58,   -58,   -58,    24,
       1,   -57,    26,   -58
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     9,    10,    11,    12,    40,    13,    14,    15,    55,
      52,    53,    17,    18
  };

  const signed char
  Parser::yytable_[] =
  {
      20,    16,    36,    67,    68,    21,    22,    26,    61,    62,
      27,    33,    23,    73,    28,    29,    30,    31,    32,    34,
      35,    38,    39,    41,    42,    24,    44,    45,    46,    47,
      48,    49,     1,    25,    16,    16,     2,    23,     3,     4,
       5,    54,     6,     7,     3,     4,    19,    57,     6,     7,
       8,    30,    31,    32,    63,    39,     8,    27,    66,    50,
      51,    28,    29,    30,    31,    32,    27,    37,    56,    64,
      28,    29,    30,    31,    32,    27,    60,    59,    65,    28,
      29,    30,    31,    32,    27,    43,    70,    69,    28,    29,
      30,    31,    32,    27,    58,    72,     0,    28,    29,    30,
      31,    32,    27,    71,     0,     0,    28,    29,    30,    31,
      32,    -1,     0,     0,     0,    28,    29,    30,    31,    32
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,     0,     4,    60,    61,    11,    15,     8,     5,     6,
      12,     0,    21,    70,    16,    17,    18,    19,    20,     8,
       0,    22,    23,    24,    25,    21,    27,    28,    29,    30,
      31,    32,     3,    21,    33,    34,     7,    21,     9,    10,
      11,    11,    13,    14,     9,    10,    11,    22,    13,    14,
      21,    18,    19,    20,    23,    56,    21,    12,    59,    33,
      34,    16,    17,    18,    19,    20,    12,    21,    23,    22,
      16,    17,    18,    19,    20,    12,    24,    23,    56,    16,
      17,    18,    19,    20,    12,    22,    15,    63,    16,    17,
      18,    19,    20,    12,    22,     6,    -1,    16,    17,    18,
      19,    20,    12,    22,    -1,    -1,    16,    17,    18,    19,
      20,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     7,     9,    10,    11,    13,    14,    21,    26,
      27,    28,    29,    31,    32,    33,    35,    37,    38,    11,
      29,    11,    15,    21,    21,    21,    29,    12,    16,    17,
      18,    19,    20,     0,     8,     0,     4,    21,    29,    29,
      30,    29,    29,    22,    29,    29,    29,    29,    29,    29,
      37,    37,    35,    36,    11,    34,    23,    22,    22,    23,
      24,     5,     6,    23,    22,    30,    29,    36,    36,    34,
      15,    22,     6,    36
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    25,    26,    26,    27,    28,    28,    28,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    30,    30,
      31,    32,    32,    33,    34,    34,    35,    35,    35,    35,
      36,    36,    37,    37,    37,    38
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     4,     6,     4,     1,     1,     3,
       3,     5,     7,     7,     1,     3,     1,     1,     1,     1,
       0,     3,     0,     3,     3,     1
  };


#if YXLANGDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IF", "THEN", "ELSE",
  "FI", "LET", "\"end of line\"", "\"integer\"", "\"double\"",
  "\"string\"", "CMP", "UNARYFUNC", "BINARYFUNC", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'('", "')'", "','", "';'", "$accept", "constant",
  "variable", "atomexpr", "expr", "exprlist", "assignment", "ifstmt",
  "funcstmt", "paramlist", "stmt", "sentencelist", "stmtlist", "start", YY_NULLPTR
  };
#endif


#if YXLANGDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   105,   105,   108,   112,   116,   119,   122,   126,   129,
     132,   135,   138,   141,   144,   147,   150,   153,   155,   158,
     162,   166,   169,   173,   177,   180,   184,   185,   186,   187,
     189,   190,   198,   199,   206,   215
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YXLANGDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    20,     2,     2,
      21,    22,    18,    16,    23,    17,     2,    19,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    15,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
    };
    // Last valid token kind.
    const int code_max = 269;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yxlang
#line 1548 "parser.cc"

#line 219 "parser.yy"
 /*** Additional Code ***/

void yxlang::Parser::error(const Parser::location_type& l, const std::string& m) {
    driver.error(l, m);
}
