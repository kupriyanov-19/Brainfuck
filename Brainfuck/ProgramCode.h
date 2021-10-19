#pragma once
#include<vector>
#include"Instruction.h"

class ProgramCode {
public:
    ProgramCode(std::vector<Instruction*> instructions) :
        instructions(instructions) {
        pointer = instructions.begin();
    }
    void increment() {
        ++pointer;
    }
    void decrement() {
        --pointer;
    }
    ~ProgramCode() {
        for (Instruction* instruction : instructions) delete instruction;
    }

private:
    std::vector<Instruction*> instructions;
    std::vector<Instruction*>::iterator pointer;
};
