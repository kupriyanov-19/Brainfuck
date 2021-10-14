#include"BrainfuckParser.h"

std::vector<Node> BrainfuckParser::parse(Iterator first, Iterator last, Iterator cycleBegin, Iterator& current) const {
    std::vector<Node> array;
    for (; current != last; ++current) {
        switch (*current) {
        case Tokens::STARTCYCLE:
            ++current;
            array.emplace_back(parse(first, last, current, current));
            break;
        case Tokens::ENDCYCLE:
            //We found a closing bracket, but the beginning of the current cycle is the beginning of the entire array, 
            //which means that it has no matching opening
            if (cycleBegin == first) throw std::exception("Incorrect program. Not all cycles have a opening bracket");
            return array;
        default:
            array.emplace_back(convertToken(*current));
        }
    }
    //We have reached the end of the array, but the beginning of the current cycle is not the beginning of the array
    if (cycleBegin != first) throw std::exception("Incorrect program. Not all cycles have a closing bracket");
    return array;
}

Instructions BrainfuckParser::convertToken(Tokens token) const {
    switch (token) {
    case Tokens::INCREMENT:
        return Instructions::INCREMENT;
    case Tokens::DECREMENT:
        return Instructions::DECREMENT;
    case Tokens::PLUS:
        return Instructions::PLUS;
    case Tokens::MINUS:
        return Instructions::MINUS;
    case Tokens::PRINT:
        return Instructions::PRINT;
    default:
        throw std::exception("Incorrect tokens");
    }

}