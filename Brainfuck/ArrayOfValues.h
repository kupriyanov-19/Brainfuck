#pragma once
#include<iostream>
#include<deque>

const int INITIALVALUE = 0;
const int MAXSIZE = 30000;

class ArrayOfValues
{
public:
    ArrayOfValues() {
        array.assign(MAXSIZE, INITIALVALUE);
        pointer = array.begin();
    }
    void increment() {
        if (pointer == prev(array.end()))
            array.push_back(INITIALVALUE);
        ++pointer;
    }
    void decrement() {
        if (pointer == array.begin())
            array.push_front(INITIALVALUE);
        --pointer;
    }
    void plus() {
        ++(*pointer);
    }
    void minus() {
        --(*pointer);
    }
    void print() const {
        std::cout << *pointer << ' ';
    }
    int getValue() const {
        return *pointer;
    }

private:
    std::deque<int> array;
    std::deque<int>::iterator pointer;
};