#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "hwconfig.h"
#include "modules/controllers/EuclideanLogicController.h"

#define CHANNELS 4
#define OUTPUTS 8

class MainController {
    public:

        enum Mode {
            ASYNC_REPEAT,
            SYNC_SINGLE
        };

        MainController();
        void init();
        void execute();

    private:
        CycleEnum<Mode> mode = CycleEnum<Mode>(ASYNC_REPEAT, SYNC_SINGLE);

        RotaryEncoder encoder = RotaryEncoder(ENCODER_PIN1, ENCODER_PIN2);
        PushButton encoderButton = PushButton(ENCODER_BTN_PIN);
        TriggerInput resetInput = TriggerInput(RESET_PIN);
        TriggerInput clockInput = TriggerInput(CLOCK_PIN);

        EuclideanLogicController euclideanLogicController;

        void modeUpdate();
};

#endif