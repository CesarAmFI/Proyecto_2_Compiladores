#ifndef QUAD_H
#define QUAD_H

#include <string>

#include "Expression.hpp"

class Quad {

    private:
        Expression result;
        Expression operator_1;
        std::string operation;
        Expression operator_2;
        
    public:
        Quad(Expression result, Expression operator_1, std::string operation, Expression operator_2);
        Quad(Expression result, Expression operator_1, std::string operation);
        Quad(Expression operator_1, std::string operation, Expression operator_2);
        Quad(Expression operator_1, std::string operation);
        Quad(std::string operation);
        Quad();
        ~Quad();

        Expression get_result();
        Expression get_operator_1();
        std::string get_operation();
        Expression get_operator_2();

};


#endif