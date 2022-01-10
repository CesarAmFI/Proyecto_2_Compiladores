#include "Quad.hpp"
        
Quad::Quad(Expression result, Expression operator_1, std::string operation, Expression operator_2) {
    this->result = result;
    this->operator_1 = operator_1;
    this->operation = operation;
    this->operator_2 = operator_2;
}

Quad::Quad(Expression result, Expression operator_1, std::string operation) {
    this->result = result;
    this->operator_1 = operator_1;
    this->operation = operation;
    this->operator_2 = Expression();
}

Quad::Quad(Expression operator_1, std::string operation, Expression operator_2) {
    this->result = Expression();
    this->operator_1 = operator_1;
    this->operation = operation;
    this->operator_2 = operator_2;
}

Quad::Quad(Expression operator_1, std::string operation) {
    this->result = Expression();
    this->operator_1 = operator_1;
    this->operation = operation;
    this->operator_2 = Expression();
}

Quad::Quad(std::string operation) {
    this->result = Expression();
    this->operator_1 = Expression();
    this->operation = operation;
    this->operator_2 = Expression();
}

Quad::Quad() {

}

Quad::~Quad() {

}

Expression Quad::get_result() {
    return this->result;    
}

Expression Quad::get_operator_1() {
    return this->operator_1;
}

std::string Quad::get_operation() {
    return this->operation;
}

Expression Quad::get_operator_2() {
    return this->operator_2;
}