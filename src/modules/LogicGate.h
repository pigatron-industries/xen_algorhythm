#ifndef LogicGate_h
#define LogicGate_h

#include <inttypes.h>
#include "Rhythm.h"

class LogicGate {
    public:
        enum GateType {
            AND,
            AND_NOT
        };

        LogicGate(GateType type, Rhythm* input1, Rhythm* input2);
        bool getOutput();

    private:
        GateType type;
        Rhythm* input1;
        Rhythm* input2;

};

#endif