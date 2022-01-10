#ifndef SYMBOLTABLESTACK_H
#define SYMBOLTABLESTACK_H

#include <string>
#include <stack>

#include "SymbolTable.hpp"

class SymbolTableStack {

    private:
        std::stack<SymbolTable> symbol_tables;
        SymbolTable global_table;

    public:
        SymbolTableStack();
        ~SymbolTableStack();

        void push_symbol_table(SymbolTable symbol_table);
        SymbolTable pop_symbol_table();
        SymbolTable& get_top_table();
        SymbolTable& get_global_table();

};


#endif