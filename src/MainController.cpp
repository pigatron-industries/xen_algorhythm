#include "MainController.h"
#include "Hardware.h"

MainController MainController::instance;

MainController::MainController() : AbstractMainController(Hardware::hw.encoder, Hardware::hw.encoderButton) {
}

void MainController::init() {
    AbstractMainController::init();
    Hardware::hw.init();
}

void MainController::controllerInit() {
    AbstractMainController::controllerInit();
}

void MainController::update() {
    Hardware::hw.resetInput.update();
    Hardware::hw.clockInput.update();

    if(Hardware::hw.resetInput.rose()) {
        controllers.getActiveController()->reset();
        Hardware::hw.updateOutputs();
    }

    if(Hardware::hw.clockInput.rose()) {
        controllers.getActiveController()->clock();
        Hardware::hw.updateOutputs();
    } else if (Hardware::hw.clockInput.fell()) {
        controllers.getActiveController()->clear();
        Hardware::hw.updateOutputs();
    }

    AbstractMainController::update();
}
