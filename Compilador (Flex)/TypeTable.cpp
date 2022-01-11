#include "TypeTable.hpp"

TypeTable::TypeTable() {
    std::vector<Type> types;
}

TypeTable::~TypeTable() {

}

void TypeTable::add_type(Type type) {
    types.push_back(type);
}

Type TypeTable::get_type_by_id(int id) {
    for (Type type : this->types) {
        if (type.get_id() == id) return type;
    }
    throw new std::exception();
}

bool TypeTable::has_type_with_id(int id) {
    for (Type type : this->types) {
        if (type.get_id() == id) return true;
    }
    return false;
}

Type TypeTable::get_type_by_name(std::string name) {
    for (Type type : this->types) {
        if (type.get_name() == name) return type;
    }
    throw new std::exception();
}

bool TypeTable::has_type_with_name(std::string name) {
    for (Type type : this->types) {
        if (type.get_name() == name) return true;
    }
    return false;
}

int TypeTable::get_table_size(SymbolTable table) {
    int top = 0;
    for (Symbol symbol : table.get_symbols()) {
        int address =  symbol.get_address() + this->get_type_by_id(symbol.get_type()).get_size();
        top = address > top ? address : top;
    }
    return top;
}

int TypeTable::get_size() {
    return this->types.size();
}