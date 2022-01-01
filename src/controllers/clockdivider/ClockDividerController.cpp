#include "ClockDividerController.h"
#include "Hardware.h"

void ClockDividerController::init() { 
    Serial.println("Clock Divider");

    int i = 0;
    clockDividers[i++].setDivisor(1);
    if(GATE_OUTPUTS == 12) {
        clockDividers[i++].setDivisor(2);
        clockDividers[i++].setDivisor(3);
        clockDividers[i++].setDivisor(4);
        clockDividers[i++].setDivisor(5);
    }
    clockDividers[i++].setDivisor(6);
    clockDividers[i++].setDivisor(8);
    clockDividers[i++].setDivisor(12);
    clockDividers[i++].setDivisor(24);
    clockDividers[i++].setDivisor(32);
    clockDividers[i++].setDivisor(48);
    clockDividers[i++].setDivisor(96);
}

void ClockDividerController::update() {
}

void ClockDividerController::clock() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(clockDividers[i].tick());
    }
}

void ClockDividerController::reset() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        clockDividers[i].reset();
        Hardware::hw.gateOutputs[i]->digitalWrite(clockDividers[i].tick());
    }
}

void ClockDividerController::clear() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(0);
    }
}
