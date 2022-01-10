#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

// EXPRESSIONS
// 5: repr: 5, alias: 5, inmediate: true
// a.b: repr: a[0], alias: a_b, inmediate: false
// float1: repr: float1, alias: float1, inmediate: false
// string1: repr: string1, alias: string1, inmediate: false
// a (local): repr: a, alias: a, inmediate: false
// a (global): repr: a, alias: a, inmediate: false

class Expression {

    private:
        int type;
        std::string address;
        std::string alias;
        bool is_immediate;

    public:
        Expression(int type, std::string address, std::string alias, bool is_immediate);
        Expression();
        ~Expression();

        int get_type();
        std::string get_address();
        std::string get_alias();
        bool get_is_immediate();
};


#endif