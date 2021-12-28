#include "EuclideanLogicController.h"

void EuclideanLogicController::init() { 
    reset();
}

void EuclideanLogicController::update() {
    bool changed = false;
    for(int channel = 0; channel < CHANNELS; channel++) {
        changed |= euclideanChannels[channel].update();

        if(mode.value == Mode::SYNCHRONOUS) {
            euclideanChannels[channel].setFrameLength(euclideanChannels[0].getLength());
        }
    }

    if(mode.value == Mode::DUAL_SEQUENTIAL) {
        sequentialGenerator[0].update();
        sequentialGenerator[1].update();
    }
}

void EuclideanLogicController::clock() {
    switch(mode.value) {
        case Mode::ASYNCHRONOUS:
        case Mode::SYNCHRONOUS:
            euclideanChannels[0].clock();
            euclideanChannels[1].clock();
            euclideanChannels[2].clock();
            euclideanChannels[3].clock();
            gateOutputs.setValue(0, euclideanChannels[0].getOutput());
            gateOutputs.setValue(1, euclideanChannels[1].getOutput());
            gateOutputs.setValue(2, euclideanChannels[2].getOutput());
            gateOutputs.setValue(3, euclideanChannels[3].getOutput());
            gateOutputs.setValue(4, logicGates[0].getOutput());
            gateOutputs.setValue(5, logicGates[1].getOutput());
            gateOutputs.setValue(6, logicGates[2].getOutput());
            gateOutputs.setValue(7, logicGates[3].getOutput());
            break;
        case Mode::DUAL_SEQUENTIAL:
            sequentialGenerator[0].clock();
            sequentialGenerator[1].clock();
            gateOutputs.setValue(0, sequentialGenerator[0].getOutput());
            gateOutputs.setValue(2, sequentialGenerator[1].getOutput());
            break;
    }

    gateOutputs.sendData();
    debugClock();
}

void EuclideanLogicController::reset() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].reset();
    }
    clear();
    debugReset();
}

void EuclideanLogicController::clear() {
    for(int channel = 0; channel < CHANNELS+4; channel++) {
        gateOutputs.setValue(channel, false);
    }
    gateOutputs.sendData();
}

void EuclideanLogicController::debugReset() {
    Serial.print("Mode: ");
    Serial.println(mode.value);
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].debug();
    }
}

void EuclideanLogicController::debugClock() {
    // for(int channel = 0; channel < CHANNELS; channel++) {
    //     Serial.print(euclideanChannels[channel].getPosition());
    //     Serial.print(":");
    //     Serial.print(euclideanChannels[channel].getOutput());
    //     Serial.print(" ");
    // }
    // Serial.println();
}