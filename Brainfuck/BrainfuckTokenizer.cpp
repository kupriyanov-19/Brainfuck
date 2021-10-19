#include<exception>
#include<string>
#include"BrainfuckTokenizer.h"

using pointer = std::shared_ptr<Instruction>;

std::vector<pointer> BrainfuckTokenizer::tokenize(const std::string& str) const {
    std::vector<pointer> instructions;
    instructions.emplace_back(new StartOfProgram());
    for (char symbol : str) {
        switch (symbol) {
        case '>':
            instructions.emplace_back(new IncrementPointer());
            break;
        case '<':
            instructions.emplace_back(new DecrementPointer());
            break;
        case '+':
            instructions.emplace_back(new PlusValue());
            break;
        case '-':
            instructions.emplace_back(new MinusValue());
            break;
        case '.':
            instructions.emplace_back(new Print());
            break;
        case '[':
            instructions.emplace_back(new StartCycle());
            break;
        case ']':
            instructions.emplace_back(new EndCycle());
            break;
        default:
            throw std::exception("Found a symbol that has no meaning in Brainfuck");
        }
    }
    instructions.emplace_back(new EndOfProgram());
    return instructions;
}