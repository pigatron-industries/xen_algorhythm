#ifndef ClockDividerController_h
#define ClockDividerController_h

#include <eurorack.h>
#include "Controller.h"

class ClockDividerController : public Controller {
    public:
        virtual void init();
        virtual void update();
        virtual void clock();
        virtual void reset();
        virtual void clear();

    private:
        int counter;
};

#endif