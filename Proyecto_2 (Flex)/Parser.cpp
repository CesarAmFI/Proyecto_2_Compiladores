#include "Parser.hpp"

Parser::Parser(Scanner *lexer) {
    this->lexer = lexer;
}

Parser::~Parser() {
    
}

void Parser::rule_program() {
    driver.semantic_prepare_program();
    rule_declarations();
}

void Parser::rule_declarations() {
    rule_declarations_();
}

void Parser::rule_declarations_() {
    if (token == CHAR || token == INT || token == FLOAT || token == DOUBLE || token == VOID || token == STRUCT) {
        rule_declaration();
        rule_declarations_();
    }
}

void Parser::rule_declaration() {
    if (token == CHAR || token == INT || token == FLOAT || token == DOUBLE) {
        int type = rule_type();
        std::string id = lexer->YYText(); 
        eat(ID);
        driver.set_parser_type(type);
        driver.set_parser_id(id);
        rule_declaration_1();
    }
    else if (token == VOID) {
        eat(VOID);
        int type = driver.get_type_table().get_type_by_name("void").get_id();
        std::string id = lexer->YYText();
        eat(ID);
        driver.set_parser_type(type);
        driver.set_parser_id(id);
        rule_declaration_function();
    }
    else if (token == STRUCT) {
        eat(STRUCT);
        rule_declaration_2();
    }
}

void Parser::rule_declaration_1() {
    if (token == LEFT_PARENTHESIS) {
        rule_declaration_function();
    }
    else if (token == COMMA || token == SEMICOLON) {
        rule_declaration_variable();
    }
}

void Parser::rule_declaration_2() {
    if (token == LEFT_BRACKET) {
        driver.set_parser_id("");
        rule_declaration_structure();
    }
    else if (token == ID) {
        std::string id = lexer->YYText();
        eat(ID);
        driver.set_parser_id(id);
        rule_declaration_3();
    }
}

void Parser::rule_declaration_3() {
    if (token == LEFT_BRACKET) {
        rule_declaration_structure();
    }
    else if (token == ID) {
        rule_declaration_function_();
    }
}

void Parser::rule_declaration_variable() {
    int type = driver.get_parser_type();
    std::string id = driver.get_parser_id();
    std::vector<Expression> list;
    list.push_back(Expression(type, id, id, false));
    driver.set_parser_list(list);
    rule_list_variables();
    eat(SEMICOLON);
}

void Parser::rule_list_variables() {
    rule_list_variables_();
}

void Parser::rule_list_variables_() {
    if (token == COMMA) {
        std::vector<Expression> list = driver.get_parser_list();
        int type = driver.get_parser_type();
        eat(COMMA);
        std::string id = lexer->YYText();
        eat(ID);
        list.push_back(Expression(type, id, id, false));
        driver.set_parser_list(list);
        rule_list_variables_();
    }
    else {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_variables(list);
    }
}

int Parser::rule_type() {
    if (token == CHAR) {
        eat(CHAR);
        return driver.get_type_table().get_type_by_name("char").get_id(); 
    }
    else if (token == INT) {
        eat(INT);
        return driver.get_type_table().get_type_by_name("int").get_id();
    }
    else if (token == DOUBLE) {
        eat(DOUBLE);
        return driver.get_type_table().get_type_by_name("double").get_id();;
    }
    else if (token == FLOAT) {
        eat(FLOAT);
        return driver.get_type_table().get_type_by_name("float").get_id();; 
    }
    else {
        error("El token debe ser int, float, double, char");
        return -1;
    }
}

void Parser::rule_declaration_structure() {
    std::string id = driver.get_parser_id();
    driver.semantic_prepare_structure(id);
    driver.semantic_create_context();
    rule_body_structure();
    driver.semantic_structure(id);
    driver.semantic_destroy_context();
    int type = driver.get_type_table().get_size();
    std::string list_id = lexer->YYText();
    eat(ID);
    std::vector<Expression> list;
    list.push_back(Expression(type, list_id, list_id, false));
    driver.set_parser_list(list);
    driver.set_parser_type(type);
    rule_list_variables();
    eat(SEMICOLON);
}

void Parser::rule_body_structure() {
    eat(LEFT_BRACKET);
    rule_declarations_local();
    eat(RIGHT_BRACKET);
}

void Parser::rule_declaration_function() {
    std::string id = driver.get_parser_id();
    int type = driver.get_parser_type();
    driver.semantic_prepare_function(id, type);
    driver.semantic_create_context();
    Expression expression = driver.expression_from_label(id);
    driver.generate_label(expression);
    eat(LEFT_PARENTHESIS);
    std::vector<Expression> list = rule_list_arguments();
    eat(RIGHT_PARENTHESIS);
    eat(LEFT_BRACKET);
    rule_declarations_local();
    rule_block_statements();
    driver.complete_generate_return_void();
    driver.semantic_function(id, list);
    driver.translate_text(id);
    driver.semantic_destroy_context();
    eat(RIGHT_BRACKET);
}

void Parser::rule_declaration_function_() {
    std::string id = lexer->YYText();
    std::string struct_id = driver.get_parser_id();
    eat(ID);
    driver.semantic_prepare_structure_function(id, struct_id);
    driver.semantic_create_context();
    Expression expression = driver.expression_from_label(id);
    driver.generate_label(expression);
    eat(LEFT_PARENTHESIS);
    std::vector<Expression> list = rule_list_arguments();
    eat(RIGHT_PARENTHESIS);
    eat(LEFT_BRACKET);
    rule_declarations_local();
    rule_block_statements();
    driver.semantic_function(id, list);
    driver.translate_text(id);
    driver.semantic_destroy_context();
    eat(RIGHT_BRACKET);
}

std::vector<Expression> Parser::rule_list_arguments() {
    if (token == CHAR || token == INT || token == FLOAT || token == DOUBLE) {
        std::vector<Expression> list;
        driver.set_parser_list(list);
        return rule_arguments();
    }
    std::vector<Expression> list;
    return list;
}

std::vector<Expression> Parser::rule_arguments() {
    std::vector<Expression> list = driver.get_parser_list();
    Expression argument = rule_argument();
    list.push_back(argument);
    driver.set_parser_list(list);
    return rule_arguments_();
}

std::vector<Expression> Parser::rule_arguments_() {
    if (token == COMMA) {
        std::vector<Expression> list = driver.get_parser_list();
        eat(COMMA);
        Expression argument = rule_argument();
        list.push_back(argument);
        driver.set_parser_list(list);
        return rule_arguments_();
    }
    else {
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_arguments(list);
        return list;
    }
}

Expression Parser::rule_argument() {
    int type = rule_type();
    std::string id = lexer->YYText();
    eat(ID);
    return Expression(type, id, id, false);
}

void Parser::rule_declarations_local() {
    rule_declarations_local_();
}

void Parser::rule_declarations_local_() {
    if (token == CHAR || token == INT || token == FLOAT || token == DOUBLE) {
        rule_declaration_local();
        rule_declarations_local_();
    }
}

void Parser::rule_declaration_local() {
    int type = rule_type();
    std::string id = lexer->YYText();
    eat(ID);
    driver.set_parser_id(id);
    driver.set_parser_type(type);
    rule_declaration_variable();
}

void Parser::rule_block_or_statement() {
    if (token == LEFT_BRACKET) {
        eat(LEFT_BRACKET);
        rule_statements();
        eat(RIGHT_BRACKET);
    }
    else if (token == ID || token == IF || token == WHILE || token == DO || token == PRINT || token == BREAK || token == SCAN || token == RETURN) {
        rule_statement();
    }
}

void Parser::rule_block_statements() {
    if (token == ID || token == IF || token == WHILE || token == DO || token == PRINT || token == BREAK || token == SCAN || token == RETURN) {
        rule_statements();
    }
}

void Parser::rule_statements() {
    rule_statement();
    rule_statements_();
}

void Parser::rule_statements_() {
    if (token == ID || token == IF || token == WHILE || token == DO || token == PRINT || token == BREAK || token == SCAN || token == RETURN) {
        rule_statement();
        rule_statements_();
    }
}

void Parser::rule_statement() {
    if (token == ID) {
        rule_statement_assign();
    }
    else if (token == IF) {
        rule_statement_if();
    }
    else if (token == WHILE) {
        rule_statement_while();
    }
    else if (token == DO) {
        rule_statement_do_while();
    }
    else if (token == PRINT) {
        eat(PRINT);
        eat(LEFT_PARENTHESIS);
        rule_statement_print();
    }
    else if (token == BREAK) {
        rule_statement_break();
    }
    else if (token == SCAN) {
        rule_statement_scan();
    }
    else if (token == RETURN) {
        rule_statement_return();
    }
    else {
        error("El token debe ser if, do, while, print, id, break, scan, return");
    }
}

void Parser::rule_statement_print() {
    if (token == STRING) {
        rule_statement_puts();
    }
    else if (token == NEGATE || token == ID || token == LEFT_PARENTHESIS || token == NUMBER_INTEGER || token == NUMBER_FLOAT || token == NUMBER_DOUBLE) {
        rule_statement_putw();
    }
}

void Parser::rule_statement_if() {
    eat(IF);
    eat(LEFT_PARENTHESIS);
    int true_label = driver.create_label();
    int false_label = driver.create_label(); 
    int next_label = driver.create_label();
    Expression true_label_expression = driver.expression_from_label(true_label);
    Expression false_label_expression = driver.expression_from_label(false_label);
    Expression next_label_expression = driver.expression_from_label(next_label);
    Expression expression = rule_expression_a();
    eat(RIGHT_PARENTHESIS);
    driver.generate_if(expression, true_label_expression);
    driver.generate_goto(false_label_expression);
    driver.generate_label(true_label_expression);
    rule_block_or_statement();
    driver.set_parser_false_label(false_label_expression);
    driver.set_parser_next_label(next_label_expression);
    rule_statement_if_();
}

void Parser::rule_statement_if_() {
    if (token == ELSE) {
        Expression next_label = driver.get_parser_next_label();
        Expression false_label = driver.get_parser_false_label();
        driver.generate_goto(next_label);
        eat(ELSE);
        driver.generate_label(false_label);
        rule_block_or_statement();
        driver.generate_goto(next_label);
        driver.generate_label(next_label);
    }
    else {
        Expression false_label = driver.get_parser_false_label();
        driver.generate_goto(false_label);
        driver.generate_label(false_label);
    }
}

void Parser::rule_statement_while() {
    eat(WHILE);
    eat(LEFT_PARENTHESIS);
    int start_label = driver.create_label();
    int true_label = driver.create_label();
    int false_label = driver.create_label();
    driver.push_label(false_label);
    Expression start_label_expression = driver.expression_from_label(start_label);
    Expression true_label_expression = driver.expression_from_label(true_label);
    Expression false_label_expression = driver.expression_from_label(false_label);
    driver.generate_label(start_label_expression);
    Expression expression = rule_expression_a();
    driver.generate_if(expression, true_label_expression);
    driver.generate_goto(false_label_expression);
    driver.generate_label(true_label_expression);
    eat(RIGHT_PARENTHESIS);
    rule_block_or_statement();
    driver.generate_goto(start_label_expression);
    driver.generate_label(false_label_expression);
    driver.pop_label();
}

void Parser::rule_statement_do_while() {
    eat(DO);
    int true_label = driver.create_label();
    int false_label = driver.create_label();
    driver.push_label(false_label);
    Expression true_label_expression = driver.expression_from_label(true_label);
    Expression false_label_expression = driver.expression_from_label(false_label);
    driver.generate_label(true_label_expression);
    rule_block_or_statement();
    eat(WHILE);
    eat(LEFT_PARENTHESIS);
    Expression expression = rule_expression_a();
    eat(RIGHT_PARENTHESIS);
    driver.generate_if(expression, true_label_expression);
    driver.generate_goto(false_label_expression);
    driver.generate_label(false_label_expression);
    driver.pop_label();
    eat(SEMICOLON);
}

void Parser::rule_statement_assign() {
    Expression assignable = rule_statement_left_side();
    eat(ASSIGN);
    Expression expression = rule_expression_a();
    eat(SEMICOLON);
    driver.semantic_variables(driver.generate_assignment(assignable, expression));
}

Expression Parser::rule_statement_left_side() {
    std::string id = lexer->YYText();
    eat(ID);
    driver.set_parser_id(id);
    return rule_statement_left_side_();
}

Expression Parser::rule_statement_left_side_() {
    if (token == DOT) {
        std::string id = driver.get_parser_id();
        eat(DOT);
        std::string attribute = lexer->YYText();
        eat(ID);
        return driver.expression_from_structure_variable(id, attribute);
    }
    else {
        std::string id = driver.get_parser_id();
        return driver.expression_from_variable(id);
    }
}

void Parser::rule_statement_putw() {
    Expression expression = rule_expression_a();
    eat(RIGHT_PARENTHESIS);
    eat(SEMICOLON);
    driver.generate_print(expression);
}

void Parser::rule_statement_puts() {
    std::string string = lexer->YYText();
    eat(STRING);
    eat(RIGHT_PARENTHESIS);
    eat(SEMICOLON);
    Constant string_constant = driver.semantic_constant_string(string);
    Expression expression = driver.expression_from_constant(string_constant.get_id());
    driver.generate_print(expression);
}

void Parser::rule_statement_scan() {
    eat(SCAN);
    eat(LEFT_PARENTHESIS);
    std::string id = lexer->YYText();
    eat(ID);
    eat(RIGHT_PARENTHESIS);
    eat(SEMICOLON);
    Expression expression = driver.expression_from_variable(id);
    driver.generate_scan(expression);
}

void Parser::rule_statement_break() {
    eat(BREAK);
    eat(SEMICOLON);
    int jump_to_label = driver.top_label();
    Expression jump_to_label_expression = driver.expression_from_label(jump_to_label);
    driver.generate_goto(jump_to_label_expression);
}

void Parser::rule_statement_return() {
    eat(RETURN);
    rule_statement_return_();
}

void Parser::rule_statement_return_() {
    if (token == SEMICOLON) {
        eat(SEMICOLON);
        driver.semantic_return_void();
        driver.generate_return();
    }
    else if (token == NEGATE || token == ID || token == LEFT_PARENTHESIS || token == NUMBER_INTEGER || token == NUMBER_FLOAT || token == NUMBER_DOUBLE) {
        Expression expression = rule_expression_a();
        eat(SEMICOLON);
        Expression expression_ = driver.semantic_temporary(driver.expression_from_return());
        driver.semantic_return_expression(expression);
        driver.semantic_returns(std::vector<Expression>{expression_});
        driver.semantic_variables(driver.generate_assignment(expression_, expression));
        driver.generate_return(expression_);
    }
}

Expression Parser::rule_expression_a() {
    Expression expression_b = rule_expression_b();
    driver.set_parser_expression(expression_b);
    Expression expression_a_ = rule_expression_a_();
    return expression_a_;
}

Expression Parser::rule_expression_a_() {
    if (token == DISJOIN) {
        Expression expression = driver.get_parser_expression();
        eat(DISJOIN);
        Expression expression_b = rule_expression_b();
        std::vector<Expression> temporals = driver.generate_disjunction(expression, expression_b);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_a_();
        return expression_;
    }
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_b() {
    Expression expression_c = rule_expression_c();
    driver.set_parser_expression(expression_c);
    Expression expression_b_ = rule_expression_b_();
    return expression_b_;
}

Expression Parser::rule_expression_b_() {
    if (token == CONJOIN) {
        Expression expression = driver.get_parser_expression();
        eat(CONJOIN);
        Expression expression_c = rule_expression_c(); 
        std::vector<Expression> temporals = driver.generate_conjunction(expression, expression_c);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_b_();
        return expression_;
    }
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_c() {
    Expression expression_d = rule_expression_d();
    driver.set_parser_expression(expression_d);
    Expression expression_c_ = rule_expression_c_();
    return expression_c_;
}

Expression Parser::rule_expression_c_() {
    if (token == EQUAL) {
        Expression expression = driver.get_parser_expression();
        eat(EQUAL);
        Expression expression_d = rule_expression_d();
        std::vector<Expression> temporals = driver.generate_equality(expression, expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_c_();
        return expression_;
    }
    else if (token == DIFFERENT) {
        Expression expression = driver.get_parser_expression();
        eat(DIFFERENT);
        Expression expression_d = rule_expression_d();
        std::vector<Expression> temporals = driver.generate_not_equality(expression, expression_d);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_c_();
        return expression_;
    }
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_d() {
    Expression expression_e = rule_expression_e();
    driver.set_parser_expression(expression_e);
    Expression expression_d_ = rule_expression_d_();
    return expression_d_;
}

Expression Parser::rule_expression_d_() {
    if (token == LESS) {
        Expression expression = driver.get_parser_expression();
        eat(LESS);
        Expression expression_e = rule_expression_e();
        std::vector<Expression> temporals = driver.generate_less_inequality(expression, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_d_();
        return expression_;
    }
    else if (token == GREATER) {
        Expression expression = driver.get_parser_expression();
        eat(GREATER);
        Expression expression_e = rule_expression_e();
        std::vector<Expression> temporals = driver.generate_greater_inequality(expression, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_d_();
        return expression_;
    }
    else if (token == LESS_EQUAL) {
        Expression expression = driver.get_parser_expression();
        eat(LESS_EQUAL);
        Expression expression_e = rule_expression_e();
        std::vector<Expression> temporals = driver.generate_less_equal_inequality(expression, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_d_();
        return expression_;
    }
    else if (token == GREATER_EQUAL) {
        Expression expression = driver.get_parser_expression();
        eat(GREATER_EQUAL);
        Expression expression_e = rule_expression_e();
        std::vector<Expression> temporals = driver.generate_greater_equal_inequality(expression, expression_e);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];
        driver.set_parser_expression(expression_);
        rule_expression_d_();
        return expression_;
    }  
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_e() {
    Expression expression_f = rule_expression_f();
    driver.set_parser_expression(expression_f);
    Expression expression_e_ = rule_expression_e_();
    return expression_e_;
}

Expression Parser::rule_expression_e_() {
    if (token == ADD) {
        Expression expression = driver.get_parser_expression();
        eat(ADD);
        Expression expression_f = rule_expression_f();
        std::vector<Expression> temporals = driver.generate_addition(expression, expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0]; 
        driver.set_parser_expression(expression_);
        rule_expression_e_();
        return expression_;
    }
    else if (token == SUBSTRACT) {
        Expression expression = driver.get_parser_expression();
        eat(SUBSTRACT);
        Expression expression_f = rule_expression_f();
        std::vector<Expression> temporals = driver.generate_substraction(expression, expression_f);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];  
        driver.set_parser_expression(expression_);
        rule_expression_e_();
        return expression_;
    }
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_f() {
    Expression expression_g = rule_expression_g();
    driver.set_parser_expression(expression_g);
    Expression expression_f_ = rule_expression_f_();
    return expression_f_;
}

Expression Parser::rule_expression_f_() {
    if (token == MULTIPLY) {
        Expression expression = driver.get_parser_expression();
        eat(MULTIPLY);
        Expression expression_g = rule_expression_g();
        std::vector<Expression> temporals = driver.generate_multiplication(expression, expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0];         
        driver.set_parser_expression(expression_);
        rule_expression_f_();
        return expression_;
    }
    else if (token == DIVIDE) {
        Expression expression = driver.get_parser_expression();
        eat(DIVIDE);
        Expression expression_g = rule_expression_g();
        std::vector<Expression> temporals = driver.generate_division(expression, expression_g);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0]; 
        driver.set_parser_expression(expression_);
        rule_expression_f_();
        return expression_;
    }
    Expression expression = driver.get_parser_expression();
    return expression;
}

Expression Parser::rule_expression_g() {
    if (token == NEGATE) {
        eat(NEGATE);
        Expression expression_h = rule_expression_h();
        std::vector<Expression> temporals = driver.generate_negation(expression_h);
        driver.semantic_variables(temporals);
        Expression expression_ = temporals[0]; 
        return expression_;
    }
    else if (token == ID || token == NUMBER_INTEGER || token == NUMBER_FLOAT || token == NUMBER_DOUBLE || token == LEFT_PARENTHESIS) {
        Expression expression_h = rule_expression_h();
        return expression_h;
    }
    else error("Se esperaba !, id, numero, (");
}

Expression Parser::rule_expression_h() {
    if (token == ID) {
        std::string id = lexer->YYText();
        eat(ID);
        driver.set_parser_id(id);
        return rule_expression_h_();
    }
    else if (token == LEFT_PARENTHESIS) {
        eat(LEFT_PARENTHESIS);
        Expression expression = rule_expression_a();
        eat(RIGHT_PARENTHESIS);
        return expression;
    }
    else if (token == NUMBER_INTEGER) {
        int value = std::stoi(lexer->YYText());
        eat(NUMBER_INTEGER);
        Expression expression = driver.expression_from_integer(value);
        return expression;
    }
    else if (token == NUMBER_FLOAT) {
        float value = std::stof(lexer->YYText());
        eat(NUMBER_FLOAT);
        Constant constant = driver.semantic_constant_float(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        return expression;
    }
    else if (token == NUMBER_DOUBLE) {
        double value = std::stod(lexer->YYText());
        eat(NUMBER_DOUBLE);
        Constant constant = driver.semantic_constant_double(value);
        Expression expression = driver.expression_from_constant(constant.get_id());
        return expression;
    }
    else error("Se esperaba id, numero, (");
}

Expression Parser::rule_expression_h_() {
    if (token == LEFT_PARENTHESIS) {
        std::string id = driver.get_parser_id();
        eat(LEFT_PARENTHESIS);
        std::vector<Expression> list = rule_list_parameters();
        eat(RIGHT_PARENTHESIS);
        Expression expression_function = driver.expression_from_function(id);
        Expression expression_number = driver.expression_from_integer(static_cast<int>(list.size()));
        Expression expression = driver.semantic_temporary(expression_function);
        driver.semantic_variables(std::vector<Expression>{expression});
        driver.generate_call(expression, expression_function, expression_number);
        return expression;
    }
    else if (token == DOT) {
        std::string id = driver.get_parser_id();
        eat(DOT);
        std::string attribute = lexer->YYText();
        eat(ID);
        Expression expression = driver.expression_from_structure_variable(id, attribute);
        return expression;
    }
    else {
        std::string id = driver.get_parser_id();
        Expression expression = driver.expression_from_variable(id);
        return expression;
    }
}

std::vector<Expression> Parser::rule_list_parameters() {
    if (token == NEGATE || token == ID || token == LEFT_PARENTHESIS || token == NUMBER_INTEGER || token == NUMBER_FLOAT || token == NUMBER_DOUBLE) {
        std::vector<Expression> list;
        driver.set_parser_list(list);
        return rule_parameters();
    }
    std::vector<Expression> list;
    return list;
}

std::vector<Expression> Parser::rule_parameters() {
    std::vector<Expression> list = driver.get_parser_list();
    std::string id = driver.get_parser_id();
    Expression parameter = rule_parameter();
    driver.set_parser_id(id);
    list.push_back(parameter);
    driver.set_parser_list(list);
    return rule_parameters_();
}

std::vector<Expression> Parser::rule_parameters_() {
    if (token == COMMA) {
        std::vector<Expression> list = driver.get_parser_list();
        std::string id = driver.get_parser_id();
        eat(COMMA);
        Expression parameter = rule_parameter();
        driver.set_parser_id(id);
        list.push_back(parameter);
        driver.set_parser_list(list);
        return rule_parameters_();
    }
    else {
        std::string id = driver.get_parser_id();
        std::vector<Expression> list = driver.get_parser_list();
        driver.semantic_parameters(id, list);
        for (int i = 0; i < list.size(); i++) {
            Expression expression_ = driver.semantic_temporary(driver.expression_from_argument(id, i));
            driver.semantic_variables(std::vector<Expression>{expression_});
            driver.semantic_variables(driver.generate_assignment(expression_, list[i]));
            driver.generate_parameter(expression_);
        }
        return list;
    }
}

Expression Parser::rule_parameter() {
    Expression expression = rule_expression_a();
    return expression;
}

void Parser::eat(int next_token) {
    if (token == next_token) {
        // std::cout << "El token aceptado es: " << next_token << std::endl;
        this->token = lexer->yylex();
        // std::cout << "El token siguiente es: " << this->token << std::endl;
    }
    else error("Se esperaba el token " + std::to_string(next_token));
}

void Parser::parse() {
    this->token = this->lexer->yylex();
    rule_program();
    if (token == 0) {
        std::cout << "La cadena es aceptada" << endl;
        driver.print();
        driver.translate_data();
        driver.translate_end();
    }
    else {
        std::cout << "La cadena no pertenece al lenguaje generado por la gramática" << endl;
    }
}

void Parser::error(std::string message) {
    std::cout << message << std::endl;
    throw std::exception();
}


