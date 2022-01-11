#ifndef TYPETABLE_H
#define TYPETABLE_H

#include <vector>

#include "Type.hpp"
#include "SymbolTable.hpp"

class TypeTable {

    private:
        std::vector<Type> types;

    public:
        TypeTable();
        ~TypeTable();

        void add_type(Type type);
        Type get_type_by_id(int id);
        bool has_type_with_id(int id);
        Type get_type_by_name(std::string name);
        bool has_type_with_name(std::string name);
        int get_table_size(SymbolTable table);
        int get_size();

};

#endif