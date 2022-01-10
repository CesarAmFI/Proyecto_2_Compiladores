#include "Expression.hpp"

Expression::Expression(int type, std::string address, std::string alias, bool is_immediate) {
    this->type = type;
    this->address = address;
    this->alias = alias;
    this->is_immediate = is_immediate;
}

Expression::Expression() {

}

Expression::~Expression() {

}

int Expression::get_type() {
    return this->type;
}

std::string Expression::get_address() {
    return this->address;
}

std::string Expression::get_alias() {
    return this->alias;
}

bool Expression::get_is_immediate() {
    return this->is_immediate;
}