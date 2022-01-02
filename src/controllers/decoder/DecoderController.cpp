#include "DecoderController.h"
#include "Hardware.h"

void DecoderController::init() { 
    Serial.println("Decoder");
}

void DecoderController::update() {
    if(mode.value == SYNCHRONOUS) {
        Controller::update();
    } else {
        decode();
        Hardware::hw.updateOutputs();
    }
}

void DecoderController::clock() {
    decode();
}

void DecoderController::reset() {
}

void DecoderController::clear() {
    for(int i = 0; i < GATE_OUTPUTS; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(0);
    }
}

void DecoderController::decode() {
    uint8_t decoded = 0;
    if(Hardware::hw.resetInputPin.digitalRead()) {
        decoded |= 0x01;
    }
    if(Hardware::hw.rotateInputPin.digitalRead()) {
        decoded |= 0x01 << 1;
    }
    if(Hardware::hw.changeInputPin.digitalRead()) {
        decoded |= 0x01 << 2;
    }

    for(int i = 0; i < GATE_OUTPUTS; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(i == decoded);
    }
}