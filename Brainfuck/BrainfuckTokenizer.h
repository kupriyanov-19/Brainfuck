#pragma once
#include"Tokens.h"
#include<vector>

class BrainfuckTokenizer {
public:
    std::vector<Tokens> tokenize(const std::string& str) const;
private:
    Tokens getInstruction(char symbol) const;
};