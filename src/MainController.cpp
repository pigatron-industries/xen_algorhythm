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

    bool update = false;

    if(clockInput.update()) {
        if(clockInput.rose()) {
            update = true;
            for(int channel = 0; channel < CHANNELS; channel++) {
                euclideanRhythmControllers[channel].clock();
            }
        } else if (clockInput.fell()) {
            // turn off all outputs
            for(int channel = 0; channel < CHANNELS+4; channel++) {
                gateOutputs.setValue(channel, false);
            }
            gateOutputs.sendData();
        }
    }

    if(resetInput.update()) {
        if(resetInput.rose()) {
            update = true;
            for(int channel = 0; channel < CHANNELS; channel++) {
                euclideanRhythmControllers[channel].reset();
            }
        }
    }

    if(update) {
        for(int channel = 0; channel < CHANNELS; channel++) {
            gateOutputs.setValue(channel, euclideanRhythmControllers[channel].getOutput());
            gateOutputs.setValue(channel+4, euclideanRhythmControllers[channel].getOutput());
        }
        gateOutputs.sendData();
    }
}