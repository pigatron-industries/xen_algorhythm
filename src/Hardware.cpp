#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        gateOutputs[i]->digitalWrite(false);
    }

    #if defined(ALGORHYTHM_MKII)
        mcp23s17Device.init();
        mcp23s17Device.send();
    #endif
}

void Hardware::updateOutputs() {
    #if defined(ALGORHYTHM_MKII)
        mcp23s17Device.send();
    #endif
    #if defined(ALGORHYTHM_MKI)
        Hardware::hw.hc595Device.send();
    #endif
}