#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Tokens.hpp"
#include "Expression.hpp"
#include "Driver.hpp"
#include "Scanner.hpp"
#include "Constant.hpp"

class Parser {

    private:

        // Token
        int token;

        // Otras partes del compilador
        /*
        Generator generator;
        */
        Scanner *lexer;
        Driver driver;

    public:
        Parser();
        Parser(Scanner *lexer);
        ~Parser();

        // Producciones gramaticales
        void rule_program();
        void rule_declarations();
        void rule_declarations_();
        void rule_declaration();
        void rule_declaration_1();
        void rule_declaration_2();
        void rule_declaration_3();
        void rule_declaration_variable();
        void rule_declaration_function();
        void rule_declaration_function_();
        void rule_declaration_structure();
        void rule_list_variables();
        void rule_list_variables_();
        int rule_type();
        void rule_body_structure();
        std::vector<Expression> rule_list_arguments();
        std::vector<Expression> rule_list_arguments_();
        std::vector<Expression> rule_arguments();
        std::vector<Expression> rule_arguments_();
        Expression rule_argument();
        void rule_declarations_local();
        void rule_declarations_local_();
        void rule_declaration_local();
        void rule_block_or_statement();
        void rule_block_statements();
        void rule_statements();
        void rule_statements_();
        void rule_statement();
        void rule_statement_if();
        void rule_statement_if_();
        void rule_statement_while();
        void rule_statement_do_while();
        void rule_statement_print();
        void rule_statement_assign();
        Expression rule_statement_left_side();
        Expression rule_statement_left_side_();
        void rule_statement_puts();
        void rule_statement_putw();
        void rule_statement_break();
        void rule_statement_scan();
        void rule_statement_return();
        void rule_statement_return_();
        Expression rule_expression_a();
        Expression rule_expression_a_();
        Expression rule_expression_b();
        Expression rule_expression_b_();
        Expression rule_expression_c();
        Expression rule_expression_c_();
        Expression rule_expression_d();
        Expression rule_expression_d_();
        Expression rule_expression_e();
        Expression rule_expression_e_();
        Expression rule_expression_f();
        Expression rule_expression_f_();
        Expression rule_expression_g();
        Expression rule_expression_h();
        Expression rule_expression_h_();
        std::vector<Expression> rule_list_parameters();
        std::vector<Expression> rule_parameters();
        std::vector<Expression> rule_parameters_();
        Expression rule_parameter();

        // Operaciones de Parser
        void eat(int token);
        void error(std::string message);
        void tokens();
        void parse();

};

#endif