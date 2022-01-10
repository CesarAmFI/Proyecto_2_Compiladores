#include "Type.hpp"

Type::Type(int id, std::string name, int size, int items, SymbolTable base_type) {
    this->id = id;
    this->name = name;
    this->size = size;
    this->items = items;
    this->base_type = base_type;
}

Type::~Type() {

}

int Type::get_id() {
    return this->id;
}

std::string Type::get_name() {
    return this->name;
}

int Type::get_size() {
    return this->size;
}

int Type::get_items() {
    return this->items;
}

SymbolTable Type::get_base_type() {
    return this->base_type;
}