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
    AbstractMainController::update();
}
