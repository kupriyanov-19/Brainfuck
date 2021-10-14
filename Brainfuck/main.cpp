#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include"BrainfuckInterpreter.h"

std::string read(std::ifstream& input) {
    char symbol;
    std::string result;
    while (input >> symbol) {
        switch (symbol) {
        case ' ':
        case '\n':
            break;
        case '<':
        case '>':
        case '+':
        case '-':
        case '[':
        case ']':
        case '.':
            result += symbol;
            break;
        default:
            throw std::invalid_argument("Found a symbol that has no meaning in BrainFuck");
        }
    }
    return result;
}

int main() {
    std::ifstream input("input.txt");
    try {
        const std::string programCode = read(input);
        BrainfuckInterpreter interpreter;
        interpreter.executeProgram(programCode);
    }
    catch (std::exception & exception) {
        std::cerr << exception.what();
    }
}