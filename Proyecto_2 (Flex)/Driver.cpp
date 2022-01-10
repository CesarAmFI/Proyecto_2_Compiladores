#include "Driver.hpp"

Driver::Driver() {
    this->code_translated = 0;
}

Driver::~Driver() {

}

TypeTable Driver::get_type_table() {
    return this->type_table;
}
    
SymbolTableStack Driver::get_symbol_table_stack() {
    return this->symbol_table_stack;
}

std::map<std::string, Constant> Driver::get_constants() {
    return this->constants;
}

std::vector<Quad> Driver::get_code_generator() {
    return this->code_generator;
}

/* ------------------------------------------------------- */

int Driver::get_parser_type() {
    return this->parser_type;
}

std::string Driver::get_parser_id() {
    return this->parser_id;
}

std::vector<Expression> Driver::get_parser_list() {
    return this->parser_list;
}

Expression Driver::get_parser_expression() {
    return this->parser_expression;
}

Expression Driver::get_parser_false_label() {
    return this->parser_false_label;
}

Expression Driver::get_parser_next_label() {
    return this->parser_next_label;
}

/* ------------------------------------------------------- */

void Driver::set_parser_type(int parser_type) {
    this->parser_type = parser_type;
}

void Driver::set_parser_id(std::string parser_id) {
    this->parser_id = parser_id;
}

void Driver::set_parser_list(std::vector<Expression> parser_list) {
    this->parser_list = parser_list;
}

void Driver::set_parser_expression(Expression parser_expression) {
    this->parser_expression = parser_expression;
}

void Driver::set_parser_false_label(Expression parser_false_label) {
    this->parser_false_label = parser_false_label;
}

void Driver::set_parser_next_label(Expression parser_next_label) {
    this->parser_next_label = parser_next_label;
} 

/* ------------------------------------------------------- */

Expression Driver::maximum(Expression expression_1, Expression expression_2) {
    if (is_larger(expression_2, expression_1)) return expression_2;
    return expression_1;
}

Expression Driver::minimum(Expression expression_1, Expression expression_2) {
    if (is_smaller(expression_2, expression_1)) return expression_2;
    return expression_1;
}

bool Driver::is_larger(Expression expression_1, Expression expression_2) {
    Type type_1 = this->type_table.get_type_by_id(expression_1.get_type());
    Type type_2 = this->type_table.get_type_by_id(expression_2.get_type());
    if (type_1.get_size() > type_2.get_size()) return true;
    if (type_1.get_size() < type_2.get_size()) return false;
    if (type_1.get_name() == "int" && type_2.get_name() == "char") return true;
    if (type_1.get_name() == "float" && type_2.get_name() == "char") return true;
    if (type_1.get_name() == "float" && type_2.get_name() == "int") return true;
    return false;
}

bool Driver::is_smaller(Expression expression_1, Expression expression_2) {
    Type type_1 = this->type_table.get_type_by_id(expression_1.get_type());
    Type type_2 = this->type_table.get_type_by_id(expression_2.get_type());
    if (type_1.get_size() < type_2.get_size()) return true;
    if (type_1.get_size() > type_2.get_size()) return false;
    if (type_1.get_name() == "char" && type_2.get_name() == "int") return true;
    if (type_1.get_name() == "char" && type_2.get_name() == "float") return true;
    if (type_1.get_name() == "int" && type_2.get_name() == "float") return true;
    return false;
}

bool Driver::is_simple_type(Expression expression) {
    Type type = this->type_table.get_type_by_id(expression.get_type());
    std::vector<std::string> cr = {"char", "int", "float", "double"};
    return (std::find(cr.begin(), cr.end(), type.get_name()) != cr.end());
}

bool Driver::is_compound_type(Expression expression) {
    Type type = this->type_table.get_type_by_id(expression.get_type());
    return type.get_name() == "struct";
}

bool Driver::are_compatible(Expression expression_1, Expression expression_2) {
    Type type_1 = this->type_table.get_type_by_id(expression_1.get_type());
    Type type_2 = this->type_table.get_type_by_id(expression_2.get_type());
    if (is_simple_type(expression_1) && is_simple_type(expression_2)) return true;
    if (is_compound_type(expression_1) && is_compound_type(expression_2)) return type_1.get_base_type().is_equivalent(type_2.get_base_type());
    return false;
}

bool Driver::are_castable(Expression expression_1, Expression expression_2) {
    if (expression_1.get_type() == expression_2.get_type()) return false;
    if (is_simple_type(expression_1) && is_simple_type(expression_2)) return true;
    return false;
}

/* ------------------------------------------------------- */

bool Driver::exists_global_symbol(std::string id) {
    return this->symbol_table_stack.get_global_table().has_symbol_with_id(id);
}

bool Driver::exists_local_symbol(std::string id) {
    return this->symbol_table_stack.get_top_table().has_symbol_with_id(id);
} 

bool Driver::exists_function(std::string id) {
    if (!exists_global_symbol(id)) return false;
    Symbol symbol = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    return symbol.get_category() == "fun";
}

bool Driver::exists_argument(std::string id, int position) {
    if (!exists_function(id)) return false;
    Symbol symbol = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    return symbol.get_arguments().size() > position;
}

bool Driver::exists_structure(std::string id) {
    if (!exists_global_symbol(id)) return false;
    Symbol symbol = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    return symbol.get_category() == "struct";
}

bool Driver::exists_structure_variable(std::string id, std::string attribute) {
    if (!exists_global_symbol(id) && !exists_local_symbol(id)) return false;
    SymbolTable table = this->symbol_table_stack.get_global_table().has_symbol_with_id(id) ? this->symbol_table_stack.get_global_table() : this->symbol_table_stack.get_top_table();
    Symbol symbol = table.get_symbol_by_id(id);
    Type type = this->type_table.get_type_by_id(symbol.get_type());
    if (type.get_name() != "struct") return false;
    return type.get_base_type().has_symbol_with_id(attribute);
}

bool Driver::exists_variable(std::string id) {
    SymbolTable table = exists_global_symbol(id) ? this->symbol_table_stack.get_global_table() : this->symbol_table_stack.get_top_table();
    if (!table.has_symbol_with_id(id)) return false;
    Symbol symbol = table.get_symbol_by_id(id);
    return symbol.get_category() == "var" || symbol.get_category() == "param";
}

bool Driver::exists_constant(std::string id) {
    return constants.count(id);
}

/* ------------------------------------------------------- */

Expression Driver::expression_from_label(int id) {
    return Expression(-1, "L" + std::to_string(id), "L" + std::to_string(id), true);
}

Expression Driver::expression_from_label(std::string id) {
    return Expression(-1, id, id, true);
}

Expression Driver::expression_from_return() {
    return Expression(this->type_return, "$return", "$return", false);
}

Expression Driver::expression_from_integer(int number) {
    int type = this->type_table.get_type_by_name("int").get_id();
    return Expression(type, std::to_string(number), std::to_string(number), true);
}

Expression Driver::expression_from_temporary(int id, int type) {
    return Expression(type, "$t" + std::to_string(id), "$t" + std::to_string(id), false);
}

Expression Driver::expression_from_function(std::string id) {
    if (!exists_function(id)) error("Funcion con id " + id + " no existe");
    Symbol function = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    return Expression(function.get_type(), id, id, false);
}

Expression Driver::expression_from_argument(std::string id, int position) {
    if (!exists_function(id)) error("Funcion con id " + id + " no existe en argumentos");
    if (!exists_argument(id, position)) error("Funcion no tiene tantos argumentos");
    Symbol function = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    std::vector<Expression> arguments = function.get_arguments();
    return Expression(arguments[position].get_type(), arguments[position].get_address(), arguments[position].get_address(), false);
}

Expression Driver::expression_from_structure(std::string id) {
    if (!exists_structure(id)) error("Estructura con id " + id + " no existe");
    Symbol structure = this->symbol_table_stack.get_global_table().get_symbol_by_id(id);
    return Expression(structure.get_type(), id, id, false);
}

Expression Driver::expression_from_structure_variable(std::string id, std::string attribute) {
    if (!exists_structure_variable(id, attribute)) error("No existe " + id + "." + attribute);
    SymbolTable table = this->symbol_table_stack.get_global_table().has_symbol_with_id(id) ? this->symbol_table_stack.get_global_table() : this->symbol_table_stack.get_top_table();
    Symbol var = table.get_symbol_by_id(id);
    Symbol attr = this->type_table.get_type_by_id(var.get_type()).get_base_type().get_symbol_by_id(attribute);
    return Expression(attr.get_type(), id + "$" + attribute, id + "[" + std::to_string(attr.get_address()) + "]", false);
}

Expression Driver::expression_from_variable(std::string id) {
    if (!exists_variable(id)) error("Variable con id " + id + " no existe");
    bool global = this->symbol_table_stack.get_global_table().has_symbol_with_id(id);
    SymbolTable table = global ? this->symbol_table_stack.get_global_table() : this->symbol_table_stack.get_top_table();
    Symbol variable = table.get_symbol_by_id(id);
    return Expression(variable.get_type(), id, id, false);
}

Expression Driver::expression_from_constant(std::string id) {
    if (!exists_constant(id)) error("Constante " + id + " no existe");
    Constant constant = constants[id];
    return Expression(constant.get_type(), constant.get_id(), constant.get_id(), false);
}

/* ------------------------------------------------------- */

int Driver::create_label() {
    return this->label_number++;
}

int Driver::top_label() {
    return labels_stack.top();
}

int Driver::pop_label() {
    int top = top_label();
    labels_stack.pop();
    return top;
}

void Driver::push_label(int label) {
    labels_stack.push(label);
}

/* ------------------------------------------------------- */

int  Driver::create_temporary() {
    return this->temporary++;
}

int Driver::top_temporary() {
    return temporary_stack.top();
}

int Driver::pop_temporary() {
    int top = top_temporary();
    temporary_stack.pop();
    return top;
}

void Driver::push_temporary(int temporary) {
    temporary_stack.push(temporary);
}

/* ------------------------------------------------------- */

void Driver::semantic_create_context() {
    this->symbol_table_stack.push_symbol_table(SymbolTable());
    this->address_stack.push(address);
    this->address = 0;
    this->temporary_stack.push(temporary);
    this->temporary = 0;
}

void Driver::semantic_destroy_context() {
    this->symbol_table_stack.pop_symbol_table();
    this->address = this->address_stack.top();
    this->address_stack.pop();
    this->temporary = this->temporary_stack.top();
    this->temporary_stack.pop();
}

/* ------------------------------------------------------- */

void Driver::semantic_prepare_program() {
    this->type_table.add_type(Type(1, "void", 0, 0, SymbolTable()));
    this->type_table.add_type(Type(2, "char", 4, 0, SymbolTable()));
    this->type_table.add_type(Type(3, "int", 4, 0, SymbolTable()));
    this->type_table.add_type(Type(4, "float", 4, 0, SymbolTable()));
    this->type_table.add_type(Type(5, "double", 8, 0, SymbolTable()));
    this->type_table.add_type(Type(6, "string", -1, 0, SymbolTable()));
    this->generator.set_type_table(&this->type_table);
    this->temporary = 0;
    this->address = 0;
    this->label_number = 0;
    this->has_return = false;
    this->string_constants = 0;
    this->floating_constants = 0;   
}


void Driver::semantic_prepare_function(std::string id, int type) {
    if (exists_global_symbol(id)) error("Ya existe simbolo con id " + id);
    this->type_return = type;
    this->has_return = false;
}

void Driver::semantic_prepare_structure_function(std::string id, std::string struct_id) {
    if (exists_global_symbol(id)) error("Ya existe simbolo con id " + id);
    Expression expression = expression_from_structure(struct_id);
    this->has_return = false;
    this->type_return = expression.get_type();
}

void Driver::semantic_prepare_structure(std::string id) {
    if (exists_global_symbol(id)) error("Ya existe simbolo con id " + id);
}

/* ------------------------------------------------------- */

void Driver::semantic_function(std::string id, std::vector<Expression> arguments) {
    bool invalid_return = !this->has_return && this->type_return != this->type_table.get_type_by_name("void").get_id();
    if (invalid_return) error("Funcion debe tener retorno, no se encontro ninguno");
    this->symbol_table_stack.get_global_table().add_symbol(Symbol(id, this->type_return, -1, "fun", arguments));
}

void Driver::semantic_structure(std::string id) {
    int type_id = this->type_table.get_size() + 1;
    SymbolTable base_type = this->symbol_table_stack.get_top_table();
    this->type_table.add_type(Type(type_id, "struct", this->type_table.get_table_size(base_type), base_type.get_symbols().size(), base_type));
    // Estructura no es anonima
    if (id != "") this->symbol_table_stack.get_global_table().add_symbol(Symbol(id, type_id, -1, "struct", {}));}

void Driver::semantic_parameters(std::string id, std::vector<Expression> parameters) {
    int position = 0;
    for (Expression parameter : parameters) {
        Expression argument = expression_from_argument(id, position++);
        if (!are_compatible(parameter, argument)) error("Parametros incompatibles");
    }
}

void Driver::semantic_variables(std::vector<Expression> variables) {
    semantic_symbols(variables, "var");
}

void Driver::semantic_arguments(std::vector<Expression> arguments) {
    semantic_symbols(arguments, "param");
}

void Driver::semantic_returns(std::vector<Expression> returns) {
    semantic_symbols(returns, "return");
}

void Driver::semantic_symbols(std::vector<Expression> symbols, std::string category) {
    for (Expression symbol : symbols) {
        std::string id = symbol.get_address();
        if (exists_local_symbol(id)) error("Simbolo con id " + id + " ya existe");
        bool is_compound = is_compound_type(symbol);
        int type = symbol.get_type();
        int align = this->address % this->type_table.get_type_by_id(type).get_size();
        this->symbol_table_stack.get_top_table().add_symbol(Symbol(id, type, !is_compound ? this->address + align : -1, category, {}));
        this->address += !is_compound ? this->type_table.get_type_by_id(type).get_size() + align : 0;
        if (is_compound) {
            std::vector<Symbol> symbols_ = this->type_table.get_type_by_id(type).get_base_type().get_symbols();
            std::vector<Expression> attributes;
            for (Symbol symbol_ : symbols_) attributes.push_back(expression_from_structure_variable(id, symbol_.get_id()));
            semantic_symbols(attributes, category);
        }
    }
}

/* ------------------------------------------------------- */

void Driver::semantic_return_void() {
    int void_type = this->type_table.get_type_by_name("void").get_id();
    if (this->type_return != void_type) error("La funcion no puede retornar void");
    this->has_return = true;
}

void Driver::semantic_return_expression(Expression expression) {
    Expression expression_return = expression_from_return();
    if (this->type_return == this->type_table.get_type_by_name("void").get_id()) error("La funcion debe retornar void");
    if (!are_compatible(expression, expression_return)) error("La funcion no puede retornar ese tipo");
    this->has_return = true;
}

/* ------------------------------------------------------- */

Expression Driver::semantic_temporary(Expression expression) {
    return expression_from_temporary(create_temporary(), expression.get_type());
}

/* ------------------------------------------------------- */

Constant Driver::semantic_constant_float(float number) {
    int type = this->type_table.get_type_by_name("float").get_id();
    std::string id = "$float" + std::to_string(this->floating_constants++);
    Constant constant(type, id, std::to_string(number));
    this->constants[id] = constant;
    return constant;
}

Constant Driver::semantic_constant_double(double number) {
    int type = this->type_table.get_type_by_name("double").get_id();
    std::string id = "$float" + std::to_string(this->floating_constants++);
    Constant constant(type, id, std::to_string(number));
    this->constants[id] = constant;
    return constant;
}

Constant Driver::semantic_constant_string(std::string string) {
    int type = this->type_table.get_type_by_name("string").get_id();
    std::string id = "$string" + std::to_string(this->floating_constants++);
    Constant constant(type, id, string);
    this->constants[id] = constant;
    return constant;
}

/* ------------------------------------------------------- */

std::vector<Expression> Driver::generate_operation(Expression expression_1, Expression expression_2, std::string operation) {
    if (!are_compatible(expression_1, expression_2)) error("Tipos no compatibles en " + operation); 
    bool is_smaller_1 = is_smaller(expression_1, expression_2);
    bool is_smaller_2 = is_smaller(expression_2, expression_1);
    std::vector<Expression> expressions_1 = is_smaller_1 ? generate_upcast(expression_1, expression_2) : std::vector<Expression>{expression_1};
    std::vector<Expression> expressions_2 = is_smaller_2 ? generate_upcast(expression_2, expression_1) : std::vector<Expression>{expression_2};
    int temporary = create_temporary();
    Expression expression = expression_from_temporary(temporary, maximum(expression_1, expression_2).get_type());
    Quad quad = Quad(expression, expressions_1[0], operation, expressions_2[0]);
    this->code_generator.push_back(quad);
    std::vector<Expression> expressions;
    expressions.push_back(expression);
    if (is_smaller_1) expressions.insert(expressions.end(), expressions_1.begin(), expressions_1.end());
    if (is_smaller_2) expressions.insert(expressions.end(), expressions_2.begin(), expressions_2.end());
    return expressions;
}

std::vector<Expression> Driver::generate_addition(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "+");
}

std::vector<Expression> Driver::generate_substraction(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "-");
}

std::vector<Expression> Driver::generate_multiplication(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "*");
}

std::vector<Expression> Driver::generate_division(Expression expression_1, Expression expression_2) {
    if (expression_2.get_address() == "0") error("No se puede dividir entre 0");
    return generate_operation(expression_1, expression_2, "/");
}

std::vector<Expression> Driver::generate_disjunction(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "||");
}

std::vector<Expression> Driver::generate_conjunction(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "&&");
}

std::vector<Expression> Driver::generate_equality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "==");
}

std::vector<Expression> Driver::generate_not_equality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "!=");
}

std::vector<Expression> Driver::generate_less_inequality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "<");
}

std::vector<Expression> Driver::generate_greater_inequality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, ">");
}

std::vector<Expression> Driver::generate_less_equal_inequality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, "<=");
}

std::vector<Expression> Driver::generate_greater_equal_inequality(Expression expression_1, Expression expression_2) {
    return generate_operation(expression_1, expression_2, ">=");
}

std::vector<Expression> Driver::generate_negation(Expression expression) {
    int temporary = create_temporary();
    Expression expression_ = expression_from_temporary(temporary, expression.get_type());
    Quad quad = Quad(expression_, expression, "!");
    this->code_generator.push_back(quad);
    return std::vector<Expression>{expression};
}

std::vector<Expression> Driver::generate_downcast(Expression expression_1, Expression expression_2) {
    if (!are_compatible(expression_1, expression_2)) error("Tipos incompatibles en downcast");
    if (!is_larger(expression_1, expression_2)) error("Expresion no es mayor en downcast");
    return generate_cast(expression_1, expression_2);
}

std::vector<Expression> Driver::generate_upcast(Expression expression_1, Expression expression_2) {
    if (!are_compatible(expression_1, expression_2)) error("Tipos incompatibles en upcast");
    if (!is_smaller(expression_1, expression_2)) error("Expresion no es menor en upcast");
    return generate_cast(expression_1, expression_2);
}

std::vector<Expression> Driver::generate_cast(Expression expression_1, Expression expression_2) {
    std::string cast = "(" + this->type_table.get_type_by_id(expression_2.get_type()).get_name() + ")";
    int temporary = create_temporary();
    Expression expression = expression_from_temporary(temporary, expression_2.get_type());
    Quad quad = Quad(expression, expression_1, cast);
    this->code_generator.push_back(quad);
    return std::vector<Expression>{expression};
}

std::vector<Expression> Driver::generate_assignment(Expression expression_1, Expression expression_2) {
    if (!are_compatible(expression_1, expression_2)) error("Tipos no compatibles en asignacion");
    if (is_compound_type(expression_1)) { generate_assignment_structure(expression_1, expression_2); return {}; }
    bool smaller = is_smaller(expression_2, expression_1);
    bool larger = is_larger(expression_2, expression_1);
    std::vector<Expression> expressions_ = smaller ? generate_upcast(expression_2, expression_1) : larger ? generate_downcast(expression_2, expression_1) : std::vector<Expression>{expression_2};
    Quad quad = Quad(expression_1, expressions_[0], "=");
    this->code_generator.push_back(quad);
    std::vector<Expression> expressions;
    if (smaller || larger) expressions.insert(expressions.end(), expressions_.begin(), expressions_.end());
    return expressions;
}

// NOTA: SI GRAMATICA CAMBIA PARA ACEPTAR TIPOS ESTRUCTURADOS
// COMO PARAMETROS, DEBE CAMBIAR ESTA FUNCION.
void Driver::generate_parameter(Expression expression) {
    Quad quad = Quad(expression, "param");    
    this->code_generator.push_back(quad);
}

void Driver::generate_call(Expression expression_1, Expression expression_2, Expression expression_3) {
    Quad quad = Quad(expression_1, expression_2, "call", expression_3);
    this->code_generator.push_back(quad);
    generate_call_value(expression_1);
}

void Driver::generate_call_value(Expression expression) {
    std::vector<Expression> expressions;
    if (!is_compound_type(expression)) {
        expressions.push_back(expression);
    }
    else {
        SymbolTable symbol_table = this->type_table.get_type_by_id(expression.get_type()).get_base_type();
        for (Symbol symbol : symbol_table.get_symbols()) 
        expressions.push_back(expression_from_structure_variable(expression.get_address(), symbol.get_id()));
    }
    for (Expression expression_ : expressions) {
        Quad quad = Quad(expression_, "call value");
        this->code_generator.push_back(quad);
    }
}

void Driver::generate_assignment_structure(Expression expression_1, Expression expression_2) {
    if (!are_compatible(expression_1, expression_2)) error("Tipos no compatibles en asignacion");
    SymbolTable symbol_table_1 = this->type_table.get_type_by_id(expression_1.get_type()).get_base_type();
    SymbolTable symbol_table_2 = this->type_table.get_type_by_id(expression_2.get_type()).get_base_type();
    SymbolTable symbol_table_aux = symbol_table_2;
    for (Symbol symbol_1 : symbol_table_1.get_symbols()) {
        Symbol symbol_2 = symbol_table_aux.get_symbols_by_type(symbol_1.get_type())[0];
        Expression expression_1_ = expression_from_structure_variable(expression_1.get_address(), symbol_1.get_id());
        Expression expression_2_ = expression_from_structure_variable(expression_2.get_address(), symbol_2.get_id());
        symbol_table_aux.remove_symbol_by_id(symbol_2.get_id());
        generate_assignment(expression_1_, expression_2_);
    }
}

void Driver::generate_if(Expression expression_1, Expression expression_2) {
    Quad quad = Quad(expression_1, "if", expression_2);
    this->code_generator.push_back(quad);
}

void Driver::generate_label(Expression expression) {
    Quad quad = Quad(expression, "label");
    this->code_generator.push_back(quad);
}

void Driver::generate_goto(Expression expression) {
    Quad quad = Quad(expression, "goto");
    this->code_generator.push_back(quad);
}

void Driver::generate_print(Expression expression) {
    Quad quad = Quad(expression, "print");
    this->code_generator.push_back(quad);
}

void Driver::generate_scan(Expression expression) {
    Quad quad = Quad(expression, "scan");
    this->code_generator.push_back(quad);
}

void Driver::generate_return(Expression expression) {
    Expression expression_return = expression_from_return();
    if (!are_compatible(expression, expression_return)) error("Tipo de retorno incompatible");
    if (is_compound_type(expression)) { generate_returning(expression); return; }
    Quad quad = Quad(expression_return, expression, "return value");
    this->code_generator.push_back(quad);
}

void Driver::generate_returning(Expression expression) {
    SymbolTable symbol_table = this->type_table.get_type_by_id(expression.get_type()).get_base_type();
    for (Symbol symbol : symbol_table.get_symbols()) {
        Expression expression_ = expression_from_structure_variable(expression.get_address(), symbol.get_id());
        Quad quad = Quad(expression_, "returning");
        this->code_generator.push_back(quad);
    }
    generate_return();
}

void Driver::generate_return() {
    Quad quad = Quad("return");
    this->code_generator.push_back(quad);
}

/* ------------------------------------------------------- */

void Driver::complete_generate_return_void() {
    if (!this->has_return && this->type_return == this->type_table.get_type_by_name("void").get_id()) generate_return();
}

/* ------------------------------------------------------- */

void Driver::print() {
    std::cout << "------------Codigo Intermedio------------" << std::endl;
    for(Quad quad : this->code_generator) {
        std::cout << this->quad_print.resolve_string(quad);
    }
    std::cout << std::endl;
}

void Driver::error(std::string message) {
    std::cout << message << std::endl;
    throw std::exception();
}

void Driver::translate_text(std::string id) {
    if (this->code_translated == this->code_generator.size()) return; 
    SymbolTable top_table = this->symbol_table_stack.get_top_table();
    std::vector<Quad> code(this->code_generator.begin() + this->code_translated, this->code_generator.end());
    this->code_translated = this->code_generator.size();
    this->generator.set_symbol_table(id, top_table);
    this->generator.translate_code(code);
}

void Driver::translate_data() {
    SymbolTable global_table = this->symbol_table_stack.get_global_table();
    this->generator.translate_global_table(global_table);
    this->generator.translate_custom_constants();
    this->generator.translate_constants_table(this->constants);
}

void Driver::translate_end() {
    this->generator.to_file();
}





