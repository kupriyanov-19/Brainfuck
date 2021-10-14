#include"BrainfuckVirtualMachine.h"

void BrainfuckVirtualMachine::executeNode(const Node &command) {
    if (command.isInstruction())
        consumeInstruction(command.getInstruction());
    else {
        while (array.getValue() != 0) {
            for(Node directive: *(command.getChild()))
                executeNode(directive);
        }
    }
}

void BrainfuckVirtualMachine::consumeInstruction(Instructions instruction) {
    switch (instruction) {
    case Instructions::INCREMENT:
        array.increment();
        break;
    case Instructions::DECREMENT:
        array.decrement();
        break;
    case Instructions::PLUS:
        array.plus();
        break;
    case Instructions::MINUS:
        array.minus();
        break;
    case Instructions::PRINT:
        array.print();
        break;
    }
}