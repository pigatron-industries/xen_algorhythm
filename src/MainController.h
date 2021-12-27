#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "hwconfig.h"
#include "Controller.h"
#include "controllers/euclideanlogic/EuclideanLogicController.h"
#include "controllers/clockdivider/ClockDividerController.h"

#define CHANNELS 4
#define OUTPUTS 8

class MainController {
    public:

        enum Mode {
            EUCLID_ASYNCHRONOUS,
            EUCLID_SYNCHRONOUS,
            EUCLID_DUAL_SEQUENTIAL,
            CLOCK_DIVIDER
        };

        MainController();
        void init();
        void execute();

    private:
        CycleEnum<Mode> mode = CycleEnum<Mode>(Mode::EUCLID_ASYNCHRONOUS, Mode::CLOCK_DIVIDER);

        Controller* activeController;
        EuclideanLogicController euclideanLogicController;
        ClockDividerController clockDividerController;

        void modeUpdate();
};

#endif