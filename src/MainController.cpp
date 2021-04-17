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
        case Mode::ASYNCHRONOUS:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::ASYNCHRONOUS);
            break;
        case Mode::SYNCHRONOUS:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::SYNCHRONOUS);
            break;
        case Mode::DUAL_SEQUENTIAL:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::DUAL_SEQUENTIAL);
            break;
        default:
            break;
    }
}