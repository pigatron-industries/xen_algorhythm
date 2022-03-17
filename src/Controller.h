#ifndef Controller_h
#define Controller_h

#include <eurorack.h>
#include "Hardware.h"

#define CHANNELS 4
#define OUTPUTS 8

class Controller {
    public:
        Controller(int lastMode = 0) : mode(0, lastMode) {}
        virtual void init() = 0;
        virtual void update();
        virtual void clock() = 0;
        virtual void clear() = 0;
        virtual void reset() = 0;

        int cycleMode(int amount) { mode.cycle(amount); return mode.value; }
        void setMode(int value) { mode.setValue(value); }

    protected:
        CycleEnum<int> mode;
};

inline void Controller::update() {
    #if defined(ALGORHYTHM_MKII)
        Hardware::hw.mcp23s17Device.receive();
    #endif

    Hardware::hw.resetInput.update();
    Hardware::hw.clockInput.update();

    #if defined(ALGORHYTHM_MKII)
        Hardware::hw.rotateInput.update();
        Hardware::hw.changeInput.update();
    #endif

    if(Hardware::hw.resetInput.rose()) {
        reset();
        Hardware::hw.updateOutputs();
    }

    if(Hardware::hw.clockInput.rose()) {
        clock();
        Hardware::hw.updateOutputs();
    } else if (Hardware::hw.clockInput.fell()) {
        clear();
        Hardware::hw.updateOutputs();
    }
}

#endif