#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "hwconfig.h"
#include "Controller.h"

#define CHANNELS 4
#define OUTPUTS 8

class MainController {
    public:
        static MainController instance;

        MainController();
        void init();
        void update();

        void registerController(Controller& controller);

    private:
        ControllerList<Controller, 2> controllers;

        void controllerInit();
};

#endif