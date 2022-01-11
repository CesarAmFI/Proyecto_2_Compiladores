#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Symbol.hpp"

class SymbolTable {

    private:
        std::vector<Symbol> symbols;

    public:
        SymbolTable();
        ~SymbolTable();

        void add_symbol(Symbol symbol);
        // void remove_symbol(Symbol symbol);
        void remove_symbol_by_id(std::string id);
        Symbol get_symbol_by_id(std::string id);
        bool has_symbol_with_id(std::string id);
        Symbol get_symbol_by_address(int address);
        bool has_symbol_with_address(int address);
        bool is_equivalent(SymbolTable symbol_table);
        std::vector<Symbol> get_symbols_by_type(int type);
        std::vector<Symbol> get_symbols_by_category(std::string category);
        std::vector<Symbol> get_symbols();

};


#endif