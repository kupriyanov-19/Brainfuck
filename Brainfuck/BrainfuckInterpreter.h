#pragma once
#include"BrainfuckTokenizer.h"
#include"BrainfuckParser.h"
#include"BrainfuckVirtualMachine.h"

class BrainfuckInterpreter
{
public:
    void executeProgram(const std::string& str) {
        std::vector<Tokens> tokens = tokenizer.tokenize(str);
        std::vector<Node> commands = parser.parse(tokens.begin(), tokens.end());
        for (Node command : commands) machine.executeNode(command);
    }

private:
    BrainfuckTokenizer tokenizer;
    BrainfuckParser parser;
    BrainfuckVirtualMachine machine;
};