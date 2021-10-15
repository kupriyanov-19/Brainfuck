#pragma once
#include<vector>
#include"Tokens.h"

class BrainfuckTokenizer {
public:
    std::vector<Tokens> tokenize(const std::string& str) const;
private:
    Tokens getInstruction(char symbol) const;
};