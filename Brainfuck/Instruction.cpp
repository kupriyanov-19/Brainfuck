#include"Instruction.h"

using pointer = std::shared_ptr<Instruction>;

bool StartCycle::executeCommand(ArrayOfValues& array,
    std::vector<pointer>::iterator &ptr) {
    if (!array.getValue()) {
        int counter = 0;
        while (true) {
            ++ptr;
            if (std::dynamic_pointer_cast<EndOfProgram>(*ptr))
                throw std::exception("Incorrect program. There are more opening brackets than closing.");
            if (std::dynamic_pointer_cast<StartCycle>(*ptr)) ++counter;
            if (std::dynamic_pointer_cast<EndCycle>(*ptr)) {
                if (counter == 0) break;
                --counter;
            }
        }
    }
    ++ptr;
    return true;
}

bool EndCycle::executeCommand(ArrayOfValues& array,
    std::vector<pointer>::iterator &ptr) {
    if (array.getValue()) {
        int counter = 0;
        while (true) {
            --ptr;
            if (std::dynamic_pointer_cast<StartOfProgram>(*ptr))
                throw std::exception("Incorrect program. There are more closing brackets than opening.");
            if (std::dynamic_pointer_cast<EndCycle>(*ptr)) ++counter;
            if (std::dynamic_pointer_cast<StartCycle>(*ptr)) {
                if (counter == 0) break;
                --counter;
            }
        }
    }
    ++ptr;
    return true;
}
