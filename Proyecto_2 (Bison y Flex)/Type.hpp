#ifndef TYPE_H
#define TYPE_H

#include <string>

#include "SymbolTable.hpp"

class Type {

    private:
        int id;
        std::string name;
        int size;
        int items;
        SymbolTable base_type;

    public:
        Type(int id, std::string name, int size, int items, SymbolTable base_type);
        ~Type();

        int get_id();
        std::string get_name();
        int get_size();
        int get_items();
        SymbolTable get_base_type();
        
};

#endif