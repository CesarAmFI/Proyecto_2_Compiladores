#include "SymbolTable.hpp"

SymbolTable::SymbolTable() {
    std::vector<Symbol> symbols;
}

SymbolTable::~SymbolTable() {

}

void SymbolTable::add_symbol(Symbol symbol) {
    this->symbols.push_back(symbol);
}

void SymbolTable::remove_symbol_by_id(std::string id) {
    for (int i = 0; i < this->symbols.size(); i++) {
        if (this->symbols[i].get_id() != id) continue;
        this->symbols.erase(this->symbols.begin() + i);
        return;
    }
}

Symbol SymbolTable::get_symbol_by_id(std::string id) {
    for (Symbol symbol : this->symbols) {
        if (symbol.get_id() == id) return symbol;
    }
    throw new std::exception();
}

bool SymbolTable::has_symbol_with_id(std::string id) {
    for (Symbol symbol : this->symbols) {
        if (symbol.get_id() == id) return true;
    }
    return false;
}

Symbol SymbolTable::get_symbol_by_address(int address) {
    for (Symbol symbol : this->symbols) {
        if (symbol.get_address() == address) return symbol;
    }
    throw new std::exception();
}

bool SymbolTable::has_symbol_with_address(int address) {
    for (Symbol symbol : this->symbols) {
        if (symbol.get_address() == address) return true;
    }
    return false;
}

bool SymbolTable::is_equivalent(SymbolTable symbol_table) {
    std::vector<std::string> equivalents;
    for (Symbol symbol_1 : get_symbols()) {
        for (Symbol symbol_2 : symbol_table.get_symbols()) {
            if ((symbol_1.get_type() == symbol_2.get_type()) && std::find(equivalents.begin(), equivalents.end(), symbol_2.get_id()) == equivalents.end()) {
                equivalents.push_back(symbol_2.get_id());
            }
        }
    }
    return equivalents.size() == get_symbols().size();
}

std::vector<Symbol> SymbolTable::get_symbols_by_type(int type) {
    std::vector<Symbol> symbols;
    for (Symbol symbol : this->symbols) {
        if (symbol.get_type() == type) symbols.push_back(symbol);
    }
    return symbols;
}

std::vector<Symbol> SymbolTable::get_symbols_by_category(std::string category) {
    std::vector<Symbol> symbols;
    for (Symbol symbol : this->symbols) {
        if (symbol.get_category() == category) symbols.push_back(symbol);
    }
    return symbols;
}

std::vector<Symbol> SymbolTable::get_symbols() {
    return this->symbols;
} 

