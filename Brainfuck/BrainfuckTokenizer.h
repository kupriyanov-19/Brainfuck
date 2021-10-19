#pragma once
#include<vector>
#include<memory>
#include"Instruction.h"

class BrainfuckTokenizer {
public:
    std::vector<std::shared_ptr<Instruction>> tokenize(const std::string& str) const;
};