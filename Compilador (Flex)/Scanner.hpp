#ifndef SCANNER_H
#define SCANNER_H 1

#if !defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

class Scanner : public yyFlexLexer {

    public:
        Scanner();
        Scanner(std::istream *in) : yyFlexLexer(in){};

        using FlexLexer::yylex;
        virtual int yylex();

    private:
        const int ERROR = -1;

};

#endif /* END __SCANNER_H__ */