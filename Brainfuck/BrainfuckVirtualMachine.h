#pragma once
#include"Instructions.h"
#include"ArrayOfValues.h"
#include"Node.h"

class BrainfuckVirtualMachine {
public:
    void executeNode(const Node &command);
private:
    ArrayOfValues array;
    void consumeInstruction(Instructions instruction);
};

