#include "SymbolTableStack.hpp"

SymbolTableStack::SymbolTableStack() {
    std::stack<SymbolTable> symbol_tables;
    SymbolTable global_table;
}

SymbolTableStack::~SymbolTableStack() {

}

void SymbolTableStack::push_symbol_table(SymbolTable symbol_table) {
    this->symbol_tables.push(symbol_table);
}

SymbolTable SymbolTableStack::pop_symbol_table() {
    SymbolTable top = this->symbol_tables.top();
    this->symbol_tables.pop();
    return top;
}

SymbolTable& SymbolTableStack::get_top_table() {
    if (static_cast<int>(this->symbol_tables.size()) > 0) {
        return this->symbol_tables.top();
    } else {
        return this->global_table;
    }
}

SymbolTable& SymbolTableStack::get_global_table() {
    return this->global_table;
}

