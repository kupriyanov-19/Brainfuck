#pragma once
#include"BrainfuckTokenizer.h"
#include"ArrayOfValues.h"

class BrainfuckInterpreter
{
public:
    using pointer = std::shared_ptr<Instruction>;

    void executeProgram(const std::string& str) {
        std::vector<pointer> instructions = tokenizer.tokenize(str);
        ArrayOfValues array;
        std::vector<pointer>::iterator ptr = instructions.begin();
        while((*ptr)->executeCommand(array, ptr));
    }

private:
    BrainfuckTokenizer tokenizer;
};