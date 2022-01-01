#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        gateOutputs[i]->init();
    }

    for(int i = 0; i < GATE_OUTPUTS; i++) {
        gateOutputs[i]->digitalWrite(false);
    }

    mcp23s17Device.gpioPortUpdate(); // TODO move to send() function
}

void Hardware::updateOutputs() {
    #if defined(ALGORHYTHM_MKII)
        mcp23s17Device.gpioPortUpdate(); // TODO move to send() function
    #endif
    #if defined(ALGORHYTHM_MKI)
        Hardware::hw.hc595Device.send();
    #endif
}