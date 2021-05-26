#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "hwconfig.h"
#include "modules/controllers/AbstractController.h"
#include "modules/controllers/EuclideanLogicController.h"
#include "modules/controllers/ClockDividerController.h"

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

        RotaryEncoder encoder = RotaryEncoder(ENCODER_PIN1, ENCODER_PIN2);
        PushButton encoderButton = PushButton(ENCODER_BTN_PIN);
        TriggerInput resetInput = TriggerInput(RESET_PIN);
        TriggerInput clockInput = TriggerInput(CLOCK_PIN);

        AbstractController* activeController;
        EuclideanLogicController euclideanLogicController;
        ClockDividerController clockDividerController;

        void modeUpdate();
};

#endif