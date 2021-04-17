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

        LogicGate(GateType type, Rhythm& rhythm1, Rhythm& rhythm2);
        bool getOutput();

    private:
        GateType type;
        Rhythm& rhythm1;
        Rhythm& rhythm2;

};

#endif