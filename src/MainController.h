#ifndef MainController_h
#define MainController_h

#include <eurorack.h>
#include "hwconfig.h"
#include "modules/controllers/EuclideanRhythmController.h"

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
        GateInput resetInput = GateInput(RESET_PIN);
        GateInput clockInput = GateInput(CLOCK_PIN);
        MultiplexGateOutput gateOutputs = MultiplexGateOutput(OUT_DATA_PIN, OUT_LATCH_PIN, OUT_CLOCK_PIN, OUTPUTS);
        
        EuclideanRhythmController euclideanRhythmControllers[CHANNELS] = {
            EuclideanRhythmController(A3, A7, A11),
            EuclideanRhythmController(A2, A6, A10),
            EuclideanRhythmController(A1, A5, A9),
            EuclideanRhythmController(A0, A4, A8)
        };

        void clock();
        void reset();
        void clear();
        void modeUpdate();

        void debugReset();
        void debugClock();
};

#endif