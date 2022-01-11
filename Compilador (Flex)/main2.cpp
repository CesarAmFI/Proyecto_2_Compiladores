#include <iostream>
#include <fstream>

#include "Scanner.hpp"
#include "Parser.hpp"
#include "Driver.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    filebuf fb;
    fb.open(string(argv[1]), ios::in);
    istream in(&fb);
    Scanner lexer(&in);  
    Parser parser(&lexer);
    parser.parse();    
    fb.close();

}