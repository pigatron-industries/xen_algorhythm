#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "apps.h"
#include "hwconfig.h"
#include "Controller.h"

#define CHANNELS 4
#define OUTPUTS 8

class MainController : public AbstractMainController<Controller, CONTROLLERS> {
    public:
        static MainController instance;

        MainController();
        void init();
        void update();

    private:
        void controllerInit();
};

#endif