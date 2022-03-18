#include "EuclideanLogicController.h"

void EuclideanLogicController::init() { 
    Serial.println("Euclidean Logic");
    Serial.print("Mode: ");
    Serial.println(mode.value);
    switch(mode.value) {
        case Mode::ASYNCHRONOUS:
        case Mode::DUAL_SEQUENTIAL:
            euclideanChannels = asyncEuclideanChannels;
            setFrameMode(EuclideanRhythmGenerator::FrameMode::FRAME_NONE);
            break;
        case Mode::SYNCHRONOUS:
            euclideanChannels = asyncEuclideanChannels;
            setFrameMode(EuclideanRhythmGenerator::FrameMode::FRAME_SINGLE);
            break;
        case Mode::SYNCHRONOUS_LIMITED:
            euclideanChannels = syncEuclideanChannels;
            setFrameMode(EuclideanRhythmGenerator::FrameMode::FRAME_NONE);
            break;
    }
    reset();
    debug();
}

void EuclideanLogicController::update() {
    Controller::update();

    bool changed = false;
    for(int channel = 0; channel < CHANNELS; channel++) {
        changed |= euclideanChannels[channel].update();
        if(mode.value == Mode::SYNCHRONOUS || mode.value == Mode::SYNCHRONOUS_LIMITED) {
            euclideanChannels[channel].setFrameLength(euclideanChannels[0].getLength());
        }
    }

    if(mode.value == Mode::DUAL_SEQUENTIAL) {
        sequentialGenerator[0].update();
        sequentialGenerator[1].update();
    }

    if(changed) {
        Serial.println("===========");
        for(int channel = 0; channel < CHANNELS; channel++) {
            Serial.print("Channel ");
            Serial.println(channel);
            euclideanChannels[channel].debug();
        }
    }
}

void EuclideanLogicController::setFrameMode(EuclideanRhythmGenerator::FrameMode frameMode) {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].setFrameMode(frameMode);
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
            Hardware::hw.gateOutputs[0]->digitalWrite(euclideanChannels[0].getOutput());
            Hardware::hw.gateOutputs[1]->digitalWrite(euclideanChannels[1].getOutput());
            Hardware::hw.gateOutputs[2]->digitalWrite(euclideanChannels[2].getOutput());
            Hardware::hw.gateOutputs[3]->digitalWrite(euclideanChannels[3].getOutput());
            Hardware::hw.gateOutputs[4]->digitalWrite(logicGates[0].getOutput());
            Hardware::hw.gateOutputs[5]->digitalWrite(logicGates[1].getOutput());
            Hardware::hw.gateOutputs[6]->digitalWrite(logicGates[2].getOutput());
            Hardware::hw.gateOutputs[7]->digitalWrite(logicGates[3].getOutput());
            break;
        case Mode::DUAL_SEQUENTIAL:
            sequentialGenerator[0].clock();
            sequentialGenerator[1].clock();
            Hardware::hw.gateOutputs[0]->digitalWrite(sequentialGenerator[0].getOutput());
            Hardware::hw.gateOutputs[2]->digitalWrite(sequentialGenerator[1].getOutput());
            break;
    }

    debugClock();
}

void EuclideanLogicController::reset() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanChannels[channel].reset();
    }
    clear();
}

void EuclideanLogicController::clear() {
    for(int i = 0; i < 8; i++) {
        Hardware::hw.gateOutputs[i]->digitalWrite(0);
    }
}

void EuclideanLogicController::debug() {
    Serial.println("===========");
    for(int channel = 0; channel < CHANNELS; channel++) {
        Serial.print("Channel ");
        Serial.println(channel);
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