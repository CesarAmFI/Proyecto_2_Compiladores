#include "Instruction.hpp"

Instruction::Instruction(std::string mnemonic, std::vector<std::string> arguments) {
    this->mnemonic = mnemonic;
    this->arguments = arguments;
}

Instruction::Instruction() {

}

Instruction::~Instruction() {

}

std::string Instruction::get_mnemonic() {
    return this->mnemonic;
}

std::vector<std::string> Instruction::get_arguments() {
    return this->arguments;
}