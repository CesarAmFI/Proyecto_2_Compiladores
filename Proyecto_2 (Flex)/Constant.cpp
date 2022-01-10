#include "Constant.hpp"

Constant::Constant(int type, std::string id, std::string value) {
    this->type = type;
    this->id = id;
    this->value = value;
}

Constant::Constant() {

}

Constant::~Constant() {

}

int Constant::get_type() {
    return this->type;
}

std::string Constant::get_id() {
    return this->id;
}

std::string Constant::get_value() {
    return this->value;
}