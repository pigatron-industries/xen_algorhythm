#include "MainController.h"

MainController::MainController() {
    activeController = &euclideanLogicController;
}

void MainController::init() {
    Eurorack::init();
}

void MainController::execute() {
    activeController->execute();

    encoderButton.update();
    if(encoder.update()) {
        if(encoderButton.held()) {
            //TODO change controller when button held down
            mode.cycle(encoder.getMovement());
            modeUpdate();
        } else {
            mode.cycle(encoder.getMovement());
            modeUpdate();
        }
    }

    if(resetInput.didRise()) {
        activeController->reset();
    }

    if(clockInput.didRise()) {
        activeController->clock();
    } else if (clockInput.didFall()) {
        activeController->clear();
    }

    activeController->execute();
}

void MainController::modeUpdate() {
    switch(mode.value) {
        case Mode::EUCLID_ASYNCHRONOUS:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::ASYNCHRONOUS);
            activeController = &euclideanLogicController;
            break;
        case Mode::EUCLID_SYNCHRONOUS:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::SYNCHRONOUS);
            activeController = &euclideanLogicController;
            break;
        case Mode::EUCLID_DUAL_SEQUENTIAL:
            euclideanLogicController.setMode(EuclideanLogicController::Mode::DUAL_SEQUENTIAL);
            activeController = &euclideanLogicController;
            break;
        case Mode::CLOCK_DIVIDER:
            activeController = &clockDividerController;
            break;
        default:
            break;
    }
}