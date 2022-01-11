// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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





#include "Parser.tab.hh"


// Unqualified %code blocks.
#line 32 "../Parser.yy"


    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    #include "Scanner.hpp"
    #include "Driver.hpp"

    #undef yylex
    #define yylex scanner.yylex


#line 60 "Parser.tab.cc"


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
#if YYDEBUG

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

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 152 "Parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
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
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.copy< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.copy< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



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
    switch (this->kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.move< Expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type: // type
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.move< std::vector<Expression> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

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
  Parser::by_kind::clear ()
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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.YY_MOVE_OR_COPY< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.YY_MOVE_OR_COPY< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.move< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.move< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.copy< Expression > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.copy< std::vector<Expression> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.move< Expression > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.move< std::vector<Expression> > (that.value);
        break;

      default:
        break;
    }

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
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
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

#if YYDEBUG
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
#endif // YYDEBUG

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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_93_21: // @21
      case symbol_kind::S_94_22: // @22
      case symbol_kind::S_95_23: // @23
      case symbol_kind::S_99_26: // @26
      case symbol_kind::S_100_27: // @27
      case symbol_kind::S_104_30: // @30
      case symbol_kind::S_105_31: // @31
      case symbol_kind::S_106_32: // @32
      case symbol_kind::S_110_35: // @35
      case symbol_kind::S_111_36: // @36
      case symbol_kind::S_statement_left_side: // statement_left_side
      case symbol_kind::S_statement_left_side_: // statement_left_side_
      case symbol_kind::S_expression_a: // expression_a
      case symbol_kind::S_expression_a_: // expression_a_
      case symbol_kind::S_127_41: // @41
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        yylhs.value.emplace< Expression > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMBER_INTEGER: // NUMBER_INTEGER
      case symbol_kind::S_NUMBER_FLOAT: // NUMBER_FLOAT
      case symbol_kind::S_NUMBER_DOUBLE: // NUMBER_DOUBLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_63_8: // @8
      case symbol_kind::S_69_12: // @12
      case symbol_kind::S_170_71: // @71
      case symbol_kind::S_174_73: // @73
      case symbol_kind::S_177_75: // @75
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        yylhs.value.emplace< std::vector<Expression> > ();
        break;

      default:
        break;
    }


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
  case 2: // $@1: %empty
#line 133 "../Parser.yy"
    {
        driver.semantic_prepare_program();
    }
#line 1128 "Parser.tab.cc"
    break;

  case 3: // program: $@1 declarations
#line 137 "../Parser.yy"
    {
        driver.print();
        driver.translate_data();
        driver.translate_end();
    }
#line 1138 "Parser.tab.cc"
    break;

  case 7: // $@2: %empty
#line 153 "../Parser.yy"
    {
        driver.set_parser_type(yystack_[1].value.as < int > ());
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
    }
#line 1147 "Parser.tab.cc"
    break;

  case 9: // $@3: %empty
#line 160 "../Parser.yy"
    {
        driver.set_parser_type(driver.get_type_table().get_type_by_name("void").get_id());
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
    }
#line 1156 "Parser.tab.cc"
    break;

  case 14: // $@4: %empty
#line 174 "../Parser.yy"
    {
        driver.set_parser_id("");
    }
#line 1164 "Parser.tab.cc"
    break;

  case 16: // $@5: %empty
#line 180 "../Parser.yy"
    {
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
    }
#line 1172 "Parser.tab.cc"
    break;

  case 20: // $@6: %empty
#line 191 "../Parser.yy"
    {
        std::vector<Expression> list;
        list.push_back(Expression(driver.get_parser_type(), driver.get_parser_id(), driver.get_parser_id(), false));
        driver.set_parser_list(list);
    }
#line 1182 "Parser.tab.cc"
    break;

  case 23: // $@7: %empty
#line 203 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        list.push_back(Expression(driver.get_parser_type(), yystack_[0].value.as < std::string > (), yystack_[0].value.as < std::string > (), false));
        driver.set_parser_list(list);
    }
#line 1192 "Parser.tab.cc"
    break;

  case 25: // list_variables_: %empty
#line 211 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_variables(list);
    }
#line 1201 "Parser.tab.cc"
    break;

  case 26: // type: CHAR
#line 218 "../Parser.yy"
    {
        yylhs.value.as < int > () = driver.get_type_table().get_type_by_name("char").get_id();
    }
#line 1209 "Parser.tab.cc"
    break;

  case 27: // type: INT
#line 223 "../Parser.yy"
    {
        yylhs.value.as < int > () = driver.get_type_table().get_type_by_name("int").get_id();
    }
#line 1217 "Parser.tab.cc"
    break;

  case 28: // type: DOUBLE
#line 228 "../Parser.yy"
    {
        yylhs.value.as < int > () = driver.get_type_table().get_type_by_name("double").get_id();
    }
#line 1225 "Parser.tab.cc"
    break;

  case 29: // type: FLOAT
#line 233 "../Parser.yy"
    {
        yylhs.value.as < int > () = driver.get_type_table().get_type_by_name("float").get_id();
    }
#line 1233 "Parser.tab.cc"
    break;

  case 30: // @8: %empty
#line 238 "../Parser.yy"
                  {   
        std::string id = driver.get_parser_id();
        yylhs.value.as < std::string > () = id;
    }
#line 1242 "Parser.tab.cc"
    break;

  case 31: // $@9: %empty
#line 242 "../Parser.yy"
    {
        driver.semantic_prepare_structure(yystack_[0].value.as < std::string > ());
        driver.semantic_create_context();
    }
#line 1251 "Parser.tab.cc"
    break;

  case 32: // $@10: %empty
#line 247 "../Parser.yy"
    {
        driver.semantic_structure(yystack_[2].value.as < std::string > ());
        driver.semantic_destroy_context();
    }
#line 1260 "Parser.tab.cc"
    break;

  case 33: // $@11: %empty
#line 252 "../Parser.yy"
    {
        std::vector<Expression> list;
        int type = driver.get_type_table().get_size();
        list.push_back(Expression(type, yystack_[0].value.as < std::string > (), yystack_[0].value.as < std::string > (), false));
        driver.set_parser_list(list);
        driver.set_parser_type(type);
    }
#line 1272 "Parser.tab.cc"
    break;

  case 36: // @12: %empty
#line 265 "../Parser.yy"
                  {
        std::string id = driver.get_parser_id();
        yylhs.value.as < std::string > () = id;
    }
#line 1281 "Parser.tab.cc"
    break;

  case 37: // $@13: %empty
#line 269 "../Parser.yy"
    {
        int type = driver.get_parser_type();
        driver.semantic_prepare_function(yystack_[0].value.as < std::string > (), type);
        driver.semantic_create_context();
        driver.generate_label(driver.expression_from_label(yystack_[0].value.as < std::string > ()));
    }
#line 1292 "Parser.tab.cc"
    break;

  case 38: // $@14: %empty
#line 277 "../Parser.yy"
    {
        std::vector<Expression> list = yystack_[4].value.as < std::vector<Expression> > ();
        driver.complete_generate_return_void();
        driver.semantic_function(yystack_[7].value.as < std::string > (), list);
        driver.translate_text(yystack_[7].value.as < std::string > ());
        driver.semantic_destroy_context();
    }
#line 1304 "Parser.tab.cc"
    break;

  case 40: // $@15: %empty
#line 288 "../Parser.yy"
    {
        std::string struct_id = driver.get_parser_id();
        driver.semantic_prepare_structure_function(yystack_[0].value.as < std::string > (), struct_id);
        driver.semantic_create_context();
        driver.generate_label(driver.expression_from_label(yystack_[0].value.as < std::string > ()));
    }
#line 1315 "Parser.tab.cc"
    break;

  case 41: // $@16: %empty
#line 296 "../Parser.yy"
    {
        std::vector<Expression> list = yystack_[4].value.as < std::vector<Expression> > ();  
        driver.semantic_function(yystack_[7].value.as < std::string > (), list);
        driver.translate_text(yystack_[7].value.as < std::string > ());
        driver.semantic_destroy_context();
    }
#line 1326 "Parser.tab.cc"
    break;

  case 43: // $@17: %empty
#line 305 "../Parser.yy"
    {
        std::vector<Expression> list;
        driver.set_parser_list(list);
    }
#line 1335 "Parser.tab.cc"
    break;

  case 44: // list_arguments: $@17 arguments
#line 310 "../Parser.yy"
    {
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > ();
    }
#line 1343 "Parser.tab.cc"
    break;

  case 45: // list_arguments: %empty
#line 315 "../Parser.yy"
    {
        std::vector<Expression> list;
        yylhs.value.as < std::vector<Expression> > () = list;
    }
#line 1352 "Parser.tab.cc"
    break;

  case 46: // $@18: %empty
#line 322 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression argument = yystack_[0].value.as < Expression > ();
        list.push_back(argument);
        driver.set_parser_list(list);
    }
#line 1363 "Parser.tab.cc"
    break;

  case 47: // arguments: argument $@18 arguments_
#line 329 "../Parser.yy"
    { 
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > (); 
    }
#line 1371 "Parser.tab.cc"
    break;

  case 48: // $@19: %empty
#line 335 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression argument = yystack_[0].value.as < Expression > ();
        list.push_back(argument);
        driver.set_parser_list(list);
    }
#line 1382 "Parser.tab.cc"
    break;

  case 49: // arguments_: COMMA argument $@19 arguments_
#line 342 "../Parser.yy"
    {
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > ();
    }
#line 1390 "Parser.tab.cc"
    break;

  case 50: // arguments_: %empty
#line 347 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_arguments(list);
        yylhs.value.as < std::vector<Expression> > () = list;
    }
#line 1400 "Parser.tab.cc"
    break;

  case 51: // argument: type ID
#line 355 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = Expression(yystack_[1].value.as < int > (), yystack_[0].value.as < std::string > (), yystack_[0].value.as < std::string > (), false);
    }
#line 1408 "Parser.tab.cc"
    break;

  case 55: // $@20: %empty
#line 369 "../Parser.yy"
    {
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
        driver.set_parser_type(yystack_[1].value.as < int > ());
    }
#line 1417 "Parser.tab.cc"
    break;

  case 74: // @21: %empty
#line 417 "../Parser.yy"
                 {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        yylhs.value.as < Expression > () = true_label_expression;
    }
#line 1427 "Parser.tab.cc"
    break;

  case 75: // @22: %empty
#line 422 "../Parser.yy"
                 {
        int false_label = driver.create_label(); 
        Expression false_label_expression = driver.expression_from_label(false_label);
        yylhs.value.as < Expression > () = false_label_expression;
    }
#line 1437 "Parser.tab.cc"
    break;

  case 76: // @23: %empty
#line 427 "../Parser.yy"
                 {
        int next_label = driver.create_label();
        Expression next_label_expression = driver.expression_from_label(next_label);
        yylhs.value.as < Expression > () = next_label_expression;
    }
#line 1447 "Parser.tab.cc"
    break;

  case 77: // $@24: %empty
#line 432 "../Parser.yy"
    {
        driver.generate_if(yystack_[4].value.as < Expression > (), yystack_[2].value.as < Expression > ());
        driver.generate_goto(yystack_[1].value.as < Expression > ());
        driver.generate_label(yystack_[2].value.as < Expression > ());
    }
#line 1457 "Parser.tab.cc"
    break;

  case 78: // $@25: %empty
#line 438 "../Parser.yy"
    {
        driver.set_parser_false_label(yystack_[3].value.as < Expression > ());
        driver.set_parser_next_label(yystack_[2].value.as < Expression > ());
    }
#line 1466 "Parser.tab.cc"
    break;

  case 80: // @26: %empty
#line 445 "../Parser.yy"
                 {
        Expression next_label = driver.get_parser_next_label();
        yylhs.value.as < Expression > () = next_label;
    }
#line 1475 "Parser.tab.cc"
    break;

  case 81: // @27: %empty
#line 449 "../Parser.yy"
                 {
        Expression false_label = driver.get_parser_false_label();
        yylhs.value.as < Expression > () = false_label;
    }
#line 1484 "Parser.tab.cc"
    break;

  case 82: // $@28: %empty
#line 453 "../Parser.yy"
    {
        driver.generate_goto(yystack_[1].value.as < Expression > ());
    }
#line 1492 "Parser.tab.cc"
    break;

  case 83: // $@29: %empty
#line 457 "../Parser.yy"
    {
        driver.generate_label(yystack_[2].value.as < Expression > ());
    }
#line 1500 "Parser.tab.cc"
    break;

  case 84: // statement_if_: @26 @27 $@28 ELSE $@29 block_or_statement
#line 461 "../Parser.yy"
    {
        driver.generate_goto(yystack_[5].value.as < Expression > ());
        driver.generate_label(yystack_[5].value.as < Expression > ());
    }
#line 1509 "Parser.tab.cc"
    break;

  case 85: // statement_if_: %empty
#line 467 "../Parser.yy"
    {
        Expression false_label = driver.get_parser_false_label();
        driver.generate_goto(false_label);
        driver.generate_label(false_label);
    }
#line 1519 "Parser.tab.cc"
    break;

  case 86: // @30: %empty
#line 475 "../Parser.yy"
                 {
        int start_label = driver.create_label();
        Expression start_label_expression = driver.expression_from_label(start_label);
        yylhs.value.as < Expression > () = start_label_expression;
    }
#line 1529 "Parser.tab.cc"
    break;

  case 87: // @31: %empty
#line 480 "../Parser.yy"
                 {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        yylhs.value.as < Expression > () = true_label_expression;
    }
#line 1539 "Parser.tab.cc"
    break;

  case 88: // @32: %empty
#line 485 "../Parser.yy"
                 {
        int false_label = driver.create_label();
        Expression false_label_expression = driver.expression_from_label(false_label);
        driver.push_label(false_label);
        yylhs.value.as < Expression > () = false_label_expression;
    }
#line 1550 "Parser.tab.cc"
    break;

  case 89: // $@33: %empty
#line 491 "../Parser.yy"
    {
        driver.generate_label(yystack_[2].value.as < Expression > ());
    }
#line 1558 "Parser.tab.cc"
    break;

  case 90: // $@34: %empty
#line 495 "../Parser.yy"
    {
        driver.generate_if(yystack_[0].value.as < Expression > (), yystack_[3].value.as < Expression > ());
        driver.generate_goto(yystack_[2].value.as < Expression > ());
        driver.generate_label(yystack_[3].value.as < Expression > ());
    }
#line 1568 "Parser.tab.cc"
    break;

  case 91: // statement_while: WHILE LEFT_PARENTHESIS @30 @31 @32 $@33 expression_a $@34 RIGHT_PARENTHESIS block_or_statement
#line 501 "../Parser.yy"
    {
        driver.generate_goto(yystack_[7].value.as < Expression > ());
        driver.generate_label(yystack_[5].value.as < Expression > ());
        driver.pop_label();
    }
#line 1578 "Parser.tab.cc"
    break;

  case 92: // @35: %empty
#line 509 "../Parser.yy"
                 {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        yylhs.value.as < Expression > () = true_label_expression;
    }
#line 1588 "Parser.tab.cc"
    break;

  case 93: // @36: %empty
#line 514 "../Parser.yy"
                 {
        int false_label = driver.create_label();
        Expression false_label_expression = driver.expression_from_label(false_label);
        driver.push_label(false_label);
        yylhs.value.as < Expression > () = false_label_expression;
    }
#line 1599 "Parser.tab.cc"
    break;

  case 94: // $@37: %empty
#line 520 "../Parser.yy"
    {
        driver.generate_label(yystack_[1].value.as < Expression > ());
    }
#line 1607 "Parser.tab.cc"
    break;

  case 95: // $@38: %empty
#line 524 "../Parser.yy"
    {
        driver.generate_if(yystack_[1].value.as < Expression > (), yystack_[7].value.as < Expression > ());
        driver.generate_goto(yystack_[6].value.as < Expression > ());
        driver.generate_label(yystack_[6].value.as < Expression > ());
        driver.pop_label();
    }
#line 1618 "Parser.tab.cc"
    break;

  case 97: // statement_assign: statement_left_side ASSIGN expression_a SEMICOLON
#line 534 "../Parser.yy"
    {
        Expression assignable = yystack_[3].value.as < Expression > ();
        Expression expression = yystack_[1].value.as < Expression > ();
        driver.semantic_variables(driver.generate_assignment(assignable, expression));
    }
#line 1628 "Parser.tab.cc"
    break;

  case 98: // $@39: %empty
#line 542 "../Parser.yy"
    {
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
    }
#line 1636 "Parser.tab.cc"
    break;

  case 99: // statement_left_side: ID $@39 statement_left_side_
#line 546 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1644 "Parser.tab.cc"
    break;

  case 100: // statement_left_side_: DOT ID
#line 552 "../Parser.yy"
    {
        std::string id = driver.get_parser_id();
        std::string attribute = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Expression > () = driver.expression_from_structure_variable(id, attribute);
    }
#line 1654 "Parser.tab.cc"
    break;

  case 101: // statement_left_side_: %empty
#line 559 "../Parser.yy"
    {
        std::string id = driver.get_parser_id();
        yylhs.value.as < Expression > () = driver.expression_from_variable(id);
    }
#line 1663 "Parser.tab.cc"
    break;

  case 102: // statement_putw: expression_a RIGHT_PARENTHESIS SEMICOLON
#line 566 "../Parser.yy"
    {
        Expression expression = yystack_[2].value.as < Expression > ();
        driver.generate_print(expression);
    }
#line 1672 "Parser.tab.cc"
    break;

  case 103: // statement_puts: STRING RIGHT_PARENTHESIS SEMICOLON
#line 573 "../Parser.yy"
    {
        Constant string_constant = driver.semantic_constant_string(yystack_[2].value.as < std::string > ());
        Expression expression = driver.expression_from_constant(string_constant.get_id());
        driver.generate_print(expression);
    }
#line 1682 "Parser.tab.cc"
    break;

  case 104: // statement_scan: SCAN LEFT_PARENTHESIS ID RIGHT_PARENTHESIS SEMICOLON
#line 581 "../Parser.yy"
    {
        Expression expression = driver.expression_from_variable(yystack_[2].value.as < std::string > ());
        driver.generate_scan(expression);
    }
#line 1691 "Parser.tab.cc"
    break;

  case 105: // statement_break: BREAK SEMICOLON
#line 588 "../Parser.yy"
    {
        int jump_to_label = driver.top_label();
        Expression jump_to_label_expression = driver.expression_from_label(jump_to_label);
        driver.generate_goto(jump_to_label_expression);
    }
#line 1701 "Parser.tab.cc"
    break;

  case 107: // statement_return_: SEMICOLON
#line 599 "../Parser.yy"
    {
        driver.semantic_return_void();
        driver.generate_return();
    }
#line 1710 "Parser.tab.cc"
    break;

  case 108: // statement_return_: expression_a SEMICOLON
#line 605 "../Parser.yy"
    {
        Expression expression = yystack_[1].value.as < Expression > ();
        Expression expression_ = driver.semantic_temporary(driver.expression_from_return());
        driver.semantic_return_expression(expression);
        driver.semantic_returns(std::vector<Expression>{expression_});
        driver.semantic_variables(driver.generate_assignment(expression_, expression));
        driver.generate_return(expression_);
    }
#line 1723 "Parser.tab.cc"
    break;

  case 109: // $@40: %empty
#line 616 "../Parser.yy"
    {
        Expression expression_b = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_b);
    }
#line 1732 "Parser.tab.cc"
    break;

  case 110: // expression_a: expression_b $@40 expression_a_
#line 621 "../Parser.yy"
    {
        Expression expression_a = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_a;
    }
#line 1741 "Parser.tab.cc"
    break;

  case 111: // @41: %empty
#line 627 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1750 "Parser.tab.cc"
    break;

  case 112: // $@42: %empty
#line 632 "../Parser.yy"
    {
        Expression expression_b = yystack_[0].value.as < Expression > ();
        std::vector<Expression> temporals = driver.generate_disjunction(yystack_[2].value.as < Expression > (), expression_b);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1762 "Parser.tab.cc"
    break;

  case 113: // expression_a_: @41 DISJOIN expression_b $@42 expression_a_
#line 640 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1770 "Parser.tab.cc"
    break;

  case 114: // expression_a_: %empty
#line 645 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1779 "Parser.tab.cc"
    break;

  case 115: // $@43: %empty
#line 652 "../Parser.yy"
    {
        Expression expression_c = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_c);
    }
#line 1788 "Parser.tab.cc"
    break;

  case 116: // expression_b: expression_c $@43 expression_b_
#line 657 "../Parser.yy"
    {
        Expression expression_b_ = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_b_;
    }
#line 1797 "Parser.tab.cc"
    break;

  case 117: // @44: %empty
#line 663 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1806 "Parser.tab.cc"
    break;

  case 118: // $@45: %empty
#line 668 "../Parser.yy"
    {
        Expression expression_c = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_conjunction(yystack_[2].value.as < Expression > (), expression_c);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1818 "Parser.tab.cc"
    break;

  case 119: // expression_b_: @44 CONJOIN expression_c $@45 expression_b_
#line 676 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1826 "Parser.tab.cc"
    break;

  case 120: // expression_b_: %empty
#line 681 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1835 "Parser.tab.cc"
    break;

  case 121: // $@46: %empty
#line 688 "../Parser.yy"
    {
        Expression expression_d = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_d);
    }
#line 1844 "Parser.tab.cc"
    break;

  case 122: // expression_c: expression_d $@46 expression_c_
#line 693 "../Parser.yy"
    {
        Expression expression_c_ = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_c_;
    }
#line 1853 "Parser.tab.cc"
    break;

  case 123: // @47: %empty
#line 699 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1862 "Parser.tab.cc"
    break;

  case 124: // $@48: %empty
#line 704 "../Parser.yy"
    {
        Expression expression_d = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_equality(yystack_[2].value.as < Expression > (), expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1874 "Parser.tab.cc"
    break;

  case 125: // expression_c_: @47 EQUAL expression_d $@48 expression_c_
#line 712 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1882 "Parser.tab.cc"
    break;

  case 126: // @49: %empty
#line 716 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1891 "Parser.tab.cc"
    break;

  case 127: // $@50: %empty
#line 721 "../Parser.yy"
    {
        Expression expression_d = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_not_equality(yystack_[2].value.as < Expression > (), expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1903 "Parser.tab.cc"
    break;

  case 128: // expression_c_: @49 DIFFERENT expression_d $@50 expression_c_
#line 729 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1911 "Parser.tab.cc"
    break;

  case 129: // expression_c_: %empty
#line 734 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1920 "Parser.tab.cc"
    break;

  case 130: // $@51: %empty
#line 741 "../Parser.yy"
    {
        Expression expression_e = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_e);
    }
#line 1929 "Parser.tab.cc"
    break;

  case 131: // expression_d: expression_e $@51 expression_d_
#line 746 "../Parser.yy"
    {
        Expression expression_d_ = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_d_;
    }
#line 1938 "Parser.tab.cc"
    break;

  case 132: // @52: %empty
#line 752 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1947 "Parser.tab.cc"
    break;

  case 133: // $@53: %empty
#line 757 "../Parser.yy"
    {
        Expression expression_e = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_less_inequality(yystack_[2].value.as < Expression > (), expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1959 "Parser.tab.cc"
    break;

  case 134: // expression_d_: @52 LESS expression_e $@53 expression_d_
#line 765 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1967 "Parser.tab.cc"
    break;

  case 135: // @54: %empty
#line 769 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 1976 "Parser.tab.cc"
    break;

  case 136: // $@55: %empty
#line 774 "../Parser.yy"
    {
        Expression expression_e = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_greater_inequality(yystack_[2].value.as < Expression > (), expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 1988 "Parser.tab.cc"
    break;

  case 137: // expression_d_: @54 GREATER expression_e $@55 expression_d_
#line 782 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 1996 "Parser.tab.cc"
    break;

  case 138: // @56: %empty
#line 786 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2005 "Parser.tab.cc"
    break;

  case 139: // $@57: %empty
#line 791 "../Parser.yy"
    {
        Expression expression_e = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_less_equal_inequality(yystack_[2].value.as < Expression > (), expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2017 "Parser.tab.cc"
    break;

  case 140: // expression_d_: @56 LESS_EQUAL expression_e $@57 expression_d_
#line 799 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2025 "Parser.tab.cc"
    break;

  case 141: // @58: %empty
#line 803 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2034 "Parser.tab.cc"
    break;

  case 142: // $@59: %empty
#line 808 "../Parser.yy"
    {
        Expression expression_e = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_greater_equal_inequality(yystack_[2].value.as < Expression > (), expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2046 "Parser.tab.cc"
    break;

  case 143: // expression_d_: @58 GREATER_EQUAL expression_e $@59 expression_d_
#line 816 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2054 "Parser.tab.cc"
    break;

  case 144: // expression_d_: %empty
#line 821 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2063 "Parser.tab.cc"
    break;

  case 145: // $@60: %empty
#line 828 "../Parser.yy"
    {
        Expression expression_f = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_f);
    }
#line 2072 "Parser.tab.cc"
    break;

  case 146: // expression_e: expression_f $@60 expression_e_
#line 833 "../Parser.yy"
    {
        Expression expression_e_ = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_e_;
    }
#line 2081 "Parser.tab.cc"
    break;

  case 147: // @61: %empty
#line 839 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2090 "Parser.tab.cc"
    break;

  case 148: // $@62: %empty
#line 844 "../Parser.yy"
    {
        Expression expression_f = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_addition(yystack_[2].value.as < Expression > (), expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2102 "Parser.tab.cc"
    break;

  case 149: // expression_e_: @61 ADD expression_f $@62 expression_e_
#line 852 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2110 "Parser.tab.cc"
    break;

  case 150: // @63: %empty
#line 856 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2119 "Parser.tab.cc"
    break;

  case 151: // $@64: %empty
#line 861 "../Parser.yy"
    {
        Expression expression_f = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_substraction(yystack_[2].value.as < Expression > (), expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2131 "Parser.tab.cc"
    break;

  case 152: // expression_e_: @63 SUBSTRACT expression_f $@64 expression_e_
#line 869 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2139 "Parser.tab.cc"
    break;

  case 153: // expression_e_: %empty
#line 874 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2148 "Parser.tab.cc"
    break;

  case 154: // $@65: %empty
#line 881 "../Parser.yy"
    {
        Expression expression_g = yystack_[0].value.as < Expression > ();
        driver.set_parser_expression(expression_g);
    }
#line 2157 "Parser.tab.cc"
    break;

  case 155: // expression_f: expression_g $@65 expression_f_
#line 886 "../Parser.yy"
    {
        Expression expression_f_ = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_f_;
    }
#line 2166 "Parser.tab.cc"
    break;

  case 156: // @66: %empty
#line 892 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2175 "Parser.tab.cc"
    break;

  case 157: // $@67: %empty
#line 897 "../Parser.yy"
    {
        Expression expression_g = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_multiplication(yystack_[2].value.as < Expression > (), expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2187 "Parser.tab.cc"
    break;

  case 158: // expression_f_: @66 MULTIPLY expression_g $@67 expression_f_
#line 905 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2195 "Parser.tab.cc"
    break;

  case 159: // @68: %empty
#line 909 "../Parser.yy"
                 {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2204 "Parser.tab.cc"
    break;

  case 160: // $@69: %empty
#line 914 "../Parser.yy"
    {
        Expression expression_g = yystack_[0].value.as < Expression > (); 
        std::vector<Expression> temporals = driver.generate_division(yystack_[2].value.as < Expression > (), expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }
#line 2216 "Parser.tab.cc"
    break;

  case 161: // expression_f_: @68 DIVIDE expression_g $@69 expression_f_
#line 922 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2224 "Parser.tab.cc"
    break;

  case 162: // expression_f_: %empty
#line 927 "../Parser.yy"
    {
        Expression expression = driver.get_parser_expression();
        yylhs.value.as < Expression > () = expression;
    }
#line 2233 "Parser.tab.cc"
    break;

  case 163: // expression_g: NEGATE expression_h
#line 934 "../Parser.yy"
    {
        Expression expression_h = yystack_[0].value.as < Expression > ();
        std::vector<Expression> temporals = driver.generate_negation(expression_h);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0]; 
        yylhs.value.as < Expression > () = expression_;
    }
#line 2245 "Parser.tab.cc"
    break;

  case 164: // expression_g: expression_h
#line 943 "../Parser.yy"
    {
        Expression expression_h = yystack_[0].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression_h;
    }
#line 2254 "Parser.tab.cc"
    break;

  case 165: // expression_h: LEFT_PARENTHESIS expression_a RIGHT_PARENTHESIS
#line 950 "../Parser.yy"
    {
        Expression expression = yystack_[1].value.as < Expression > ();
        yylhs.value.as < Expression > () = expression;
    }
#line 2263 "Parser.tab.cc"
    break;

  case 166: // $@70: %empty
#line 956 "../Parser.yy"
    {
        driver.set_parser_id(yystack_[0].value.as < std::string > ());
    }
#line 2271 "Parser.tab.cc"
    break;

  case 167: // expression_h: ID $@70 expression_h_
#line 960 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2279 "Parser.tab.cc"
    break;

  case 168: // expression_h: NUMBER_DOUBLE
#line 965 "../Parser.yy"
    {
        double value = std::stod(yystack_[0].value.as < std::string > ());
        Constant constant = driver.semantic_constant_double(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        yylhs.value.as < Expression > () = expression;
    }
#line 2290 "Parser.tab.cc"
    break;

  case 169: // expression_h: NUMBER_INTEGER
#line 973 "../Parser.yy"
    {
        int value = std::stoi(yystack_[0].value.as < std::string > ());
        Expression expression = driver.expression_from_integer(value);
        yylhs.value.as < Expression > () = expression;
    }
#line 2300 "Parser.tab.cc"
    break;

  case 170: // expression_h: NUMBER_FLOAT
#line 980 "../Parser.yy"
    {
        float value = std::stof(yystack_[0].value.as < std::string > ());
        Constant constant = driver.semantic_constant_float(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        yylhs.value.as < Expression > () = expression;
    }
#line 2311 "Parser.tab.cc"
    break;

  case 171: // @71: %empty
#line 988 "../Parser.yy"
                  {
        std::string id = driver.get_parser_id();
        yylhs.value.as < std::string > () = id;
    }
#line 2320 "Parser.tab.cc"
    break;

  case 172: // expression_h_: @71 LEFT_PARENTHESIS list_parameters RIGHT_PARENTHESIS
#line 993 "../Parser.yy"
    {
        std::vector<Expression> list = yystack_[1].value.as < std::vector<Expression> > ();
        Expression expression_function = driver.expression_from_function(yystack_[3].value.as < std::string > ());
        Expression expression_number = driver.expression_from_integer(static_cast<int>(list.size()));
        Expression expression = driver.semantic_temporary(expression_function);
        driver.semantic_variables(std::vector<Expression>{expression});
        driver.generate_call(expression, expression_function, expression_number);
        yylhs.value.as < Expression > () = expression;
    }
#line 2334 "Parser.tab.cc"
    break;

  case 173: // expression_h_: DOT ID
#line 1004 "../Parser.yy"
    {
        std::string id = driver.get_parser_id();
        std::string attribute = yystack_[0].value.as < std::string > ();
        Expression expression = driver.expression_from_structure_variable(id, attribute);
        yylhs.value.as < Expression > () = expression;
    }
#line 2345 "Parser.tab.cc"
    break;

  case 174: // expression_h_: %empty
#line 1012 "../Parser.yy"
    {
        std::string id = driver.get_parser_id();
        Expression expression = driver.expression_from_variable(id);
        yylhs.value.as < Expression > () = expression;
    }
#line 2355 "Parser.tab.cc"
    break;

  case 175: // $@72: %empty
#line 1019 "../Parser.yy"
    {
        std::vector<Expression> list;
        driver.set_parser_list(list);
    }
#line 2364 "Parser.tab.cc"
    break;

  case 176: // list_parameters: $@72 parameters
#line 1024 "../Parser.yy"
    {
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > ();
    }
#line 2372 "Parser.tab.cc"
    break;

  case 177: // list_parameters: %empty
#line 1029 "../Parser.yy"
    {
        std::vector<Expression> list;
        yylhs.value.as < std::vector<Expression> > () = list;
    }
#line 2381 "Parser.tab.cc"
    break;

  case 178: // @73: %empty
#line 1035 "../Parser.yy"
                  {
        std::string id = driver.get_parser_id();
        yylhs.value.as < std::string > () = id;
    }
#line 2390 "Parser.tab.cc"
    break;

  case 179: // $@74: %empty
#line 1040 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression parameter = yystack_[0].value.as < Expression > ();
        driver.set_parser_id(yystack_[1].value.as < std::string > ());
        list.push_back(parameter);
        driver.set_parser_list(list);
    }
#line 2402 "Parser.tab.cc"
    break;

  case 180: // parameters: @73 parameter $@74 parameters_
#line 1048 "../Parser.yy"
    {
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > ();
    }
#line 2410 "Parser.tab.cc"
    break;

  case 181: // @75: %empty
#line 1053 "../Parser.yy"
                  {
        std::string id = driver.get_parser_id();
        yylhs.value.as < std::string > () = id;
    }
#line 2419 "Parser.tab.cc"
    break;

  case 182: // $@76: %empty
#line 1058 "../Parser.yy"
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression parameter = yystack_[0].value.as < Expression > ();
        driver.set_parser_id(yystack_[2].value.as < std::string > ());
        list.push_back(parameter);
        driver.set_parser_list(list);
    }
#line 2431 "Parser.tab.cc"
    break;

  case 183: // parameters_: @75 COMMA parameter $@76 parameters_
#line 1066 "../Parser.yy"
    {
        yylhs.value.as < std::vector<Expression> > () = yystack_[0].value.as < std::vector<Expression> > ();
    }
#line 2439 "Parser.tab.cc"
    break;

  case 184: // parameters_: %empty
#line 1071 "../Parser.yy"
    {
        std::string id = driver.get_parser_id();
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_parameters(id, list);
        for (int i = 0; i < list.size(); i++) {
            Expression expression_ = driver.semantic_temporary(driver.expression_from_argument(id, i));
            driver.semantic_variables(std::vector<Expression>{expression_});
            driver.semantic_variables(driver.generate_assignment(expression_, list[i]));
            driver.generate_parameter(expression_);
        }
        yylhs.value.as < std::vector<Expression> > () = list;
    }
#line 2456 "Parser.tab.cc"
    break;

  case 185: // parameter: expression_a
#line 1086 "../Parser.yy"
    {
        yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
    }
#line 2464 "Parser.tab.cc"
    break;


#line 2468 "Parser.tab.cc"

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
        std::string msg = YY_("syntax error");
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

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const short Parser::yypact_ninf_ = -242;

  const short Parser::yytable_ninf_ = -185;

  const short
  Parser::yypact_[] =
  {
    -242,     7,    29,  -242,  -242,  -242,  -242,  -242,   -18,   -12,
    -242,  -242,    29,    16,  -242,  -242,  -242,  -242,  -242,  -242,
      37,  -242,  -242,  -242,   -28,  -242,  -242,  -242,  -242,    56,
    -242,  -242,  -242,  -242,    66,  -242,    53,    58,  -242,    67,
      75,   110,  -242,    73,    94,   108,  -242,    58,    96,    73,
    -242,  -242,    77,    58,  -242,  -242,  -242,  -242,    78,    66,
     111,   100,  -242,  -242,  -242,    66,   114,  -242,    58,  -242,
     113,  -242,   123,    58,    61,    58,  -242,  -242,    61,    86,
      87,  -242,    88,    89,   128,     6,  -242,  -242,  -242,    61,
    -242,  -242,  -242,  -242,   105,  -242,  -242,  -242,  -242,  -242,
      20,  -242,  -242,    32,   112,  -242,  -242,  -242,  -242,  -242,
    -242,    26,    20,  -242,   130,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,   118,   127,  -242,    61,    20,   113,   129,    95,
    -242,  -242,    97,  -242,  -242,  -242,    98,    99,    -9,  -242,
     102,  -242,   117,   119,    62,    36,    59,    60,   120,  -242,
    -242,  -242,   143,  -242,  -242,  -242,  -242,     4,   144,   146,
     147,   131,  -242,   115,  -242,  -242,   124,  -242,   122,  -242,
     125,   126,  -242,   132,   121,   133,   134,  -242,   135,   136,
    -242,   137,   138,  -242,  -242,  -242,  -242,    61,   145,  -242,
    -242,  -242,  -242,  -242,   116,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,  -242,    20,   150,
     139,   140,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,    20,  -242,
    -242,    20,   117,   119,    62,    62,    36,    36,    36,    36,
      59,    59,    60,    60,     4,   141,   142,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,     4,  -242,   148,   149,  -242,   158,  -242,   153,
    -242,  -242,  -242,    20,  -242,  -242,   152,   148,  -242,  -242,
       4,  -242
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       2,     0,     6,     1,    26,    27,    29,    28,    14,     0,
       3,     4,     6,     0,    16,    11,    30,     9,     5,     7,
      30,    15,    31,    36,    20,    40,    17,    18,    19,     0,
      10,    37,     8,    12,    25,    13,     0,    54,    32,     0,
       0,     0,    22,    43,     0,     0,    52,    54,     0,    43,
      23,    21,     0,     0,    55,    35,    53,    33,     0,    25,
       0,     0,    44,    46,    20,    25,     0,    24,    54,    51,
      50,    56,     0,    54,    60,     0,    47,    34,    60,     0,
       0,    92,     0,     0,     0,     0,    98,    41,    59,    63,
      64,    65,    69,    67,     0,    71,    68,    70,    48,    38,
       0,    86,    93,     0,     0,   105,   107,   166,   169,   170,
     168,     0,     0,   106,     0,   109,   115,   121,   130,   145,
     154,   164,   101,     0,    61,    63,     0,    50,     0,     0,
      87,    94,     0,    66,    73,    72,     0,     0,   174,   163,
       0,   108,   114,   120,   129,   144,   153,   162,     0,    99,
      42,    62,     0,    49,    39,    74,    88,     0,     0,     0,
       0,     0,   167,     0,   165,   110,     0,   116,     0,   122,
       0,     0,   131,     0,     0,     0,     0,   146,     0,     0,
     155,     0,     0,   100,    97,    75,    89,     0,     0,    58,
     103,   102,   104,   173,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,   178,   112,   118,   124,   127,   133,   136,   139,
     142,   148,   151,   157,   160,    77,    90,    57,     0,   172,
     176,     0,   114,   120,   129,   129,   144,   144,   144,   144,
     153,   153,   162,   162,     0,     0,     0,   185,   179,   113,
     119,   125,   128,   134,   137,   140,   143,   149,   152,   158,
     161,    78,     0,    95,   181,    85,    91,     0,   180,     0,
      79,    81,    96,     0,    82,   182,     0,   181,    83,   183,
       0,    84
  };

  const short
  Parser::yypgoto_[] =
  {
    -242,  -242,  -242,  -242,   156,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,   106,  -242,   107,   103,  -242,     0,   154,
    -242,  -242,  -242,  -242,  -242,   155,  -242,  -242,  -242,  -242,
    -242,  -242,   151,  -242,  -242,  -242,    49,  -242,   157,   -62,
     159,  -242,  -242,  -241,   109,    -6,    63,   -73,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,   -85,  -242,   -54,  -242,  -242,   -10,  -242,   -47,  -242,
    -242,    -7,  -242,  -134,  -242,  -242,  -242,  -242,   -95,  -242,
    -152,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -111,
    -242,  -136,  -242,  -242,  -242,  -242,   -97,  -242,  -133,  -242,
    -242,  -242,  -242,   -94,    80,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,   -84,  -242,  -242,   -81
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,    10,    11,    12,    24,    23,    32,    15,
      16,    20,    26,    33,    34,    41,    42,    59,    44,    21,
      22,    29,    48,    65,    38,    30,    31,    39,   128,    28,
      36,   123,    52,    53,    62,    70,    76,   127,    63,    45,
      46,    47,    64,   188,    87,    88,   124,   189,   133,    90,
     185,   207,   225,   244,   265,   270,   271,   274,   276,   280,
      91,   130,   156,   186,   208,   245,    92,   102,   131,   157,
     267,    93,    94,   122,   149,   134,   135,    95,    96,    97,
     113,   247,   142,   165,   166,   232,   115,   143,   167,   168,
     233,   116,   144,   169,   170,   234,   171,   235,   117,   145,
     172,   173,   236,   174,   237,   175,   238,   176,   239,   118,
     146,   177,   178,   240,   179,   241,   119,   147,   180,   181,
     242,   182,   243,   120,   121,   138,   162,   163,   211,   212,
     230,   231,   264,   268,   269,   277,   248
  };

  const short
  Parser::yytable_[] =
  {
     114,    89,    13,   261,    14,    89,    74,     3,   161,   106,
      17,    78,    13,   -36,   187,   129,   125,    79,   136,    80,
      81,   266,    82,    83,    84,    85,    86,   140,   107,   108,
     109,   110,  -171,     4,     5,     6,     7,     8,    19,   281,
       9,   152,   107,   108,   109,   110,   111,   112,   107,   108,
     109,   110,   125,    61,   107,   108,   109,   110,   132,    25,
     111,   112,     4,     5,     6,     7,    37,   112,  -132,  -135,
    -138,  -141,   111,   112,    79,    61,    80,    81,    40,    82,
      83,    84,    85,    86,   253,   254,   255,   256,   217,   218,
     219,   220,  -123,  -126,    43,  -147,  -150,    50,  -156,  -159,
     251,   252,   215,   216,   257,   258,   221,   222,    49,   259,
     260,   223,   224,    51,    89,   -45,    54,    55,    57,    60,
      66,    68,    69,   226,    73,    75,    77,   100,   101,   103,
     104,   105,   126,   141,   137,   148,   150,   155,   154,   158,
     159,   160,   183,   246,   164,  -111,   184,   190,  -117,   191,
     192,   196,   195,   193,   200,   197,   194,   198,  -177,   227,
     210,   272,    67,   -80,   199,   273,   278,   201,    18,   202,
      71,   203,    72,   204,    27,   205,   153,   206,   249,    35,
     228,   209,   229,   262,   263,   213,   250,    99,   151,   214,
    -184,   139,   275,   279,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98
  };

  const short
  Parser::yycheck_[] =
  {
      85,    74,     2,   244,    22,    78,    68,     0,    17,     3,
      22,    73,    12,    41,    10,   100,    89,    13,   103,    15,
      16,   262,    18,    19,    20,    21,    22,   112,    22,    23,
      24,    25,    41,     4,     5,     6,     7,     8,    22,   280,
      11,   126,    22,    23,    24,    25,    40,    41,    22,    23,
      24,    25,   125,    53,    22,    23,    24,    25,    26,    22,
      40,    41,     4,     5,     6,     7,    10,    41,    32,    33,
      34,    35,    40,    41,    13,    75,    15,    16,    12,    18,
      19,    20,    21,    22,   236,   237,   238,   239,   199,   200,
     201,   202,    30,    31,    41,    36,    37,    22,    38,    39,
     234,   235,   197,   198,   240,   241,   203,   204,    41,   242,
     243,   205,   206,     3,   187,    42,    22,     9,    22,    42,
      42,    10,    22,   208,    10,    12,     3,    41,    41,    41,
      41,     3,    27,     3,    22,    17,     9,    42,     9,    42,
      42,    42,    22,   228,    42,    28,     3,     3,    29,     3,
       3,    29,    28,    22,    33,    30,    41,    31,    42,     9,
      15,     3,    59,    14,    32,    12,    14,    34,    12,    35,
      64,    36,    65,    37,    20,    38,   127,    39,   232,    24,
      41,   187,    42,    42,    42,   195,   233,    78,   125,   196,
      42,   111,   273,   277,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    44,    45,     0,     4,     5,     6,     7,     8,    11,
      46,    47,    48,    61,    22,    52,    53,    22,    47,    22,
      54,    62,    63,    50,    49,    22,    55,    62,    72,    64,
      68,    69,    51,    56,    57,    68,    73,    10,    67,    70,
      12,    58,    59,    41,    61,    82,    83,    84,    65,    41,
      22,     3,    75,    76,    22,     9,    83,    22,    75,    60,
      42,    61,    77,    81,    85,    66,    42,    59,    10,    22,
      78,    56,    58,    10,    82,    12,    79,     3,    82,    13,
      15,    16,    18,    19,    20,    21,    22,    87,    88,    90,
      92,   103,   109,   114,   115,   120,   121,   122,    81,    87,
      41,    41,   110,    41,    41,     3,     3,    22,    23,    24,
      25,    40,    41,   123,   124,   129,   134,   141,   152,   159,
     166,   167,   116,    74,    89,    90,    27,    80,    71,   124,
     104,   111,    26,    91,   118,   119,   124,    22,   168,   167,
     124,     3,   125,   130,   135,   142,   153,   160,    17,   117,
       9,    89,   124,    79,     9,    42,   105,   112,    42,    42,
      42,    17,   169,   170,    42,   126,   127,   131,   132,   136,
     137,   139,   143,   144,   146,   148,   150,   154,   155,   157,
     161,   162,   164,    22,     3,    93,   106,    10,    86,    90,
       3,     3,     3,    22,    41,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    94,   107,    88,
      15,   171,   172,   129,   134,   141,   141,   152,   152,   152,
     152,   159,   159,   166,   166,    95,   124,     9,    41,    42,
     173,   174,   128,   133,   138,   140,   145,   147,   149,   151,
     156,   158,   163,   165,    96,   108,   124,   124,   179,   126,
     131,   136,   136,   143,   143,   143,   143,   154,   154,   161,
     161,    86,    42,    42,   175,    97,    86,   113,   176,   177,
      98,    99,     3,    12,   100,   179,   101,   178,    14,   176,
     102,    86
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    43,    45,    44,    46,    47,    47,    49,    48,    50,
      48,    48,    51,    51,    53,    52,    54,    52,    55,    55,
      57,    56,    58,    60,    59,    59,    61,    61,    61,    61,
      63,    64,    65,    66,    62,    67,    69,    70,    71,    68,
      73,    74,    72,    76,    75,    75,    78,    77,    80,    79,
      79,    81,    82,    83,    83,    85,    84,    86,    86,    87,
      87,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    93,    94,    95,    96,    97,    92,
      99,   100,   101,   102,    98,    98,   104,   105,   106,   107,
     108,   103,   110,   111,   112,   113,   109,   114,   116,   115,
     117,   117,   118,   119,   120,   121,   122,   123,   123,   125,
     124,   127,   128,   126,   126,   130,   129,   132,   133,   131,
     131,   135,   134,   137,   138,   136,   139,   140,   136,   136,
     142,   141,   144,   145,   143,   146,   147,   143,   148,   149,
     143,   150,   151,   143,   143,   153,   152,   155,   156,   154,
     157,   158,   154,   154,   160,   159,   162,   163,   161,   164,
     165,   161,   161,   166,   166,   167,   168,   167,   167,   167,
     167,   170,   169,   169,   169,   172,   171,   171,   174,   175,
     173,   177,   178,   176,   176,   179
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     0,     0,     4,     0,
       4,     2,     1,     1,     0,     2,     0,     3,     1,     1,
       0,     3,     1,     0,     4,     0,     1,     1,     1,     1,
       0,     0,     0,     0,     8,     3,     0,     0,     0,    10,
       0,     0,    10,     0,     2,     0,     0,     3,     0,     4,
       0,     2,     1,     2,     0,     0,     4,     3,     1,     1,
       0,     2,     2,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    11,     4,     0,     3,
       2,     0,     3,     3,     5,     2,     2,     1,     2,     0,
       3,     0,     0,     5,     0,     0,     3,     0,     0,     5,
       0,     0,     3,     0,     0,     5,     0,     0,     5,     0,
       0,     3,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     3,     0,     0,     5,
       0,     0,     5,     0,     0,     3,     0,     0,     5,     0,
       0,     5,     0,     2,     1,     3,     0,     3,     1,     1,
       1,     0,     4,     2,     0,     0,     2,     0,     0,     0,
       4,     0,     0,     5,     0,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CHAR",
  "INT", "FLOAT", "DOUBLE", "STRUCT", "RIGHT_BRACKET", "LEFT_BRACKET",
  "VOID", "COMMA", "IF", "ELSE", "WHILE", "DO", "DOT", "PRINT", "SCAN",
  "BREAK", "RETURN", "ID", "NUMBER_INTEGER", "NUMBER_FLOAT",
  "NUMBER_DOUBLE", "STRING", "ASSIGN", "DISJOIN", "CONJOIN", "EQUAL",
  "DIFFERENT", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "ADD",
  "SUBSTRACT", "MULTIPLY", "DIVIDE", "NEGATE", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "$accept", "program", "$@1", "declarations",
  "declarations_", "declaration", "$@2", "$@3", "declaration_1",
  "declaration_2", "$@4", "$@5", "declaration_3", "declaration_variable",
  "$@6", "list_variables", "list_variables_", "$@7", "type",
  "declaration_structure", "@8", "$@9", "$@10", "$@11", "body_structure",
  "declaration_function", "@12", "$@13", "$@14", "declaration_function_",
  "$@15", "$@16", "list_arguments", "$@17", "arguments", "$@18",
  "arguments_", "$@19", "argument", "local_declarations",
  "local_declarations_", "local_declaration", "$@20", "block_or_statement",
  "block_statements", "statements", "statements_", "statement",
  "statement_1", "statement_if", "@21", "@22", "@23", "$@24", "$@25",
  "statement_if_", "@26", "@27", "$@28", "$@29", "statement_while", "@30",
  "@31", "@32", "$@33", "$@34", "statement_do", "@35", "@36", "$@37",
  "$@38", "statement_assign", "statement_left_side", "$@39",
  "statement_left_side_", "statement_putw", "statement_puts",
  "statement_scan", "statement_break", "statement_return",
  "statement_return_", "expression_a", "$@40", "expression_a_", "@41",
  "$@42", "expression_b", "$@43", "expression_b_", "@44", "$@45",
  "expression_c", "$@46", "expression_c_", "@47", "$@48", "@49", "$@50",
  "expression_d", "$@51", "expression_d_", "@52", "$@53", "@54", "$@55",
  "@56", "$@57", "@58", "$@59", "expression_e", "$@60", "expression_e_",
  "@61", "$@62", "@63", "$@64", "expression_f", "$@65", "expression_f_",
  "@66", "$@67", "@68", "$@69", "expression_g", "expression_h", "$@70",
  "expression_h_", "@71", "list_parameters", "$@72", "parameters", "@73",
  "$@74", "parameters_", "@75", "$@76", "parameter", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   133,   133,   133,   144,   147,   149,   153,   152,   160,
     159,   166,   169,   171,   174,   174,   180,   179,   186,   188,
     191,   191,   199,   203,   202,   210,   217,   222,   227,   232,
     238,   242,   247,   252,   238,   262,   265,   269,   277,   265,
     288,   296,   287,   305,   305,   314,   322,   321,   335,   334,
     346,   354,   360,   363,   365,   369,   368,   376,   378,   381,
     383,   386,   389,   391,   394,   396,   398,   400,   402,   404,
     406,   408,   411,   413,   417,   422,   427,   432,   438,   416,
     445,   449,   453,   457,   445,   466,   475,   480,   485,   491,
     495,   474,   509,   514,   520,   524,   508,   533,   542,   541,
     551,   558,   565,   572,   580,   587,   595,   598,   604,   616,
     615,   627,   632,   627,   644,   652,   651,   663,   668,   663,
     680,   688,   687,   699,   704,   699,   716,   721,   716,   733,
     741,   740,   752,   757,   752,   769,   774,   769,   786,   791,
     786,   803,   808,   803,   820,   828,   827,   839,   844,   839,
     856,   861,   856,   873,   881,   880,   892,   897,   892,   909,
     914,   909,   926,   933,   942,   949,   956,   955,   964,   972,
     979,   988,   988,  1003,  1011,  1019,  1019,  1028,  1035,  1040,
    1035,  1053,  1058,  1053,  1070,  1085
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
#endif // YYDEBUG

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
    };
    // Last valid token kind.
    const int code_max = 297;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 3054 "Parser.tab.cc"

#line 1090 "../Parser.yy"


void yy::Parser::error( const location_type &l, const std::string &err_message ) {
    cerr << "Error: " << err_message << " at " << l << endl;
}
