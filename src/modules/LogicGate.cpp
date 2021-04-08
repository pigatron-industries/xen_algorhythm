#include "LogicGate.h"


LogicGate::LogicGate(GateType type, Rhythm* input1, Rhythm* input2) {
    this->type = type;
    this->input1 = input1;
    this->input2 = input2;
}

bool LogicGate::getOutput() {
    switch(type) {
        case AND:
            return input1->getOutput() && input2->getOutput();
        case AND_NOT:
            return input1->getOutput() && !input2->getOutput();
    }
}