#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

#include "TypeTable.hpp"
#include "Type.hpp"
#include "SymbolTableStack.hpp"
#include "SymbolTable.hpp"
#include "Symbol.hpp"
#include "Quad.hpp"
#include "QuadResolver.hpp"
#include "Constant.hpp"
#include "Expression.hpp"
#include "Generator.hpp"

class Driver
{

private:
    // Tablas
    TypeTable type_table;
    SymbolTableStack symbol_table_stack;

    // Para funciones
    bool has_return;
    int type_return;

    // Para constantes
    std::map<std::string, Constant> constants;
    int string_constants;
    int floating_constants;

    // Para etiquetas
    std::stack<int> labels_stack;
    int label_number;

    // Para direcciones
    std::stack<int> address_stack;
    int address;

    // Para temporales
    std::stack<int> temporary_stack;
    int temporary;

    // Codigo de tres direcciones
    std::vector<Quad> code_generator;
    int code_translated;

    // Impresion de codigo
    QuadResolver quad_print;

    // Otras etapas del compilador
    Generator generator;

public:
    Driver();
    ~Driver();

    // Para acceder a atributos
    TypeTable get_type_table();
    SymbolTableStack get_symbol_table_stack();
    std::map<std::string, Constant> get_constants();
    std::vector<Quad> get_code_generator();

    // Para manejar tipos
    Expression maximum(Expression expression_1, Expression expression_2); // max(e_1, e_2)
    Expression minimum(Expression expression_1, Expression expression_2); // min(e_1, e_2)
    bool is_larger(Expression expression_1, Expression expression_2);     // e_1 > e_2
    bool is_smaller(Expression expression_1, Expression expression_2);    // e_1 < e_2
    bool is_simple_type(Expression expression);
    bool is_compound_type(Expression expression);
    bool are_compatible(Expression expression_1, Expression expression_2); // e_1 ~ e_2
    bool are_castable(Expression expression_1, Expression expression_2);

    // Para verificar que existen en tabla de tipos y constantes
    bool exists_global_symbol(std::string id);
    bool exists_local_symbol(std::string id);
    bool exists_function(std::string id);
    bool exists_argument(std::string id, int position);
    bool exists_structure(std::string id);
    bool exists_variable(std::string id);
    bool exists_structure_variable(std::string id, std::string attribute);
    bool exists_constant(std::string id);

    // Para crear expresiones
    Expression expression_from_return();
    Expression expression_from_label(int id);
    Expression expression_from_label(std::string id);
    Expression expression_from_integer(int number);
    Expression expression_from_temporary(int id, int type);
    Expression expression_from_argument(std::string id, int position);
    Expression expression_from_function(std::string id);
    Expression expression_from_structure(std::string id);
    Expression expression_from_variable(std::string id);
    Expression expression_from_structure_variable(std::string id, std::string attribute);
    Expression expression_from_constant(std::string id);

    // Para operaciones con etiquetas
    int create_label();
    int top_label();
    int pop_label();
    void push_label(int label);

    // Para operaciones con temporales
    int create_temporary();
    int top_temporary();
    int pop_temporary();
    void push_temporary(int temporary);

    // Para contextos
    void semantic_create_context();
    void semantic_destroy_context();

    // Para preparar tablas de simbolos
    void semantic_prepare_program();
    void semantic_prepare_function(std::string id, int type);
    void semantic_prepare_structure_function(std::string id, std::string struct_id);
    void semantic_prepare_structure(std::string id);

    // Para agregar simbolos
    void semantic_function(std::string id, std::vector<Expression> arguments);
    void semantic_parameters(std::string id, std::vector<Expression> parameters);
    void semantic_structure(std::string id);
    void semantic_variables(std::vector<Expression> variables);
    void semantic_arguments(std::vector<Expression> arguments);
    void semantic_returns(std::vector<Expression> arguments);
    void semantic_symbols(std::vector<Expression> symbols, std::string category);

    // Para funciones
    void semantic_return_void();
    void semantic_return_expression(Expression expression);

    // Para temporal
    Expression semantic_temporary(Expression expression);

    // Para constantes
    Constant semantic_constant_string(std::string);
    Constant semantic_constant_float(float number);
    Constant semantic_constant_double(double number);

    // Para generaciones que generan temporales
    std::vector<Expression> generate_operation(Expression expression_1, Expression expression_2, std::string operation);
    std::vector<Expression> generate_addition(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_substraction(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_multiplication(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_division(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_conjunction(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_disjunction(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_equality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_not_equality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_less_inequality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_less_equal_inequality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_greater_inequality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_greater_equal_inequality(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_upcast(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_downcast(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_cast(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_assignment(Expression expression_1, Expression expression_2);
    std::vector<Expression> generate_negation(Expression expression);

    // Para generaciones que no generan temporales
    void generate_assignment_structure(Expression expression_1, Expression expression_2);
    void generate_if(Expression expression_1, Expression expression_2);
    void generate_label(Expression expression);
    void generate_goto(Expression expression);
    void generate_print(Expression expression);
    void generate_scan(Expression expression);
    void generate_parameter(Expression expression);
    void generate_call(Expression expression_1, Expression expression_2, Expression expression_3);
    void generate_call_value(Expression expression);
    void generate_return(Expression expression);
    void generate_returning(Expression expression);
    void generate_return();

    // Para completar generacion de codigo
    void complete_generate_return_void();

    // Operaciones de Driver
    void error(std::string message);
    void print();
    void translate_text(std::string id);
    void translate_data();
    void translate_end();
};

#endif