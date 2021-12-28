#ifndef Controller_h
#define Controller_h

#include <eurorack.h>
#include "hwconfig.h"

#define CHANNELS 4
#define OUTPUTS 8

class Controller {
    public:
        Controller(int lastMode = 0) : mode(0, lastMode) {}
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void clock() = 0;
        virtual void clear() = 0;
        virtual void reset() = 0;

        int cycleMode(int amount) { mode.cycle(amount); return mode.value; }
        void setMode(int value) { mode.setValue(value); }

    protected:
        CycleEnum<int> mode;
        MultiplexGateOutput gateOutputs = MultiplexGateOutput(OUT_DATA_PIN, OUT_LATCH_PIN, OUT_CLOCK_PIN, OUTPUTS);
};

#endif