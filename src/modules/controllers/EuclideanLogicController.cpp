#include "EuclideanLogicController.h"

void EuclideanLogicController::init() { 
}

void EuclideanLogicController::execute() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].update();

        if(mode == EuclideanRhythmGenerator::Mode::FRAME_SINGLE) {
            euclideanChannels[channel].setFrameLength(euclideanChannels[0].getLength());
        }
    }
}

void EuclideanLogicController::setMode(EuclideanRhythmGenerator::Mode mode) {
    this->mode = mode;
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].setMode(mode);
    }
}

void EuclideanLogicController::clock() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].clock();
    }

    for(int channel = 0; channel < CHANNELS; channel++) {
        gateOutputs.setValue(channel, euclideanChannels[channel].getOutput());
        gateOutputs.setValue(channel+4, euclideanChannels[channel].getOutput());
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
    Serial.println(mode);
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].debug();
    }
}

void EuclideanLogicController::debugClock() {
    // for(int channel = 0; channel < CHANNELS; channel++) {
    //     Serial.print(euclideanRhythmControllers[channel].getPosition());
    //     Serial.print(":");
    //     Serial.print(euclideanRhythmControllers[channel].getOutput());
    //     Serial.print(" ");
    // }
    // Serial.println();
}