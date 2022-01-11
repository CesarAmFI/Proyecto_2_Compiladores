%{
    #include <iostream>
    #include <string>
    using namespace std;
        
    #include "Tokens.hpp"
    #include "Scanner.hpp"

    #undef YY_DECL
    #define YY_DECL int Scanner::yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location)

    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option c++
%option outfile="Scanner.cpp"
%option yyclass="Scanner"
%option case-insensitive
%option noyywrap

INT_RE [0-9]+
DOUBLE_RE [0-9]*\.[0-9]+(e[0-9]+)?(d|D)?
FLOAT_RE [0-9]*\.[0-9]+(e[0-9]+)?(f|F)
ID_RE [A-Za-z][A-Za-z0-9_]*
STRING_RE \"(\\.|[^"\\])*\"
SPACE_RE [ \t\n\r]

%%
";"         {return yy::Parser::token::SEMICOLON;}
"{"         {return yy::Parser::token::LEFT_BRACKET;}
"}"         {return yy::Parser::token::RIGHT_BRACKET;}
"("         {return yy::Parser::token::LEFT_PARENTHESIS;}
")"         {return yy::Parser::token::RIGHT_PARENTHESIS;}
","         {return yy::Parser::token::COMMA;}
"="         {return yy::Parser::token::ASSIGN;}
"."         {return yy::Parser::token::DOT;}
"+"         {return yy::Parser::token::ADD;}
"-"         {return yy::Parser::token::SUBSTRACT;}
"*"         {return yy::Parser::token::MULTIPLY;}
"/"         {return yy::Parser::token::DIVIDE;}
"||"        {return yy::Parser::token::DISJOIN;}
"&&"        {return yy::Parser::token::CONJOIN;}
"<"         {return yy::Parser::token::LESS;}
">"         {return yy::Parser::token::GREATER;}
"!="        {return yy::Parser::token::DIFFERENT;}
"=="        {return yy::Parser::token::EQUAL;}
"<="        {return yy::Parser::token::LESS_EQUAL;}
">="        {return yy::Parser::token::GREATER_EQUAL;}
"!"         {return yy::Parser::token::NEGATE;}
"if"        {return yy::Parser::token::IF;}
"else"      {return yy::Parser::token::ELSE;}
"while"     {return yy::Parser::token::WHILE;}
"do"        {return yy::Parser::token::DO;}
"char"      {return yy::Parser::token::CHAR;}
"int"       {return yy::Parser::token::INT;}
"float"     {return yy::Parser::token::FLOAT;}
"double"    {return yy::Parser::token::DOUBLE;}
"struct"    {return yy::Parser::token::STRUCT;}
"void"      {return yy::Parser::token::VOID;}
"print"     {return yy::Parser::token::PRINT;}
"scan"      {return yy::Parser::token::SCAN;}
"break"     {return yy::Parser::token::BREAK;}
"return"    {return yy::Parser::token::RETURN;}

{INT_RE} {lval->emplace<std::string>(YYText()); return yy::Parser::token::NUMBER_INTEGER;}
{FLOAT_RE} {lval->emplace<std::string>(YYText()); return yy::Parser::token::NUMBER_FLOAT;}
{DOUBLE_RE} {lval->emplace<std::string>(YYText()); return yy::Parser::token::NUMBER_DOUBLE;}
{ID_RE} {lval->emplace<std::string>(YYText()); return yy::Parser::token::ID;}
{STRING_RE} {lval->emplace<std::string>(YYText()); return yy::Parser::token::STRING;}
{SPACE_RE} {}

.       {cout<<"ERROR LEXICO"<<yytext<<endl;}

%%