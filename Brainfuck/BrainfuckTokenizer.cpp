#include<exception>
#include<string>
#include"BrainfuckTokenizer.h"

std::vector<Tokens> BrainfuckTokenizer::tokenize(const std::string& str) const {
    std::vector<Tokens> tokens;
    for (char symbol : str) {
        tokens.push_back(getInstruction(symbol));
    }
    return tokens;
}

Tokens BrainfuckTokenizer::getInstruction(char symbol) const {
    switch (symbol) {
    case '>':
        return Tokens::INCREMENT;
    case '<':
        return Tokens::DECREMENT;
    case '+':
        return Tokens::PLUS;
    case '-':
        return Tokens::MINUS;
    case '.':
        return Tokens::PRINT;
    case '[':
        return Tokens::STARTCYCLE;
    case ']':
        return Tokens::ENDCYCLE;
    default:
        throw std::exception("Found a symbol that has no meaning in Brainfuck");
    }
}