#include "QuadResolver.hpp"

QuadResolver::QuadResolver() {

}

QuadResolver::~QuadResolver() {
    
}

QuadType QuadResolver::resolve_type(Quad quad) {
    std::string operation = quad.get_operation();
    if (operation == "if") return Q_IF;
    if (operation == "goto") return Q_GOTO;
    if (operation == "label") return Q_LABEL;
    if (operation == "=") return Q_ASSIGN;
    if (operation == "scan") return Q_SCAN;
    if (operation == "print") return Q_PRINT;
    if (operation == "call") return Q_CALL;
    if (operation == "call value") return Q_CALL_VALUE;
    if (operation == "param") return Q_PARAM;
    if (operation == "return") return Q_RETURN_VOID;
    if (operation == "return value") return Q_RETURN_VALUE;
    if (operation == "returning") return Q_RETURNING;
    if (operation == "(char)") return Q_CAST_TO_CHAR;
    if (operation == "(int)") return Q_CAST_TO_INTEGER;
    if (operation == "(float)") return Q_CAST_TO_FLOAT;
    if (operation == "(double)") return Q_CAST_TO_DOUBLE;
    if (operation == "||") return Q_DISJOIN;
    if (operation == "&&") return Q_CONJOIN;
    if (operation == "==") return Q_EQUAL;
    if (operation == "!=") return Q_NOT_EQUAL;
    if (operation == "<") return Q_LESS;
    if (operation == ">") return Q_GREATER;
    if (operation == "<=") return Q_LESS_EQUAL;
    if (operation == ">=") return Q_GREATER_EQUAL;
    if (operation == "+") return Q_ADD;
    if (operation == "-") return Q_SUBSTRACT;
    if (operation == "*") return Q_MULTIPLY;
    if (operation == "/") return Q_DIVIDE;
    if (operation == "!") return Q_NEGATE;
    else throw std::exception();
}

std::string QuadResolver::resolve_string(Quad quad) {
    QuadType quad_type = resolve_type(quad);
    switch (quad_type) {
        case Q_RETURN_VOID:
            return "return\n";
        case Q_IF: 
            return quad.get_operation() + " " + quad.get_operator_1().get_alias() + " goto " + quad.get_operator_2().get_alias() + "\n";
        case Q_GOTO:
        case Q_PARAM: 
        case Q_CALL_VALUE:
        case Q_RETURN_VALUE:
        case Q_RETURNING:
        case Q_SCAN:
        case Q_PRINT:
            return quad.get_operation() + " " + quad.get_operator_1().get_alias() + "\n";
        case Q_LABEL: 
            return quad.get_operator_1().get_alias() + ": ";
        case Q_CAST_TO_CHAR:
        case Q_CAST_TO_INTEGER:
        case Q_CAST_TO_FLOAT:
        case Q_CAST_TO_DOUBLE:
        case Q_NEGATE:
            return quad.get_result().get_alias() + " = " + quad.get_operation() + " " + quad.get_operator_1().get_alias() + "\n";
        case Q_ASSIGN: 
            return quad.get_result().get_alias() + " " + quad.get_operation() + " " + quad.get_operator_1().get_alias() + "\n";
        case Q_CALL: 
            return quad.get_result().get_alias() + " = " + quad.get_operation() + " " + quad.get_operator_1().get_alias() + ", " + quad.get_operator_2().get_alias() + "\n";
        case Q_DISJOIN:
        case Q_CONJOIN:
        case Q_EQUAL:
        case Q_NOT_EQUAL:
        case Q_LESS:
        case Q_GREATER:
        case Q_LESS_EQUAL:
        case Q_GREATER_EQUAL:
        case Q_ADD:
        case Q_SUBSTRACT:
        case Q_MULTIPLY:
        case Q_DIVIDE:
            return quad.get_result().get_alias() + " = " + quad.get_operator_1().get_alias() + " " + quad.get_operation() + " " + quad.get_operator_2().get_alias() + "\n";
        default:
            return "";
    }
}