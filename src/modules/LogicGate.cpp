#include "LogicGate.h"


LogicGate::LogicGate(GateType type, Rhythm& rhythm1, Rhythm& rhythm2) :
    rhythm1(rhythm1),
    rhythm2(rhythm2) {
    this->type = type;
}

bool LogicGate::getOutput() {
    switch(type) {
        case AND:
            return rhythm1.getOutput() && rhythm2.getOutput();
        case AND_NOT:
            return rhythm1.getOutput() && !rhythm2.getOutput();
    }
    return false;
}