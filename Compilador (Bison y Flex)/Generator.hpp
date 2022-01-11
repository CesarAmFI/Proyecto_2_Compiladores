#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <iterator>
#include <sstream>

#include "SymbolTable.hpp"
#include "TypeTable.hpp"
#include "Constant.hpp"
#include "Quad.hpp"
#include "QuadType.hpp"
#include "QuadResolver.hpp"
#include "Instruction.hpp"
#include "InstructionType.hpp"

const int P_WORD = 0;
const int P_SINGLE = 1;
const int P_DOUBLE = 2; 
const int P_STRING = 3; 

const std::string ZERO_WORD = "$zero_word";
const std::string ZERO_SINGLE = "$zero_single";
const std::string ZERO_DOUBLE = "$zero_double";

const std::string ONE_WORD = "$one_word";
const std::string ONE_SINGLE = "$one_single";
const std::string ONE_DOUBLE = "$one_double";

class Generator {

    private:

        std::vector<Constant> program_data;
        std::vector<Instruction> program_text;

        TypeTable* type_table;

        SymbolTable symbol_table;
        std::map<std::string, SymbolTable> symbol_tables;

        std::vector<Quad> code;

        QuadResolver quad_resolver;

        std::queue<std::string> register_memory;

        int register_free_f;
        int register_free_t;
        std::stack<int> register_limit_f;
        std::stack<int> register_limit_t;

        std::ofstream file;
        
    public:
        Generator();
        ~Generator();

        void set_type_table(TypeTable* type_table);
        void set_symbol_table(std::string id, SymbolTable table);

        void reserve_register(Expression expression);
        void adjust_register(Expression expression);
        void push_limit_register(Expression expression);
        void pop_limit_register(Expression expression);
        void unreserve_registers();

        std::string get_mnemonic(Expression expression, InstructionType type);
        std::string get_argument(Expression expression, InstructionType type);
        std::string get_register_reserved(Expression expression);
        std::string get_register_unreserved(Expression expression);
        std::string get_zero(Expression expression);
        std::string get_one(Expression expression);
        std::string get_system_read_register(Expression expression);
        std::string get_system_write_register(Expression expression);
        std::string get_address(Expression expression);
        std::string get_address(Expression expression, SymbolTable symbol_table);
        int get_precision(Expression expression);

        void translate_global_table(SymbolTable global_table);
        void translate_constants_table(std::map<std::string, Constant> constants_table);
        void translate_custom_constants();
        void translate_code(std::vector<Quad> code);

        void to_file();
        void error(std::string message);

};


#endif