#ifndef SCANNER_H
#define SCANNER_H 1

#include "Parser.tab.hh"
#include "location.hh"

#if !defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

class Scanner : public yyFlexLexer {

    public:
        Scanner();
        Scanner(std::istream *in) : yyFlexLexer(in) {
            loc = new yy::Parser::location_type();
        };

        using FlexLexer::yylex;
        // virtual int yylex();
        virtual int yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location);

    private:
        yy::Parser::semantic_type *yylval = nullptr;
        yy::Parser::location_type *loc = nullptr;
        const int ERROR = -1;

};

#endif /* END __SCANNER_H__ */

