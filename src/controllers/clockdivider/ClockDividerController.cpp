#include "ClockDividerController.h"

void ClockDividerController::init() { 
    counter = 0;
}

void ClockDividerController::update() {
}

void ClockDividerController::clock() {
    counter++;
    if(counter == 24*12) {
        counter = 0;
    }

    // if(_mode == CLOCK_MODE_PPQN24) {
    gateOutputs.setValue(0, counter % 1 == 0);
    gateOutputs.setValue(1, counter % 6 == 0);
    gateOutputs.setValue(2, counter % 8 == 0);
    gateOutputs.setValue(3, counter % 12 == 0);
    gateOutputs.setValue(4, counter % 24 == 0);
    gateOutputs.setValue(5, counter % 32 == 0);
    gateOutputs.setValue(6, counter % 48 == 0);
    gateOutputs.setValue(7, counter % 96 == 0);

    gateOutputs.sendData();
}

void ClockDividerController::reset() {
    counter = 0;
}

void ClockDividerController::clear() {
    for(int channel = 0; channel < CHANNELS+4; channel++) {
        gateOutputs.setValue(channel, false);
    }
    gateOutputs.sendData();
}
