#ifndef QUADTYPE_H
#define QUADTYPE_H

enum QuadType {
    Q_IF,
    Q_GOTO,
    Q_LABEL,
    Q_ASSIGN,
    Q_SCAN,
    Q_PRINT,
    Q_CALL,
    Q_CALL_VALUE,
    Q_PARAM,
    Q_RETURN_VALUE,
    Q_RETURN_VOID,
    Q_RETURNING,
    Q_CAST_TO_INTEGER,
    Q_CAST_TO_FLOAT,
    Q_CAST_TO_DOUBLE,
    Q_CAST_TO_CHAR,
    Q_DISJOIN,
    Q_CONJOIN,
    Q_EQUAL,
    Q_NOT_EQUAL,
    Q_LESS,
    Q_GREATER,
    Q_LESS_EQUAL,
    Q_GREATER_EQUAL,
    Q_ADD,
    Q_SUBSTRACT,
    Q_MULTIPLY,
    Q_DIVIDE,
    Q_NEGATE
};

#endif