#include "Generator.hpp"

Generator::Generator() {
    this->register_free_t = 0;
    this->register_free_f = 0;
    this->register_limit_t.push(0);
    this->register_limit_f.push(0);
}

Generator::~Generator() {

}

void Generator::set_type_table(TypeTable* type_table) {
    this->type_table = type_table;
}

void Generator::set_symbol_table(std::string id, SymbolTable table) {
    this->symbol_table = table;
    this->symbol_tables[id] = table;
}

void Generator::reserve_register(Expression expression) {
    if (get_precision(expression) == P_WORD) this->register_free_t += 1;
    else if (get_precision(expression) == P_SINGLE) this->register_free_f += 1;
    else if (get_precision(expression) == P_DOUBLE) this->register_free_f += 2;
    else error("Error en generacion de codigo, no se pudo reservar registro");
}

void Generator::push_limit_register(Expression expression) {
    if (get_precision(expression) == P_WORD) this->register_limit_t.push(this->register_free_t);
    else if (get_precision(expression) == P_SINGLE) this->register_limit_f.push(this->register_free_f);
    else if (get_precision(expression) == P_DOUBLE) this->register_limit_f.push(this->register_free_f);
    else error("Error en generacion de codigo, no se pudo reservar registro");
}

void Generator::pop_limit_register(Expression expression) {
    if (get_precision(expression) == P_WORD) this->register_limit_t.pop();
    else if (get_precision(expression) == P_SINGLE) this->register_limit_f.pop();
    else if (get_precision(expression) == P_DOUBLE) this->register_limit_f.pop();
    else error("Error en generacion de codigo, no se pudo reservar registro");
}

void Generator::adjust_register(Expression expression) {
    bool odd_register_f = this->register_free_f % 2 == 1;
    if (get_precision(expression) == P_DOUBLE && odd_register_f) this->register_free_f += 1;
}

void Generator::unreserve_registers() {
    this->register_free_t = register_limit_f.top();
    this->register_free_f = register_limit_f.top();
}

std::string Generator::get_system_read_register(Expression expression) {
    if (get_precision(expression) == P_WORD) return "$v0";
    else if (get_precision(expression) == P_SINGLE) return "$f0";
    else if (get_precision(expression) == P_DOUBLE) return "$f0";
    else error("Error en generacion de codigo, no se reconocio registro para print");   
}

std::string Generator::get_system_write_register(Expression expression) {
    if (get_precision(expression) == P_WORD) return "$a0";
    else if (get_precision(expression) == P_SINGLE) return "$f12";
    else if (get_precision(expression) == P_DOUBLE) return "$f12";
    else if (get_precision(expression) == P_STRING) return "$a0";
    else error("Error en generacion de codigo, no se reconocio registro para print");   
}

std::string Generator::get_register_reserved(Expression expression) {
    adjust_register(expression);
    std::string str = get_register_unreserved(expression);
    reserve_register(expression);
    return str;
}

std::string Generator::get_register_unreserved(Expression expression) {
    std::string str = "";
    if (get_precision(expression) == P_WORD) str += ("$t" + std::to_string(this->register_free_t));
    else if (get_precision(expression) == P_SINGLE) str += ("$f" + std::to_string(this->register_free_f));
    else if (get_precision(expression) == P_DOUBLE) str += ("$f" + std::to_string(this->register_free_f));
    else error("Error en generacion de codigo, no se pudo tomar registro");
    return str;
}

std::string Generator::get_address(Expression expression, SymbolTable symbol_table) {
    // absolute or relative to stack pointer
    std::string address = expression.get_address();
    if (symbol_table.has_symbol_with_id(address)) 
    return std::to_string(symbol_table.get_symbol_by_id(address).get_address()) + "($sp)"; 
    else return address;
}

std::string Generator::get_address(Expression expression) {
    return get_address(expression, this->symbol_table);
}

std::string Generator::get_mnemonic(Expression expression, InstructionType type) {
    switch (type) {
        case I_LOAD:
            if (get_precision(expression) == P_WORD && !expression.get_is_immediate()) return "lw";
            if (get_precision(expression) == P_WORD  && expression.get_is_immediate()) return "li";
            if (get_precision(expression) == P_SINGLE) return "l.s";
            if (get_precision(expression) == P_DOUBLE) return "l.d";
        case I_LOAD_DATA:
            if (get_precision(expression) == P_WORD) return "lw";
            if (get_precision(expression) == P_SINGLE) return "l.s";
            if (get_precision(expression) == P_DOUBLE) return "l.d";
        case I_LOAD_WRITE:
            if (get_precision(expression) == P_WORD) return "la";
            if (get_precision(expression) == P_SINGLE) return "l.s";
            if (get_precision(expression) == P_DOUBLE) return "l.d";
            if (get_precision(expression) == P_STRING) return "la";
        case I_STORE:
            if (get_precision(expression) == P_WORD) return "sw";
            if (get_precision(expression) == P_SINGLE) return "s.s";
            if (get_precision(expression) == P_DOUBLE) return "s.d";
        case I_CONVERT_TO_WORD:
            if (get_precision(expression) == P_SINGLE) return "cvt.w.s";
            if (get_precision(expression) == P_DOUBLE) return "cvt.w.d";
        case I_CONVERT_TO_SINGLE:
            if (get_precision(expression) == P_WORD) return "cvt.s.w";
            if (get_precision(expression) == P_DOUBLE) return "cvt.s.d";
        case I_CONVERT_TO_DOUBLE:
            if (get_precision(expression) == P_WORD) return "cvt.d.w";
            if (get_precision(expression) == P_SINGLE) return "ctw.d.s";
        case I_ADD:
            if (get_precision(expression) == P_WORD) return "add";
            if (get_precision(expression) == P_SINGLE) return "add.s";
            if (get_precision(expression) == P_DOUBLE) return "add.d";
        case I_SUBSTRACT:
            if (get_precision(expression) == P_WORD) return "sub";
            if (get_precision(expression) == P_SINGLE) return "sub.s";
            if (get_precision(expression) == P_DOUBLE) return "sub.d";
        case I_MULTIPLY:
            if (get_precision(expression) == P_WORD) return "mul";
            if (get_precision(expression) == P_SINGLE) return "mul.s";
            if (get_precision(expression) == P_DOUBLE) return "mul.d";
        case I_DIVIDE:
            if (get_precision(expression) == P_WORD) return "div";
            if (get_precision(expression) == P_SINGLE) return "div.s";
            if (get_precision(expression) == P_DOUBLE) return "div.d";
        case I_COMPARE_EQUAL:
            if (get_precision(expression) == P_SINGLE) return "c.eq.s";
            if (get_precision(expression) == P_DOUBLE) return "c.eq.d";
        case I_COMPARE_LESS:
            if (get_precision(expression) == P_SINGLE) return "c.lt.s";
            if (get_precision(expression) == P_DOUBLE) return "c.lt.d";
        case I_COMPARE_LESS_EQUAL:
            if (get_precision(expression) == P_SINGLE) return "c.le.s";
            if (get_precision(expression) == P_DOUBLE) return "c.le.d";
        case I_MOVE_ON_FALSE:
            if (get_precision(expression) == P_SINGLE) return "movf.s";
            if (get_precision(expression) == P_DOUBLE) return "movf.d";
        case I_MOVE_ON_TRUE:
            if (get_precision(expression) == P_SINGLE) return "movt.s";
            if (get_precision(expression) == P_DOUBLE) return "movt.d";
    }
}

std::string Generator::get_argument(Expression expression, InstructionType type) {
    switch (type) {
        case I_WRITE:
            if (get_precision(expression) == P_WORD) return "1";
            if (get_precision(expression) == P_SINGLE) return "2";
            if (get_precision(expression) == P_DOUBLE) return "3";
            if (get_precision(expression) == P_STRING) return "4";
        case I_READ:
            if (get_precision(expression) == P_WORD) return "5";
            if (get_precision(expression) == P_SINGLE) return "6";
            if (get_precision(expression) == P_DOUBLE) return "7";
            if (get_precision(expression) == P_STRING) return "8";
    }
}

std::string Generator::get_zero(Expression expression) {
    if (get_precision(expression) == P_WORD) return ZERO_WORD;
    if (get_precision(expression) == P_SINGLE) return ZERO_SINGLE;
    if (get_precision(expression) == P_DOUBLE) return ZERO_DOUBLE;
}

std::string Generator::get_one(Expression expression) {
    if (get_precision(expression) == P_WORD) return ONE_WORD;
    if (get_precision(expression) == P_SINGLE) return ONE_SINGLE;
    if (get_precision(expression) == P_DOUBLE) return ONE_DOUBLE;
}

int Generator::get_precision(Expression expression) {
    if (expression.get_type() == type_table->get_type_by_name("char").get_id()) return P_WORD;
    if (expression.get_type() == type_table->get_type_by_name("int").get_id()) return P_WORD;
    if (expression.get_type() == type_table->get_type_by_name("float").get_id()) return P_SINGLE;
    if (expression.get_type() == type_table->get_type_by_name("double").get_id()) return P_DOUBLE; 
    if (expression.get_type() == type_table->get_type_by_name("string").get_id()) return P_STRING; 
    else error("Error en generacion de codigo, no se pudo determinar tipo para: " + expression.get_address() + " con tipo: " + std::to_string(expression.get_type()));   
}

void Generator::translate_global_table(SymbolTable global_table) {
    for (Symbol symbol : global_table.get_symbols()) {
        if (symbol.get_category() != "var") continue;
        if (type_table->get_type_by_id(symbol.get_type()).get_name() == "struct") continue;
        program_data.push_back(Constant(symbol.get_type(), symbol.get_id(), "0"));
    }
}

void Generator::translate_constants_table(std::map<std::string, Constant> constants_table) {
    for (auto const& constant: constants_table) {
        program_data.push_back(constant.second);
    }
}

void Generator::translate_custom_constants() {
    program_data.push_back(Constant(this->type_table->get_type_by_name("int").get_id(), ZERO_WORD, "0"));
    program_data.push_back(Constant(this->type_table->get_type_by_name("float").get_id(), ZERO_SINGLE, "0.0"));
    program_data.push_back(Constant(this->type_table->get_type_by_name("double").get_id(), ZERO_DOUBLE, "0.0"));
    program_data.push_back(Constant(this->type_table->get_type_by_name("int").get_id(), ONE_WORD, "1"));
    program_data.push_back(Constant(this->type_table->get_type_by_name("float").get_id(), ONE_SINGLE, "1.0"));
    program_data.push_back(Constant(this->type_table->get_type_by_name("double").get_id(), ONE_DOUBLE, "1.0"));
}

void Generator::translate_code(std::vector<Quad> code) {
    for (Quad quad : code) {
        QuadType quad_type = quad_resolver.resolve_type(quad);
        std::cout << quad.get_operation() << " " << quad.get_operator_1().get_address() << " " << quad.get_operator_2().get_address() << " " << quad.get_result().get_address() << std::endl;

        if (quad_type == Q_IF) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_LOAD_DATA), {get_register_reserved(quad.get_operator_1()), get_zero(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2});               
            if (get_precision(quad.get_operator_1()) == P_WORD) {
                Instruction instruction_3("bne", {instruction_1.get_arguments()[0], instruction_2.get_arguments()[0], get_address(quad.get_operator_2())});
                this->program_text.insert(this->program_text.end(), {instruction_3});               
            }
            else {
                Instruction instruction_3(get_mnemonic(quad.get_operator_1(), I_COMPARE_EQUAL), {instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
                Instruction instruction_4("bc1f", {get_address(quad.get_operator_2())});
                this->program_text.insert(this->program_text.end(), {instruction_3, instruction_4});               
            }
            unreserve_registers();
        }
        else if (quad_type == Q_GOTO) {
            Instruction instruction_1("j", {get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
        }
        else if (quad_type == Q_LABEL) {
            Instruction instruction_1("", {get_address(quad.get_operator_1()) + ":"});
            this->program_text.insert(this->program_text.end(), {instruction_1});
        }
        else if (quad_type == Q_ASSIGN) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_unreserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_result(), I_STORE), {instruction_1.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2});
        }
        else if (quad_type == Q_SCAN) {
            Instruction instruction_1("li", {"$v0", get_argument(quad.get_operator_1(), I_READ)});     
            Instruction instruction_2("syscall", {});
            Instruction instruction_3(get_mnemonic(quad.get_operator_1(), I_STORE), {get_system_read_register(quad.get_operator_1()), get_address(quad.get_operator_1())});     
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3});

        }
        else if (quad_type == Q_PRINT) {
            Instruction instruction_1("li", {"$v0", get_argument(quad.get_operator_1(), I_WRITE)});     
            Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_LOAD_WRITE), {get_system_write_register(quad.get_operator_1()), get_address(quad.get_operator_1())});     
            Instruction instruction_3("syscall", {});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3});
        }
        else if (quad_type == Q_PARAM) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
            this->register_memory.push(instruction_1.get_arguments()[0]);
            pop_limit_register(quad.get_operator_1());
            push_limit_register(quad.get_operator_1());
        }
        else if (quad_type == Q_CALL) {
            unreserve_registers();
            int size = this->type_table->get_table_size(this->symbol_tables[quad.get_operator_1().get_address()]);
            int shift = size + 4 + (size % 8);
            std::vector<Symbol> parameter_symbols = this->symbol_tables[quad.get_operator_1().get_address()].get_symbols_by_category("param");
            std::vector<Symbol> return_symbols = this->symbol_tables[quad.get_operator_1().get_address()].get_symbols_by_category("return");
            Instruction instruction_1("addi", {"$sp", "$sp", std::to_string(-shift)});
            Instruction instruction_2("sw", {"$ra", std::to_string(shift - 4) + "($sp)"});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2});
            for (int i = 0; i < parameter_symbols.size(); i++) {
                if (this->type_table->get_type_by_id(parameter_symbols[i].get_type()).get_name() == "struct") continue;
                Symbol symbol = parameter_symbols[i];
                Expression expression(symbol.get_type(), symbol.get_id(), symbol.get_id(), false);
                Instruction instruction(get_mnemonic(expression, I_STORE), {this->register_memory.front(), get_address(expression, this->symbol_tables[quad.get_operator_1().get_address()])});
                this->register_memory.pop();
                this->program_text.insert(this->program_text.end(), {instruction});
            }
            Instruction instruction_3("jal", {quad.get_operator_1().get_address()});
            this->program_text.insert(this->program_text.end(), {instruction_3});
            for (int i = 0; i < return_symbols.size(); i++) {
                if (this->type_table->get_type_by_id(return_symbols[i].get_type()).get_name() == "struct") continue;
                Symbol symbol = return_symbols[i];
                Expression expression(symbol.get_type(), symbol.get_id(), symbol.get_id(), false);
                Instruction instruction(get_mnemonic(expression, I_LOAD), {get_register_reserved(expression), get_address(expression, this->symbol_tables[quad.get_operator_1().get_address()])});
                this->register_memory.push(instruction.get_arguments()[0]);
                this->program_text.insert(this->program_text.end(), {instruction});
            }
            unreserve_registers();
            Instruction instruction_4("lw", {"$ra", std::to_string(shift - 4) + "($sp)"});
            Instruction instruction_5("addi", {"$sp", "$sp", std::to_string(shift)});
            this->program_text.insert(this->program_text.end(), {instruction_4, instruction_5});
        }
        else if (quad_type == Q_CALL_VALUE) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_STORE), {this->register_memory.front(), get_address(quad.get_operator_1())});
            this->register_memory.pop();
            this->program_text.insert(this->program_text.end(), {instruction_1});
        }
        else if (quad_type == Q_RETURN_VALUE) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_unreserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_STORE), {instruction_1.get_arguments()[0], get_address(quad.get_operator_1())});
            Instruction instruction_3("jr", {"$ra"});           
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3});
        }
        else if (quad_type == Q_RETURN_VOID) {
            Instruction instruction_1("jr", {"$ra"});           
            this->program_text.insert(this->program_text.end(), {instruction_1});
        }
        else if (quad_type == Q_RETURNING) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_unreserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_STORE), {instruction_1.get_arguments()[0], get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2});
        }
        else if (quad_type == Q_CAST_TO_CHAR) {
            Instruction instruction_ph;
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
            if (get_precision(quad.get_operator_1()) == P_WORD) {
                instruction_ph = instruction_1;
            }
            else {
                Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_WORD), {get_register_reserved(quad.get_operator_1()), instruction_1.get_arguments()[0]});
                Instruction instruction_3("mfc1", {get_register_unreserved(quad.get_result()), instruction_2.get_arguments()[0]});
                instruction_ph = instruction_3;
                this->program_text.insert(this->program_text.end(), {instruction_2, instruction_3});
            }
            Instruction instruction_4("andi", {instruction_ph.get_arguments()[0], "0x000000FF"});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_STORE), {instruction_4.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_4, instruction_5});
            unreserve_registers();
        }
        else if (quad_type == Q_CAST_TO_INTEGER) {
            Instruction instruction_ph;
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
            if (get_precision(quad.get_operator_1()) == P_WORD) {
                instruction_ph = instruction_1;
            }
            else {
                Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_WORD), {get_register_reserved(quad.get_operator_1()), instruction_1.get_arguments()[0]});
                Instruction instruction_3("mfc1", {get_register_unreserved(quad.get_result()), instruction_2.get_arguments()[0]});
                instruction_ph = instruction_3;
                this->program_text.insert(this->program_text.end(), {instruction_2, instruction_3});
            }
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_ph.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_4});
            unreserve_registers();
        }
        else if (quad_type == Q_CAST_TO_FLOAT) {
            Instruction instruction_ph;
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
            if (get_precision(quad.get_operator_1()) == P_WORD) {
                Instruction instruction_2("mtc1", {instruction_1.get_arguments()[0], get_register_reserved(quad.get_result())});
                Instruction instruction_3(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_SINGLE), {get_register_reserved(quad.get_result()), instruction_2.get_arguments()[1]});
                instruction_ph = instruction_3; 
                this->program_text.insert(this->program_text.end(), {instruction_2, instruction_3});               
            }
            else {
                Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_SINGLE), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0]});
                instruction_ph = instruction_2;
                this->program_text.insert(this->program_text.end(), {instruction_2});
            }
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_ph.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_4});
            unreserve_registers();
        }
        else if (quad_type == Q_CAST_TO_DOUBLE) {
            Instruction instruction_ph;
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            this->program_text.insert(this->program_text.end(), {instruction_1});
            if (get_precision(quad.get_operator_1()) == P_WORD) {
                Instruction instruction_2("mtc1", {instruction_1.get_arguments()[0], get_register_reserved(quad.get_result())});
                Instruction instruction_3(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_DOUBLE), {get_register_reserved(quad.get_result()), instruction_2.get_arguments()[1]});
                instruction_ph = instruction_3; 
                this->program_text.insert(this->program_text.end(), {instruction_2, instruction_3});               
            }
            else {
                Instruction instruction_2(get_mnemonic(quad.get_operator_1(), I_CONVERT_TO_DOUBLE), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0]});
                instruction_ph = instruction_2;
                this->program_text.insert(this->program_text.end(), {instruction_2});
            }
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_ph.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_4});
            unreserve_registers();
        }
        else if (quad_type == Q_DISJOIN) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_bl;
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
            if (get_precision(quad.get_result()) != P_WORD) {
                Instruction instruction_5(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_6.get_arguments()[0], instruction_4.get_arguments()[0]});
                Instruction instruction_8(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_2.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_9(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_2.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_10(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_9.get_arguments()[0], instruction_4.get_arguments()[0]});
                Instruction instruction_11(get_mnemonic(quad.get_result(), I_ADD), {get_register_reserved(quad.get_result()), instruction_6.get_arguments()[0], instruction_9.get_arguments()[0]});
                Instruction instruction_12(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_11.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_13(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_11.get_arguments()[0], instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_9.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_5, instruction_6, instruction_7, instruction_8, instruction_9, instruction_10, instruction_11, instruction_12, instruction_13, instruction_bl});
            }
            else {
                Instruction instruction_5("sne", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_1.get_arguments()[0]});
                Instruction instruction_6("sne", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_2.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_ADD), {instruction_1.get_arguments()[0], instruction_5.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("sne", {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0], instruction_7.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_5, instruction_6, instruction_7, instruction_bl});

            }
            Instruction instruction_15(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_15});
            unreserve_registers();
        }
        else if (quad_type == Q_CONJOIN) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_bl;
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
            if (get_precision(quad.get_result()) != P_WORD) {
                Instruction instruction_5(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_6.get_arguments()[0], instruction_4.get_arguments()[0]});
                Instruction instruction_8(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_2.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_9(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_2.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_10(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_9.get_arguments()[0], instruction_4.get_arguments()[0]});
                Instruction instruction_11(get_mnemonic(quad.get_result(), I_MULTIPLY), {get_register_reserved(quad.get_result()), instruction_6.get_arguments()[0], instruction_9.get_arguments()[0]});
                Instruction instruction_12(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_11.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_13(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_11.get_arguments()[0], instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_9.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_5, instruction_6, instruction_7, instruction_8, instruction_9, instruction_10, instruction_11, instruction_12, instruction_13, instruction_bl});
            }
            else {
                Instruction instruction_5("sne", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_1.get_arguments()[0]});
                Instruction instruction_6("sne", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_2.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MULTIPLY), {instruction_1.get_arguments()[0], instruction_5.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("sne", {instruction_1.get_arguments()[0], instruction_3.get_arguments()[0], instruction_7.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_5, instruction_6, instruction_7, instruction_bl});

            }
            Instruction instruction_15(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_15});
            unreserve_registers();
        }
        else if (quad_type == Q_EQUAL) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            Instruction instruction_bl;
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("seq", {get_register_reserved(quad.get_result()), instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7("movz", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movn", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_NOT_EQUAL) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("seq", {get_register_reserved(quad.get_result()), instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7("movn", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movz", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_LESS) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("slt", {get_register_reserved(quad.get_result()), instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7("movz", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movn", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_LESS), {instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_GREATER) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("slt", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_5.get_arguments()[0]});
                Instruction instruction_7("movz", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movn", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_LESS), {instruction_3.get_arguments()[0], instruction_5.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_LESS_EQUAL) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("sle", {get_register_reserved(quad.get_result()), instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7("movz", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movn", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_LESS_EQUAL), {instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_GREATER_EQUAL) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_5(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4, instruction_5});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_6("sle", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_5.get_arguments()[0]});
                Instruction instruction_7("movz", {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0], instruction_6.get_arguments()[0]});
                instruction_bl = Instruction("movn", {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0], instruction_6.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            else {
                Instruction instruction_6(get_mnemonic(quad.get_result(), I_COMPARE_LESS_EQUAL), {instruction_3.get_arguments()[0], instruction_5.get_arguments()[0]});
                Instruction instruction_7(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_3.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_7.get_arguments()[0], instruction_4.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_6, instruction_7, instruction_bl});
            }
            Instruction instruction_9(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_9});
            unreserve_registers();
        }
        else if (quad_type == Q_ADD) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_ADD), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_3.get_arguments()[0], get_address(quad.get_result())});
            unreserve_registers();
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
        }
        else if (quad_type == Q_SUBSTRACT) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_SUBSTRACT), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_3.get_arguments()[0], get_address(quad.get_result())});
            unreserve_registers();
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
        }
        else if (quad_type == Q_MULTIPLY) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_MULTIPLY), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_3.get_arguments()[0], get_address(quad.get_result())});
            unreserve_registers();
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
        }
        else if (quad_type == Q_DIVIDE) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_operator_2(), I_LOAD), {get_register_reserved(quad.get_operator_2()), get_address(quad.get_operator_2())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_DIVIDE), {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
            Instruction instruction_4(get_mnemonic(quad.get_result(), I_STORE), {instruction_3.get_arguments()[0], get_address(quad.get_result())});
            unreserve_registers();
            this->program_text.insert(this->program_text.end(), {instruction_1, instruction_2, instruction_3, instruction_4});
        }
        else if (quad_type == Q_NEGATE) {
            Instruction instruction_1(get_mnemonic(quad.get_operator_1(), I_LOAD), {get_register_reserved(quad.get_operator_1()), get_address(quad.get_operator_1())});
            Instruction instruction_2(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_zero(quad.get_result())});
            Instruction instruction_3(get_mnemonic(quad.get_result(), I_LOAD_DATA), {get_register_reserved(quad.get_result()), get_one(quad.get_result())});
            Instruction instruction_bl;
            if (get_precision(quad.get_result()) == P_WORD) {
                Instruction instruction_4("seq", {get_register_reserved(quad.get_result()), instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
                Instruction instruction_5("movn", {get_register_reserved(quad.get_result()), instruction_2.get_arguments()[0], instruction_4.get_arguments()[0]});
                instruction_bl = Instruction("movz", {instruction_5.get_arguments()[0], instruction_2.get_arguments()[0], instruction_3.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_4, instruction_5, instruction_bl});
            }
            else {
                Instruction instruction_4(get_mnemonic(quad.get_result(), I_COMPARE_EQUAL), {instruction_1.get_arguments()[0], instruction_2.get_arguments()[0]});
                Instruction instruction_5(get_mnemonic(quad.get_result(), I_MOVE_ON_FALSE), {get_register_reserved(quad.get_result()), instruction_2.get_arguments()[0]});
                instruction_bl = Instruction(get_mnemonic(quad.get_result(), I_MOVE_ON_TRUE), {instruction_5.get_arguments()[0], instruction_3.get_arguments()[0]});
                this->program_text.insert(this->program_text.end(), {instruction_4, instruction_5, instruction_bl});
            }
            Instruction instruction_6(get_mnemonic(quad.get_result(), I_STORE), {instruction_bl.get_arguments()[0], get_address(quad.get_result())});
            this->program_text.insert(this->program_text.end(), {instruction_6});
            unreserve_registers();
        }
        else error("Error en generacion de codigo. Operacion desconocida");
    }
}

void Generator::to_file() {
    file.open("a_out.mips", std::ios::out);
    file << ".data" << std::endl;
    for (Constant constant : this->program_data) {
        Expression expression(constant.get_type(), constant.get_id(), constant.get_id(), false);
        int pr = get_precision(expression);
        std::string constant_type = pr == P_WORD ? "word" : pr == P_SINGLE ? "float" : pr == P_DOUBLE ? "double" : "asciiz";
        file << "\t" << constant.get_id() << ": ." << constant_type << " " << constant.get_value() << std::endl;
    }
    file << ".text" << std::endl;
    file << ".globl main" << std::endl;
    file << "\tandi $sp, 0xfffffff8" << std::endl;
    file << "\tjal main" << std::endl;
    file << "\tli $v0, 10"<< std::endl;
    file << "\tsyscall" << std::endl;
    for (Instruction instruction : this->program_text) {
        std::string arguments;
        for (std::string argument : instruction.get_arguments()) arguments += ((arguments.empty() ? "" : ", ") + argument);
        file << "\t" << instruction.get_mnemonic() << " " << arguments << std::endl;
    }
    file.close();
}

void Generator::error(std::string message) {
    std::cout << message << std::endl;
    throw std::exception();
}