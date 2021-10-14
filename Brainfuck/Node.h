#pragma once
#include<variant>
#include"Instructions.h"
#include<vector>

class Node {
public:
    Node() : statement(std::vector<Node>({})) {}

    Node(std::variant<Instructions, std::vector<Node>> statement) : statement(statement) {}

    bool isInstruction() const {
        return std::holds_alternative<Instructions>(statement);
    }

    Instructions getInstruction() const {
        if (!this->isInstruction()) throw std::exception("Trying to interpret the cycle as a command");
        return std::get<Instructions>(statement);
    }

    std::vector<Node> const* getChild() const {
        if (this->isInstruction()) throw std::exception("Trying to interpret the commmand as a cycle");
        return &std::get<std::vector<Node>>(statement);
    }

private:
    std::variant<Instructions, std::vector<Node>> statement;
};