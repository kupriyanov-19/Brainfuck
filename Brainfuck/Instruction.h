#pragma once
#include<vector>
#include"ArrayOfValues.h"

class Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) = 0;
};

class IncrementPointer : public Instruction {
public:
    virtual bool executeCommand (ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override {
        array.increment();
        ++ptr;
        return true;
    }
};

class DecrementPointer : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override {
        array.decrement();
        ++ptr;
        return true;
    }
};

class PlusValue : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override {
        array.plus();
        ++ptr;
        return true;
    }
};

class MinusValue : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override {
        array.minus();
        ++ptr;
        return true;
    }
};

class Print : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override {
        array.print();
        ++ptr;
        return true;
    }
};

class StartCycle : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override;
};

class EndCycle : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator &ptr) override;
};

class EndOfProgram : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator& ptr) override {
        return false;
    }
};

class StartOfProgram : public Instruction {
public:
    virtual bool executeCommand(ArrayOfValues& array,
        std::vector<std::shared_ptr<Instruction>>::iterator& ptr) override {
        ++ptr;
        return true;
    }
};
