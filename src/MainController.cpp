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

    if((encoderButton.update() && encoderButton.pressed()) || resetInput.didRise()) {
        euclideanLogicController.reset();
    }

    if(clockInput.didRise()) {
        euclideanLogicController.clock();
    } else if (clockInput.didFall()) {
        euclideanLogicController.clear();
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