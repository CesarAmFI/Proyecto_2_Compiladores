#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>

class Constant {

    private:
        int type;
        std::string id;
        std::string value;

    public:
        Constant();
        Constant(int type, std::string id, std::string value);
        ~Constant();

        int get_type();
        std::string get_id();
        std::string get_value();
};


#endif