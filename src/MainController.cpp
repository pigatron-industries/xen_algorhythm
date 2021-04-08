#include "MainController.h"

MainController::MainController() {
}

void MainController::init() {
    Eurorack::init();
}

void MainController::execute() {
    euclideanLogicController.execute();

    if(encoder.update()) {
        mode.cycle(encoder.getMovement());
        modeUpdate();
    }

    if(resetInput.update() || encoderButton.update()) {
        if(resetInput.rose() || encoderButton.pressed()) {
            euclideanLogicController.reset();
        }
    }

    if(clockInput.update()) {
        if(clockInput.rose()) {
            euclideanLogicController.clock();
        } else if (clockInput.fell()) {
            euclideanLogicController.clear();
        }
    }

    euclideanLogicController.execute();
}

void MainController::modeUpdate() {
    switch(mode.value) {
        case Mode::ASYNC_REPEAT:
            euclideanLogicController.setMode(EuclideanRhythmGenerator::Mode::FRAME_NONE);
            break;
        case Mode::SYNC_SINGLE:
            euclideanLogicController.setMode(EuclideanRhythmGenerator::Mode::FRAME_SINGLE);
            break;
    }
}