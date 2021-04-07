#include "MainController.h"

MainController::MainController() {
}

void MainController::init() {
    Eurorack::init();
}

void MainController::execute() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanRhythmControllers[channel].update();
    }

    if(encoder.update()) {
        mode.cycle(encoder.getMovement());
        modeUpdate();
    }

    if(clockInput.update()) {
        if(clockInput.rose()) {
            clock();
            debugClock();
        } else if (clockInput.fell()) {
            clear();
        }
    }

    if(resetInput.update() || encoderButton.update()) {
        if(resetInput.rose() || encoderButton.pressed()) {
            reset();
            debugReset();
        }
    }
}

void MainController::clock() {
    uint8_t finished = 0;
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanRhythmControllers[channel].clock();
    }

    for(int channel = 0; channel < CHANNELS; channel++) {
        gateOutputs.setValue(channel, euclideanRhythmControllers[channel].getOutput());
        gateOutputs.setValue(channel+4, euclideanRhythmControllers[channel].getOutput());
    }
    gateOutputs.sendData();
}

void MainController::reset() {
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanRhythmControllers[channel].reset();
    }
    clear();
}

void MainController::clear() {
    for(int channel = 0; channel < CHANNELS+4; channel++) {
        gateOutputs.setValue(channel, false);
    }
    gateOutputs.sendData();
}

void MainController::modeUpdate() {
    switch(mode.value) {
        case Mode::ASYNC_REPEAT:
            break;
        case Mode::SYNC_REPEAT:
            break;
        case Mode::SYNC_SINGLE:
            break;
    }
}

void MainController::debugReset() {
    Serial.print("Mode: ");
    Serial.println(mode.value);
    for(int channel = 0; channel < CHANNELS; channel++) {
        euclideanRhythmControllers[channel].debug();
    }
}

void MainController::debugClock() {
    // for(int channel = 0; channel < CHANNELS; channel++) {
    //     Serial.print(euclideanRhythmControllers[channel].getPosition());
    //     Serial.print(":");
    //     Serial.print(euclideanRhythmControllers[channel].getOutput());
    //     Serial.print(" ");
    // }
    // Serial.println();
}