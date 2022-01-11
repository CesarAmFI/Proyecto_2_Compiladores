#include "Symbol.hpp"

Symbol::Symbol(std::string id, int type, int address, std::string category, std::vector<Expression> arguments) {
    this->id = id;
    this->type = type;
    this->address = address;
    this->category = category;
    this->arguments = arguments;
}

Symbol::~Symbol() {

}

std::string Symbol::get_id() {
    return this->id;
}

int Symbol::get_type() {
    return this->type;
}

int Symbol::get_address() {
    return this->address;
}

std::string Symbol::get_category() {
    return this->category;
}

std::vector<Expression> Symbol::get_arguments() {
    return this->arguments;
}