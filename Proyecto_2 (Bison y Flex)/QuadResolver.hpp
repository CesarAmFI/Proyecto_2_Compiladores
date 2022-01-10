#ifndef QUADRESOLVER_H
#define QUADRESOLVER_H

#include <string>

#include "Quad.hpp"
#include "QuadType.hpp"

class QuadResolver {

    public:
        QuadResolver();
        ~QuadResolver();

        QuadType resolve_type(Quad quad);
        std::string resolve_string(Quad quad);

};


#endif