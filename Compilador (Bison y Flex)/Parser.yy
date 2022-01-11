
%skeleton "lalr1.cc"
%language "c++"
%require "3.7.4"
%defines 
%define api.parser.class {Parser}
%define parse.trace

%code requires {

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

}

%parse-param {Scanner &scanner}
%parse-param {Driver &driver}

%code {

    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    #include "Scanner.hpp"
    #include "Driver.hpp"

    #undef yylex
    #define yylex scanner.yylex

}

%define api.value.type variant
%define parse.assert

/* Se especifican los terminales juntos con sus tipos */
%token SEMICOLON
%token CHAR
%token INT
%token FLOAT
%token DOUBLE
%token STRUCT
%token RIGHT_BRACKET
%token LEFT_BRACKET
%token VOID
%token COMMA
%token IF
%token ELSE
%token WHILE
%token DO
%token DOT
%token PRINT
%token SCAN
%token BREAK
%token RETURN
%token <std::string> ID
%token <std::string> NUMBER_INTEGER
%token <std::string> NUMBER_FLOAT
%token <std::string> NUMBER_DOUBLE
%token <std::string> STRING

%left ASSIGN
%left DISJOIN
%left CONJOIN
%left EQUAL DIFFERENT
%left LESS GREATER LESS_EQUAL GREATER_EQUAL
%left ADD SUBSTRACT
%left MULTIPLY DIVIDE
%left NEGATE

%nonassoc LEFT_PARENTHESIS RIGHT_PARENTHESIS

%type <int> type

%type <std::vector<Expression>> list_arguments
%type <std::vector<Expression>> arguments
%type <std::vector<Expression>> arguments_

%type <Expression> argument

%type <Expression> statement_left_side
%type <Expression> statement_left_side_

%type <Expression> expression_a
%type <Expression> expression_a_
%type <Expression> expression_b
%type <Expression> expression_b_
%type <Expression> expression_c
%type <Expression> expression_c_
%type <Expression> expression_d
%type <Expression> expression_d_
%type <Expression> expression_e
%type <Expression> expression_e_
%type <Expression> expression_f
%type <Expression> expression_f_
%type <Expression> expression_g
%type <Expression> expression_h
%type <Expression> expression_h_

%type <std::vector<Expression>> list_parameters
%type <std::vector<Expression>> parameters
%type <std::vector<Expression>> parameters_

%type <Expression> parameter

/* Se declaran los no terminales junto con sus tipos */

/*
*
* Declaracion de no terminales
*
*/

%locations

%start program
%%

program: 
    {
        driver.semantic_prepare_program();
    } 
    declarations 
    {
        driver.print();
        driver.translate_data();
        driver.translate_end();
    };

declarations: 
    declarations_;

declarations_: 
    declaration declarations_ 
    | 
    %empty;

declaration: 
    type ID 
    {
        driver.set_parser_type($1);
        driver.set_parser_id($2);
    } 
    declaration_1
    | 
    VOID ID 
    {
        driver.set_parser_type(driver.get_type_table().get_type_by_name("void").get_id());
        driver.set_parser_id($2);
    } 
    declaration_function
    | 
    STRUCT declaration_2;

declaration_1: 
    declaration_variable 
    | 
    declaration_function;

declaration_2: 
    {
        driver.set_parser_id("");
    } 
    declaration_structure
    | 
    ID 
    {
        driver.set_parser_id($1);
    } 
    declaration_3;

declaration_3: 
    declaration_structure
    | 
    declaration_function_;

declaration_variable: 
    {
        std::vector<Expression> list;
        list.push_back(Expression(driver.get_parser_type(), driver.get_parser_id(), driver.get_parser_id(), false));
        driver.set_parser_list(list);
    } 
    list_variables SEMICOLON;

list_variables: 
    list_variables_;

list_variables_: 
    COMMA ID 
    {
        std::vector<Expression> list = driver.get_parser_list();
        list.push_back(Expression(driver.get_parser_type(), $2, $2, false));
        driver.set_parser_list(list);
    } 
    list_variables_
    | 
    %empty 
    {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_variables(list);
    }

type: 
    CHAR 
    {
        $$ = driver.get_type_table().get_type_by_name("char").get_id();
    }
    | 
    INT 
    {
        $$ = driver.get_type_table().get_type_by_name("int").get_id();
    }
    | 
    DOUBLE 
    {
        $$ = driver.get_type_table().get_type_by_name("double").get_id();
    }
    | 
    FLOAT 
    {
        $$ = driver.get_type_table().get_type_by_name("float").get_id();
    };

declaration_structure: 
    <std::string> {   
        std::string id = driver.get_parser_id();
        $$ = id;
    } 
    {
        driver.semantic_prepare_structure($1);
        driver.semantic_create_context();
    }
    body_structure 
    {
        driver.semantic_structure($1);
        driver.semantic_destroy_context();
    } 
    ID 
    {
        std::vector<Expression> list;
        int type = driver.get_type_table().get_size();
        list.push_back(Expression(type, $5, $5, false));
        driver.set_parser_list(list);
        driver.set_parser_type(type);
    } 
    list_variables SEMICOLON;

body_structure: 
    LEFT_BRACKET local_declarations RIGHT_BRACKET;

declaration_function: 
    <std::string> {
        std::string id = driver.get_parser_id();
        $$ = id;
    }
    {
        int type = driver.get_parser_type();
        driver.semantic_prepare_function($1, type);
        driver.semantic_create_context();
        driver.generate_label(driver.expression_from_label($1));
    } 
    LEFT_PARENTHESIS list_arguments 
    RIGHT_PARENTHESIS LEFT_BRACKET local_declarations block_statements 
    {
        std::vector<Expression> list = $4;
        driver.complete_generate_return_void();
        driver.semantic_function($1, list);
        driver.translate_text($1);
        driver.semantic_destroy_context();
    } 
    RIGHT_BRACKET;

declaration_function_: 
    ID 
    {
        std::string struct_id = driver.get_parser_id();
        driver.semantic_prepare_structure_function($1, struct_id);
        driver.semantic_create_context();
        driver.generate_label(driver.expression_from_label($1));
    } 
    LEFT_PARENTHESIS list_arguments 
    RIGHT_PARENTHESIS LEFT_BRACKET local_declarations block_statements 
    {
        std::vector<Expression> list = $4;  
        driver.semantic_function($1, list);
        driver.translate_text($1);
        driver.semantic_destroy_context();
    } 
    RIGHT_BRACKET;

list_arguments: 
    {
        std::vector<Expression> list;
        driver.set_parser_list(list);
    } 
    arguments
    {
        $$ = $2;
    }
    |
    %empty 
    {
        std::vector<Expression> list;
        $$ = list;
    };

arguments: 
    argument 
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression argument = $1;
        list.push_back(argument);
        driver.set_parser_list(list);
    } 
    arguments_ 
    { 
        $$ = $3; 
    };

arguments_: 
    COMMA argument 
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression argument = $2;
        list.push_back(argument);
        driver.set_parser_list(list);
    } 
    arguments_ 
    {
        $$ = $4;
    }
    | 
    %empty 
    {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_arguments(list);
        $$ = list;
    };

argument: 
    type ID 
    {
        $$ = Expression($1, $2, $2, false);
    };

local_declarations: 
    local_declarations_;

local_declarations_: 
    local_declaration local_declarations_
    | 
    %empty;

local_declaration: 
    type ID 
    {
        driver.set_parser_id($2);
        driver.set_parser_type($1);
    } 
    declaration_variable;

block_or_statement: 
    LEFT_BRACKET statements RIGHT_BRACKET
    | 
    statement;

block_statements: 
    statements
    | 
    %empty;

statements: 
    statement statements_;

statements_: 
    statement statements_
    | 
    %empty;

statement: 
    statement_if
    | 
    statement_while
    | 
    PRINT LEFT_PARENTHESIS statement_1
    | 
    statement_assign
    | 
    statement_break
    | 
    statement_do
    | 
    statement_return
    | 
    statement_scan;

statement_1: 
    statement_puts
    | 
    statement_putw;

statement_if: 
    IF LEFT_PARENTHESIS expression_a RIGHT_PARENTHESIS 
    <Expression> {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        $$ = true_label_expression;
    } 
    <Expression> {
        int false_label = driver.create_label(); 
        Expression false_label_expression = driver.expression_from_label(false_label);
        $$ = false_label_expression;
    } 
    <Expression> {
        int next_label = driver.create_label();
        Expression next_label_expression = driver.expression_from_label(next_label);
        $$ = next_label_expression;
    } 
    {
        driver.generate_if($3, $5);
        driver.generate_goto($6);
        driver.generate_label($5);
    }
    block_or_statement 
    {
        driver.set_parser_false_label($6);
        driver.set_parser_next_label($7);
    } 
    statement_if_;

statement_if_: 
    <Expression> {
        Expression next_label = driver.get_parser_next_label();
        $$ = next_label;
    }
    <Expression> {
        Expression false_label = driver.get_parser_false_label();
        $$ = false_label;
    }
    {
        driver.generate_goto($1);
    } 
    ELSE 
    {
        driver.generate_label($2);
    } 
    block_or_statement 
    {
        driver.generate_goto($1);
        driver.generate_label($1);
    }
    | 
    %empty 
    {
        Expression false_label = driver.get_parser_false_label();
        driver.generate_goto(false_label);
        driver.generate_label(false_label);
    };

statement_while: 
    WHILE LEFT_PARENTHESIS 
    <Expression> {
        int start_label = driver.create_label();
        Expression start_label_expression = driver.expression_from_label(start_label);
        $$ = start_label_expression;
    }
    <Expression> {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        $$ = true_label_expression;
    }
    <Expression> {
        int false_label = driver.create_label();
        Expression false_label_expression = driver.expression_from_label(false_label);
        driver.push_label(false_label);
        $$ = false_label_expression;
    }
    {
        driver.generate_label($3);
    } 
    expression_a
    {
        driver.generate_if($7, $4);
        driver.generate_goto($5);
        driver.generate_label($4);
    } 
    RIGHT_PARENTHESIS block_or_statement 
    {
        driver.generate_goto($3);
        driver.generate_label($5);
        driver.pop_label();
    };

statement_do: 
    DO 
    <Expression> {
        int true_label = driver.create_label();
        Expression true_label_expression = driver.expression_from_label(true_label);
        $$ = true_label_expression;
    } 
    <Expression> {
        int false_label = driver.create_label();
        Expression false_label_expression = driver.expression_from_label(false_label);
        driver.push_label(false_label);
        $$ = false_label_expression;
    } 
    {
        driver.generate_label($2);
    } 
    block_or_statement WHILE LEFT_PARENTHESIS expression_a RIGHT_PARENTHESIS 
    {
        driver.generate_if($8, $2);
        driver.generate_goto($3);
        driver.generate_label($3);
        driver.pop_label();
    } 
    SEMICOLON;

statement_assign: 
    statement_left_side ASSIGN expression_a SEMICOLON 
    {
        Expression assignable = $1;
        Expression expression = $3;
        driver.semantic_variables(driver.generate_assignment(assignable, expression));
    };

statement_left_side: 
    ID 
    {
        driver.set_parser_id($1);
    } 
    statement_left_side_ 
    {
        $$ = $3;
    };

statement_left_side_: 
    DOT ID 
    {
        std::string id = driver.get_parser_id();
        std::string attribute = $2;
        $$ = driver.expression_from_structure_variable(id, attribute);
    }
    | 
    %empty 
    {
        std::string id = driver.get_parser_id();
        $$ = driver.expression_from_variable(id);
    };

statement_putw: 
    expression_a RIGHT_PARENTHESIS SEMICOLON 
    {
        Expression expression = $1;
        driver.generate_print(expression);
    };

statement_puts: 
    STRING RIGHT_PARENTHESIS SEMICOLON 
    {
        Constant string_constant = driver.semantic_constant_string($1);
        Expression expression = driver.expression_from_constant(string_constant.get_id());
        driver.generate_print(expression);
    };

statement_scan: 
    SCAN LEFT_PARENTHESIS ID RIGHT_PARENTHESIS SEMICOLON 
    {
        Expression expression = driver.expression_from_variable($3);
        driver.generate_scan(expression);
    };

statement_break: 
    BREAK SEMICOLON
    {
        int jump_to_label = driver.top_label();
        Expression jump_to_label_expression = driver.expression_from_label(jump_to_label);
        driver.generate_goto(jump_to_label_expression);
    };

statement_return: 
    RETURN statement_return_;

statement_return_: 
    SEMICOLON 
    {
        driver.semantic_return_void();
        driver.generate_return();
    }
    | 
    expression_a SEMICOLON
    {
        Expression expression = $1;
        Expression expression_ = driver.semantic_temporary(driver.expression_from_return());
        driver.semantic_return_expression(expression);
        driver.semantic_returns(std::vector<Expression>{expression_});
        driver.semantic_variables(driver.generate_assignment(expression_, expression));
        driver.generate_return(expression_);
    };

expression_a: 
    expression_b 
    {
        Expression expression_b = $1;
        driver.set_parser_expression(expression_b);
    } 
    expression_a_
    {
        Expression expression_a = $3;
        $$ = expression_a;
    };

expression_a_: 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    DISJOIN expression_b 
    {
        Expression expression_b = $3;
        std::vector<Expression> temporals = driver.generate_disjunction($1, expression_b);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_a_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_b: 
    expression_c 
    {
        Expression expression_c = $1;
        driver.set_parser_expression(expression_c);
    } 
    expression_b_
    {
        Expression expression_b_ = $3;
        $$ = expression_b_;
    };

expression_b_: 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    CONJOIN expression_c 
    {
        Expression expression_c = $3; 
        std::vector<Expression> temporals = driver.generate_conjunction($1, expression_c);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_b_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_c: 
    expression_d 
    {
        Expression expression_d = $1;
        driver.set_parser_expression(expression_d);
    } 
    expression_c_
    {
        Expression expression_c_ = $3;
        $$ = expression_c_;
    };

expression_c_: 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    EQUAL expression_d
    {
        Expression expression_d = $3; 
        std::vector<Expression> temporals = driver.generate_equality($1, expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_c_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    DIFFERENT expression_d 
    {
        Expression expression_d = $3; 
        std::vector<Expression> temporals = driver.generate_not_equality($1, expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_c_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_d: 
    expression_e 
    {
        Expression expression_e = $1;
        driver.set_parser_expression(expression_e);
    } 
    expression_d_
    {
        Expression expression_d_ = $3;
        $$ = expression_d_;
    };

expression_d_:
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    LESS expression_e
    {
        Expression expression_e = $3; 
        std::vector<Expression> temporals = driver.generate_less_inequality($1, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }  
    expression_d_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    }  
    GREATER expression_e
    {
        Expression expression_e = $3; 
        std::vector<Expression> temporals = driver.generate_greater_inequality($1, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_d_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    }  
    LESS_EQUAL expression_e
    {
        Expression expression_e = $3; 
        std::vector<Expression> temporals = driver.generate_less_equal_inequality($1, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    }  
    expression_d_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    GREATER_EQUAL expression_e
    {
        Expression expression_e = $3; 
        std::vector<Expression> temporals = driver.generate_greater_equal_inequality($1, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_d_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_e: 
    expression_f 
    {
        Expression expression_f = $1;
        driver.set_parser_expression(expression_f);
    }
    expression_e_
    {
        Expression expression_e_ = $3;
        $$ = expression_e_;
    };

expression_e_:  
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    ADD expression_f
    {
        Expression expression_f = $3; 
        std::vector<Expression> temporals = driver.generate_addition($1, expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_e_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    }  
    SUBSTRACT expression_f
    {
        Expression expression_f = $3; 
        std::vector<Expression> temporals = driver.generate_substraction($1, expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_e_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_f: 
    expression_g
    {
        Expression expression_g = $1;
        driver.set_parser_expression(expression_g);
    }
    expression_f_
    {
        Expression expression_f_ = $3;
        $$ = expression_f_;
    };

expression_f_: 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    MULTIPLY expression_g
    {
        Expression expression_g = $3; 
        std::vector<Expression> temporals = driver.generate_multiplication($1, expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_f_
    {
        $$ = $5;
    }
    | 
    <Expression> {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    } 
    DIVIDE expression_g
    {
        Expression expression_g = $3; 
        std::vector<Expression> temporals = driver.generate_division($1, expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
    } 
    expression_f_
    {
        $$ = $5;
    }
    | 
    %empty
    {
        Expression expression = driver.get_parser_expression();
        $$ = expression;
    };

expression_g: 
    NEGATE expression_h
    {
        Expression expression_h = $2;
        std::vector<Expression> temporals = driver.generate_negation(expression_h);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0]; 
        $$ = expression_;
    }
    | 
    expression_h
    {
        Expression expression_h = $1;
        $$ = expression_h;
    };

expression_h: 
    LEFT_PARENTHESIS expression_a RIGHT_PARENTHESIS
    {
        Expression expression = $2;
        $$ = expression;
    }
    | 
    ID 
    {
        driver.set_parser_id($1);
    } 
    expression_h_
    {
        $$ = $3;
    }
    | 
    NUMBER_DOUBLE
    {
        double value = std::stod($1);
        Constant constant = driver.semantic_constant_double(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        $$ = expression;
    }
    |  
    NUMBER_INTEGER
    {
        int value = std::stoi($1);
        Expression expression = driver.expression_from_integer(value);
        $$ = expression;
    }
    | 
    NUMBER_FLOAT
    {
        float value = std::stof($1);
        Constant constant = driver.semantic_constant_float(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        $$ = expression;
    };

expression_h_: 
    <std::string> {
        std::string id = driver.get_parser_id();
        $$ = id;
    } 
    LEFT_PARENTHESIS list_parameters RIGHT_PARENTHESIS 
    {
        std::vector<Expression> list = $3;
        Expression expression_function = driver.expression_from_function($1);
        Expression expression_number = driver.expression_from_integer(static_cast<int>(list.size()));
        Expression expression = driver.semantic_temporary(expression_function);
        driver.semantic_variables(std::vector<Expression>{expression});
        driver.generate_call(expression, expression_function, expression_number);
        $$ = expression;
    }
    | 
    DOT ID
    {
        std::string id = driver.get_parser_id();
        std::string attribute = $2;
        Expression expression = driver.expression_from_structure_variable(id, attribute);
        $$ = expression;
    }
    | 
    %empty
    {
        std::string id = driver.get_parser_id();
        Expression expression = driver.expression_from_variable(id);
        $$ = expression;
    };

list_parameters: 
    {
        std::vector<Expression> list;
        driver.set_parser_list(list);
    } 
    parameters
    {
        $$ = $2;
    }
    | 
    %empty
    {
        std::vector<Expression> list;
        $$ = list;
    };

parameters: 
    <std::string> {
        std::string id = driver.get_parser_id();
        $$ = id;
    } 
    parameter 
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression parameter = $2;
        driver.set_parser_id($1);
        list.push_back(parameter);
        driver.set_parser_list(list);
    } 
    parameters_
    {
        $$ = $4;
    };

parameters_: 
    <std::string> {
        std::string id = driver.get_parser_id();
        $$ = id;
    } 
    COMMA parameter 
    {
        std::vector<Expression> list = driver.get_parser_list();
        Expression parameter = $3;
        driver.set_parser_id($1);
        list.push_back(parameter);
        driver.set_parser_list(list);
    } 
    parameters_
    {
        $$ = $5;
    }
    | 
    %empty
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
        $$ = list;
    };

parameter: 
    expression_a
    {
        $$ = $1;
    };

%%

void yy::Parser::error( const location_type &l, const std::string &err_message ) {
    cerr << "Error: " << err_message << " at " << l << endl;
}