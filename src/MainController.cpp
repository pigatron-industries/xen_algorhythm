#include "MainController.h"
#include "Hardware.h"
#include "Config.h"

MainController MainController::instance;

MainController::MainController() {
}

void MainController::registerController(Controller& controller) {
    controllers.addController(controller);
}

void MainController::init() {
    Eurorack::init();
    Config::load();
    controllers.setActiveController(Config::data.mode.controllerIndex);
    controllers.getActiveController()->setMode(Config::data.mode.controllerMode);
    controllerInit();
}

void MainController::controllerInit() {
    Config::data.mode.controllerIndex = controllers.getActiveControllerIndex();
    Config::saveMode();

    controllers.getActiveController()->init();
}

void MainController::update() {
    Hardware::hw.encoderButton.update();
    bool cycled = false;
    if(Hardware::hw.encoder.update()) {
        if(Hardware::hw.encoderButton.held()) {
            //change controller when button held down
            if(Hardware::hw.encoder.getMovement() != 0) {
                cycled = true;
                controllers.cycle(Hardware::hw.encoder.getMovement());
                controllerInit();
            } 
        } else {
            //change controller mode
            if(Hardware::hw.encoder.getMovement() != 0) {
                Config::data.mode.controllerMode = controllers.getActiveController()->cycleMode(Hardware::hw.encoder.getMovement());
                Serial.print("Mode: ");
                Serial.println(Config::data.mode.controllerMode);
                controllers.getActiveController()->init();
                Config::saveMode();
            }
        }
    }
    if(Hardware::hw.encoderButton.released()) {
        if(!cycled) {
            controllerInit();
        }
    }

    if(Hardware::hw.resetInput.didRise()) {
        controllers.getActiveController()->reset();
    }

    if(Hardware::hw.clockInput.didRise()) {
        controllers.getActiveController()->clock();
    } else if (Hardware::hw.clockInput.didFall()) {
        controllers.getActiveController()->clear();
    }

    controllers.getActiveController()->update();
}
