#pragma once
#include<vector>
#include"Instructions.h"
#include"Node.h"
#include"Tokens.h"

class BrainfuckParser {
public:
    using Iterator = std::vector<Tokens>::iterator;

    std::vector<Node> parse(Iterator first, Iterator last) const {
        Iterator current = first;
        return parse(first, last, first, current);
    }

private:
    std::vector<Node> parse(Iterator first, Iterator last, Iterator cycleBegin, Iterator& current) const;
    Instructions convertToken(Tokens token) const;
};


