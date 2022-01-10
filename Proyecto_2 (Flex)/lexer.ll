%{
#include <iostream>
#include <string>
using namespace std;
    
#include "Tokens.hpp"
#include "Scanner.hpp"
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
";"         {return SEMICOLON;}
"{"         {return LEFT_BRACKET;}
"}"         {return RIGHT_BRACKET;}
"("         {return LEFT_PARENTHESIS;}
")"         {return RIGHT_PARENTHESIS;}
","         {return COMMA;}
"="         {return ASSIGN;}
"."         {return DOT;}
"+"         {return ADD;}
"-"         {return SUBSTRACT;}
"*"         {return MULTIPLY;}
"/"         {return DIVIDE;}
"||"        {return DISJOIN;}
"&&"        {return CONJOIN;}
"<"         {return LESS;}
">"         {return GREATER;}
"!="        {return DIFFERENT;}
"=="        {return EQUAL;}
"<="        {return LESS_EQUAL;}
">="        {return GREATER_EQUAL;}
"!"         {return NEGATE;}
"if"        {return IF;}
"else"      {return ELSE;}
"while"     {return WHILE;}
"do"        {return DO;}
"char"      {return CHAR;}
"int"       {return INT;}
"float"     {return FLOAT;}
"double"    {return DOUBLE;}
"struct"    {return STRUCT;}
"void"      {return VOID;}
"print"     {return PRINT;}
"scan"      {return SCAN;}
"break"     {return BREAK;}
"return"    {return RETURN;}

{INT_RE}   {return NUMBER_INTEGER;}
{FLOAT_RE} {return NUMBER_FLOAT;}
{DOUBLE_RE} {return NUMBER_DOUBLE;}
{ID_RE}    {return ID;}
{STRING_RE}   {return STRING;}
{SPACE_RE}   {}

.       {cout<<"ERROR LEXICO"<<yytext<<endl;}

%%