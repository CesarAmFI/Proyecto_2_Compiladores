// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 9 "../Parser.yy"


    #include <string>

    #include "Expression.hpp"

    class Scanner;
    class Driver;

    // The following definitions are missing when %locations isn't used
    # ifndef YY_NULLPTR
    #  if defined __cplusplus && 201103L <= __cplusplus
    #   define YY_NULLPTR nullptr
    #  else
    #   define YY_NULLPTR 0
    #  endif
    # endif


#line 69 "Parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 203 "Parser.tab.hh"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // argument
      // @21
      // @22
      // @23
      // @26
      // @27
      // @30
      // @31
      // @32
      // @35
      // @36
      // statement_left_side
      // statement_left_side_
      // expression_a
      // expression_a_
      // @41
      // @42
      // expression_b
      // expression_b_
      // @44
      // @45
      // expression_c
      // expression_c_
      // @47
      // @48
      // @49
      // @50
      // expression_d
      // expression_d_
      // @52
      // @53
      // @54
      // @55
      // @56
      // @57
      // @58
      // @59
      // expression_e
      // expression_e_
      // @61
      // @62
      // @63
      // @64
      // expression_f
      // expression_f_
      // @66
      // @67
      // @68
      // @69
      // expression_g
      // expression_h
      // expression_h_
      // parameter
      char dummy1[sizeof (Expression)];

      // type
      char dummy2[sizeof (int)];

      // ID
      // NUMBER_INTEGER
      // NUMBER_FLOAT
      // NUMBER_DOUBLE
      // STRING
      // @8
      // @12
      // @71
      // @73
      // @75
      char dummy3[sizeof (std::string)];

      // list_arguments
      // arguments
      // arguments_
      // list_parameters
      // parameters
      // parameters_
      char dummy4[sizeof (std::vector<Expression>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    SEMICOLON = 258,               // SEMICOLON
    CHAR = 259,                    // CHAR
    INT = 260,                     // INT
    FLOAT = 261,                   // FLOAT
    DOUBLE = 262,                  // DOUBLE
    STRUCT = 263,                  // STRUCT
    RIGHT_BRACKET = 264,           // RIGHT_BRACKET
    LEFT_BRACKET = 265,            // LEFT_BRACKET
    VOID = 266,                    // VOID
    COMMA = 267,                   // COMMA
    IF = 268,                      // IF
    ELSE = 269,                    // ELSE
    WHILE = 270,                   // WHILE
    DO = 271,                      // DO
    DOT = 272,                     // DOT
    PRINT = 273,                   // PRINT
    SCAN = 274,                    // SCAN
    BREAK = 275,                   // BREAK
    RETURN = 276,                  // RETURN
    ID = 277,                      // ID
    NUMBER_INTEGER = 278,          // NUMBER_INTEGER
    NUMBER_FLOAT = 279,            // NUMBER_FLOAT
    NUMBER_DOUBLE = 280,           // NUMBER_DOUBLE
    STRING = 281,                  // STRING
    ASSIGN = 282,                  // ASSIGN
    DISJOIN = 283,                 // DISJOIN
    CONJOIN = 284,                 // CONJOIN
    EQUAL = 285,                   // EQUAL
    DIFFERENT = 286,               // DIFFERENT
    LESS = 287,                    // LESS
    GREATER = 288,                 // GREATER
    LESS_EQUAL = 289,              // LESS_EQUAL
    GREATER_EQUAL = 290,           // GREATER_EQUAL
    ADD = 291,                     // ADD
    SUBSTRACT = 292,               // SUBSTRACT
    MULTIPLY = 293,                // MULTIPLY
    DIVIDE = 294,                  // DIVIDE
    NEGATE = 295,                  // NEGATE
    LEFT_PARENTHESIS = 296,        // LEFT_PARENTHESIS
    RIGHT_PARENTHESIS = 297        // RIGHT_PARENTHESIS
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 43, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_SEMICOLON = 3,                         // SEMICOLON
        S_CHAR = 4,                              // CHAR
        S_INT = 5,                               // INT
        S_FLOAT = 6,                             // FLOAT
        S_DOUBLE = 7,                            // DOUBLE
        S_STRUCT = 8,                            // STRUCT
        S_RIGHT_BRACKET = 9,                     // RIGHT_BRACKET
        S_LEFT_BRACKET = 10,                     // LEFT_BRACKET
        S_VOID = 11,                             // VOID
        S_COMMA = 12,                            // COMMA
        S_IF = 13,                               // IF
        S_ELSE = 14,                             // ELSE
        S_WHILE = 15,                            // WHILE
        S_DO = 16,                               // DO
        S_DOT = 17,                              // DOT
        S_PRINT = 18,                            // PRINT
        S_SCAN = 19,                             // SCAN
        S_BREAK = 20,                            // BREAK
        S_RETURN = 21,                           // RETURN
        S_ID = 22,                               // ID
        S_NUMBER_INTEGER = 23,                   // NUMBER_INTEGER
        S_NUMBER_FLOAT = 24,                     // NUMBER_FLOAT
        S_NUMBER_DOUBLE = 25,                    // NUMBER_DOUBLE
        S_STRING = 26,                           // STRING
        S_ASSIGN = 27,                           // ASSIGN
        S_DISJOIN = 28,                          // DISJOIN
        S_CONJOIN = 29,                          // CONJOIN
        S_EQUAL = 30,                            // EQUAL
        S_DIFFERENT = 31,                        // DIFFERENT
        S_LESS = 32,                             // LESS
        S_GREATER = 33,                          // GREATER
        S_LESS_EQUAL = 34,                       // LESS_EQUAL
        S_GREATER_EQUAL = 35,                    // GREATER_EQUAL
        S_ADD = 36,                              // ADD
        S_SUBSTRACT = 37,                        // SUBSTRACT
        S_MULTIPLY = 38,                         // MULTIPLY
        S_DIVIDE = 39,                           // DIVIDE
        S_NEGATE = 40,                           // NEGATE
        S_LEFT_PARENTHESIS = 41,                 // LEFT_PARENTHESIS
        S_RIGHT_PARENTHESIS = 42,                // RIGHT_PARENTHESIS
        S_YYACCEPT = 43,                         // $accept
        S_program = 44,                          // program
        S_45_1 = 45,                             // $@1
        S_declarations = 46,                     // declarations
        S_declarations_ = 47,                    // declarations_
        S_declaration = 48,                      // declaration
        S_49_2 = 49,                             // $@2
        S_50_3 = 50,                             // $@3
        S_declaration_1 = 51,                    // declaration_1
        S_declaration_2 = 52,                    // declaration_2
        S_53_4 = 53,                             // $@4
        S_54_5 = 54,                             // $@5
        S_declaration_3 = 55,                    // declaration_3
        S_declaration_variable = 56,             // declaration_variable
        S_57_6 = 57,                             // $@6
        S_list_variables = 58,                   // list_variables
        S_list_variables_ = 59,                  // list_variables_
        S_60_7 = 60,                             // $@7
        S_type = 61,                             // type
        S_declaration_structure = 62,            // declaration_structure
        S_63_8 = 63,                             // @8
        S_64_9 = 64,                             // $@9
        S_65_10 = 65,                            // $@10
        S_66_11 = 66,                            // $@11
        S_body_structure = 67,                   // body_structure
        S_declaration_function = 68,             // declaration_function
        S_69_12 = 69,                            // @12
        S_70_13 = 70,                            // $@13
        S_71_14 = 71,                            // $@14
        S_declaration_function_ = 72,            // declaration_function_
        S_73_15 = 73,                            // $@15
        S_74_16 = 74,                            // $@16
        S_list_arguments = 75,                   // list_arguments
        S_76_17 = 76,                            // $@17
        S_arguments = 77,                        // arguments
        S_78_18 = 78,                            // $@18
        S_arguments_ = 79,                       // arguments_
        S_80_19 = 80,                            // $@19
        S_argument = 81,                         // argument
        S_local_declarations = 82,               // local_declarations
        S_local_declarations_ = 83,              // local_declarations_
        S_local_declaration = 84,                // local_declaration
        S_85_20 = 85,                            // $@20
        S_block_or_statement = 86,               // block_or_statement
        S_block_statements = 87,                 // block_statements
        S_statements = 88,                       // statements
        S_statements_ = 89,                      // statements_
        S_statement = 90,                        // statement
        S_statement_1 = 91,                      // statement_1
        S_statement_if = 92,                     // statement_if
        S_93_21 = 93,                            // @21
        S_94_22 = 94,                            // @22
        S_95_23 = 95,                            // @23
        S_96_24 = 96,                            // $@24
        S_97_25 = 97,                            // $@25
        S_statement_if_ = 98,                    // statement_if_
        S_99_26 = 99,                            // @26
        S_100_27 = 100,                          // @27
        S_101_28 = 101,                          // $@28
        S_102_29 = 102,                          // $@29
        S_statement_while = 103,                 // statement_while
        S_104_30 = 104,                          // @30
        S_105_31 = 105,                          // @31
        S_106_32 = 106,                          // @32
        S_107_33 = 107,                          // $@33
        S_108_34 = 108,                          // $@34
        S_statement_do = 109,                    // statement_do
        S_110_35 = 110,                          // @35
        S_111_36 = 111,                          // @36
        S_112_37 = 112,                          // $@37
        S_113_38 = 113,                          // $@38
        S_statement_assign = 114,                // statement_assign
        S_statement_left_side = 115,             // statement_left_side
        S_116_39 = 116,                          // $@39
        S_statement_left_side_ = 117,            // statement_left_side_
        S_statement_putw = 118,                  // statement_putw
        S_statement_puts = 119,                  // statement_puts
        S_statement_scan = 120,                  // statement_scan
        S_statement_break = 121,                 // statement_break
        S_statement_return = 122,                // statement_return
        S_statement_return_ = 123,               // statement_return_
        S_expression_a = 124,                    // expression_a
        S_125_40 = 125,                          // $@40
        S_expression_a_ = 126,                   // expression_a_
        S_127_41 = 127,                          // @41
        S_128_42 = 128,                          // @42
        S_expression_b = 129,                    // expression_b
        S_130_43 = 130,                          // $@43
        S_expression_b_ = 131,                   // expression_b_
        S_132_44 = 132,                          // @44
        S_133_45 = 133,                          // @45
        S_expression_c = 134,                    // expression_c
        S_135_46 = 135,                          // $@46
        S_expression_c_ = 136,                   // expression_c_
        S_137_47 = 137,                          // @47
        S_138_48 = 138,                          // @48
        S_139_49 = 139,                          // @49
        S_140_50 = 140,                          // @50
        S_expression_d = 141,                    // expression_d
        S_142_51 = 142,                          // $@51
        S_expression_d_ = 143,                   // expression_d_
        S_144_52 = 144,                          // @52
        S_145_53 = 145,                          // @53
        S_146_54 = 146,                          // @54
        S_147_55 = 147,                          // @55
        S_148_56 = 148,                          // @56
        S_149_57 = 149,                          // @57
        S_150_58 = 150,                          // @58
        S_151_59 = 151,                          // @59
        S_expression_e = 152,                    // expression_e
        S_153_60 = 153,                          // $@60
        S_expression_e_ = 154,                   // expression_e_
        S_155_61 = 155,                          // @61
        S_156_62 = 156,                          // @62
        S_157_63 = 157,                          // @63
        S_158_64 = 158,                          // @64
        S_expression_f = 159,                    // expression_f
        S_160_65 = 160,                          // $@65
        S_expression_f_ = 161,                   // expression_f_
        S_162_66 = 162,                          // @66
        S_163_67 = 163,                          // @67
        S_164_68 = 164,                          // @68
        S_165_69 = 165,                          // @69
        S_expression_g = 166,                    // expression_g
        S_expression_h = 167,                    // expression_h
        S_168_70 = 168,                          // $@70
        S_expression_h_ = 169,                   // expression_h_
        S_170_71 = 170,                          // @71
        S_list_parameters = 171,                 // list_parameters
        S_172_72 = 172,                          // $@72
        S_parameters = 173,                      // parameters
        S_174_73 = 174,                          // @73
        S_175_74 = 175,                          // $@74
        S_parameters_ = 176,                     // parameters_
        S_177_75 = 177,                          // @75
        S_178_76 = 178,                          // $@76
        S_parameter = 179                        // parameter
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
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
      case symbol_kind::S_128_42: // @42
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_133_45: // @45
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_138_48: // @48
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_140_50: // @50
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_145_53: // @53
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_147_55: // @55
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_149_57: // @57
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_151_59: // @59
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_156_62: // @62
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_158_64: // @64
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_163_67: // @67
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_165_69: // @69
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.move< Expression > (std::move (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< int > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.move< std::vector<Expression> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
      case symbol_kind::S_128_42: // @42
      case symbol_kind::S_expression_b: // expression_b
      case symbol_kind::S_expression_b_: // expression_b_
      case symbol_kind::S_132_44: // @44
      case symbol_kind::S_133_45: // @45
      case symbol_kind::S_expression_c: // expression_c
      case symbol_kind::S_expression_c_: // expression_c_
      case symbol_kind::S_137_47: // @47
      case symbol_kind::S_138_48: // @48
      case symbol_kind::S_139_49: // @49
      case symbol_kind::S_140_50: // @50
      case symbol_kind::S_expression_d: // expression_d
      case symbol_kind::S_expression_d_: // expression_d_
      case symbol_kind::S_144_52: // @52
      case symbol_kind::S_145_53: // @53
      case symbol_kind::S_146_54: // @54
      case symbol_kind::S_147_55: // @55
      case symbol_kind::S_148_56: // @56
      case symbol_kind::S_149_57: // @57
      case symbol_kind::S_150_58: // @58
      case symbol_kind::S_151_59: // @59
      case symbol_kind::S_expression_e: // expression_e
      case symbol_kind::S_expression_e_: // expression_e_
      case symbol_kind::S_155_61: // @61
      case symbol_kind::S_156_62: // @62
      case symbol_kind::S_157_63: // @63
      case symbol_kind::S_158_64: // @64
      case symbol_kind::S_expression_f: // expression_f
      case symbol_kind::S_expression_f_: // expression_f_
      case symbol_kind::S_162_66: // @66
      case symbol_kind::S_163_67: // @67
      case symbol_kind::S_164_68: // @68
      case symbol_kind::S_165_69: // @69
      case symbol_kind::S_expression_g: // expression_g
      case symbol_kind::S_expression_h: // expression_h
      case symbol_kind::S_expression_h_: // expression_h_
      case symbol_kind::S_parameter: // parameter
        value.template destroy< Expression > ();
        break;

      case symbol_kind::S_type: // type
        value.template destroy< int > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_list_arguments: // list_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_arguments_: // arguments_
      case symbol_kind::S_list_parameters: // list_parameters
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_parameters_: // parameters_
        value.template destroy< std::vector<Expression> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::RETURN)
                   || (token::ASSIGN <= tok && tok <= token::RIGHT_PARENTHESIS));
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT ((token::ID <= tok && tok <= token::STRING));
      }
    };

    /// Build a parser object.
    Parser (Scanner &scanner_yyarg, Driver &driver_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (location_type l)
      {
        return symbol_type (token::CHAR, std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const location_type& l)
      {
        return symbol_type (token::CHAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (location_type l)
      {
        return symbol_type (token::INT, std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const location_type& l)
      {
        return symbol_type (token::INT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (location_type l)
      {
        return symbol_type (token::FLOAT, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const location_type& l)
      {
        return symbol_type (token::FLOAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (location_type l)
      {
        return symbol_type (token::DOUBLE, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const location_type& l)
      {
        return symbol_type (token::DOUBLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACKET (location_type l)
      {
        return symbol_type (token::RIGHT_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_BRACKET (const location_type& l)
      {
        return symbol_type (token::RIGHT_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACKET (location_type l)
      {
        return symbol_type (token::LEFT_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_BRACKET (const location_type& l)
      {
        return symbol_type (token::LEFT_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (location_type l)
      {
        return symbol_type (token::VOID, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const location_type& l)
      {
        return symbol_type (token::VOID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SCAN (location_type l)
      {
        return symbol_type (token::SCAN, std::move (l));
      }
#else
      static
      symbol_type
      make_SCAN (const location_type& l)
      {
        return symbol_type (token::SCAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::NUMBER_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMBER_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::NUMBER_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMBER_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::NUMBER_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMBER_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DISJOIN (location_type l)
      {
        return symbol_type (token::DISJOIN, std::move (l));
      }
#else
      static
      symbol_type
      make_DISJOIN (const location_type& l)
      {
        return symbol_type (token::DISJOIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONJOIN (location_type l)
      {
        return symbol_type (token::CONJOIN, std::move (l));
      }
#else
      static
      symbol_type
      make_CONJOIN (const location_type& l)
      {
        return symbol_type (token::CONJOIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIFFERENT (location_type l)
      {
        return symbol_type (token::DIFFERENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DIFFERENT (const location_type& l)
      {
        return symbol_type (token::DIFFERENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_EQUAL (location_type l)
      {
        return symbol_type (token::LESS_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_EQUAL (const location_type& l)
      {
        return symbol_type (token::LESS_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_EQUAL (location_type l)
      {
        return symbol_type (token::GREATER_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_EQUAL (const location_type& l)
      {
        return symbol_type (token::GREATER_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (location_type l)
      {
        return symbol_type (token::ADD, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const location_type& l)
      {
        return symbol_type (token::ADD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBSTRACT (location_type l)
      {
        return symbol_type (token::SUBSTRACT, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBSTRACT (const location_type& l)
      {
        return symbol_type (token::SUBSTRACT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTIPLY (location_type l)
      {
        return symbol_type (token::MULTIPLY, std::move (l));
      }
#else
      static
      symbol_type
      make_MULTIPLY (const location_type& l)
      {
        return symbol_type (token::MULTIPLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (location_type l)
      {
        return symbol_type (token::DIVIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const location_type& l)
      {
        return symbol_type (token::DIVIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEGATE (location_type l)
      {
        return symbol_type (token::NEGATE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEGATE (const location_type& l)
      {
        return symbol_type (token::NEGATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PARENTHESIS (location_type l)
      {
        return symbol_type (token::LEFT_PARENTHESIS, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_PARENTHESIS (const location_type& l)
      {
        return symbol_type (token::LEFT_PARENTHESIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PARENTHESIS (location_type l)
      {
        return symbol_type (token::RIGHT_PARENTHESIS, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_PARENTHESIS (const location_type& l)
      {
        return symbol_type (token::RIGHT_PARENTHESIS, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 232,     ///< Last index in yytable_.
      yynnts_ = 137,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;

  };


} // yy
#line 2209 "Parser.tab.hh"




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
