#ifndef Controller_h
#define Controller_h

#include <eurorack.h>
#include "hwconfig.h"

#define CHANNELS 4
#define OUTPUTS 8

class Controller {
    public:
        virtual void init() = 0;
        virtual void execute() = 0;
        virtual void clock() = 0;
        virtual void clear() = 0;
        virtual void reset() = 0;

    protected:
        MultiplexGateOutput gateOutputs = MultiplexGateOutput(OUT_DATA_PIN, OUT_LATCH_PIN, OUT_CLOCK_PIN, OUTPUTS);
};

#endif