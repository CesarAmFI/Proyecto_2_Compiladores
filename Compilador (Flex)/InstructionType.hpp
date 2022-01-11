#ifndef INSTRUCTIONTYPE_H
#define INSTRUCTIONTYPE_H

enum InstructionType {
    I_LOAD,
    I_LOAD_DATA,
    I_LOAD_WRITE,
    I_STORE,
    I_CONVERT_TO_WORD,
    I_CONVERT_TO_SINGLE,
    I_CONVERT_TO_DOUBLE,
    I_READ,
    I_WRITE,
    I_ADD,
    I_SUBSTRACT,
    I_MULTIPLY,
    I_DIVIDE,
    I_COMPARE_EQUAL,
    I_COMPARE_LESS,
    I_COMPARE_LESS_EQUAL,
    I_MOVE_ON_TRUE,
    I_MOVE_ON_FALSE
};

#endif