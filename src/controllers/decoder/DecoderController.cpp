#include "DecoderController.h"
#include "Hardware.h"

#if defined(ALGORHYTHM_MKII)

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

    #if GATE_OUTPUTS == 12
        Hardware::hw.gateOutputs[8]->digitalWrite(Hardware::hw.gateOutputs[0]->getDigitalValue() || Hardware::hw.gateOutputs[4]->getDigitalValue());
        Hardware::hw.gateOutputs[9]->digitalWrite(Hardware::hw.gateOutputs[1]->getDigitalValue() || Hardware::hw.gateOutputs[5]->getDigitalValue());
        Hardware::hw.gateOutputs[10]->digitalWrite(Hardware::hw.gateOutputs[2]->getDigitalValue() || Hardware::hw.gateOutputs[6]->getDigitalValue());
        Hardware::hw.gateOutputs[11]->digitalWrite(Hardware::hw.gateOutputs[3]->getDigitalValue() || Hardware::hw.gateOutputs[7]->getDigitalValue());
    #endif
}

#endif