#ifndef ClockDividerController_h
#define ClockDividerController_h

#include <eurorack_dsp.h>
#include "Controller.h"
#include "Hardware.h"

class ClockDividerController : public Controller {
    public:
        virtual void init();
        virtual void update();
        virtual void clock();
        virtual void reset();
        virtual void clear();

    private:
        ClockDivider clockDividers[GATE_OUTPUTS];
};

#endif