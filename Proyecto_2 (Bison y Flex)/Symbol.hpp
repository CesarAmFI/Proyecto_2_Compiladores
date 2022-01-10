#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <vector>

#include "Expression.hpp"

class Symbol {

    private:
        std::string id;
        int type;
        int address;
        std::string category;
        std::vector<Expression> arguments;

    public:
        Symbol(std::string id, int type, int address, std::string category, std::vector<Expression> arguments);
        ~Symbol();

        std::string get_id();
        int get_type();
        int get_address();
        std::string get_category();
        std::vector<Expression> get_arguments();

};


#endif