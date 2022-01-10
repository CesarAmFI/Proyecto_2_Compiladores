#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>

class Instruction {

    private:

        std::string mnemonic;
        std::vector<std::string> arguments;

        
    public:
        Instruction(std::string mnemonic, std::vector<std::string> arguments);
        Instruction();
        ~Instruction();

        std::string get_mnemonic();
        std::vector<std::string> get_arguments();

};


#endif