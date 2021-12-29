#include "ClockDividerController.h"
#include "Hardware.h"

void ClockDividerController::init() { 
    Serial.println("Clock Divider");
    counter = 0;
    clockDividers[0].setDivisor(1);
    clockDividers[1].setDivisor(6);
    clockDividers[2].setDivisor(8);
    clockDividers[3].setDivisor(12);
    clockDividers[4].setDivisor(24);
    clockDividers[5].setDivisor(32);
    clockDividers[6].setDivisor(48);
    clockDividers[7].setDivisor(96);
}

void ClockDividerController::update() {
}

void ClockDividerController::clock() {
    counter++;
    if(counter == 24*12) {
        counter = 0;
    }

    for(int i = 0; i < 8; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(clockDividers[i].tick());
    }

    Hardware::hw.hc595Device.send();
}

void ClockDividerController::reset() {
    counter = 0;
}

void ClockDividerController::clear() {
    for(int i = 0; i < 8; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(0);
    }
    Hardware::hw.hc595Device.send();
}
