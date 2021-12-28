#include "MainController.h"
#include "Hardware.h"
#include "Config.h"

MainController MainController::instance;

MainController::MainController() : AbstractMainController(Hardware::hw.encoder, Hardware::hw.encoderButton) {
}

void MainController::init() {
    AbstractMainController::init();
}

void MainController::controllerInit() {
    AbstractMainController::controllerInit();
}

void MainController::update() {
    if(Hardware::hw.resetInput.didRise()) {
        controllers.getActiveController()->reset();
    }

    if(Hardware::hw.clockInput.didRise()) {
        controllers.getActiveController()->clock();
    } else if (Hardware::hw.clockInput.didFall()) {
        controllers.getActiveController()->clear();
    }

    AbstractMainController::update();
}
