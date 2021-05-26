#ifndef ClockDividerController_h
#define ClockDividerController_h

#include <eurorack.h>
#include "AbstractController.h"

class ClockDividerController : public AbstractController {
    public:
        virtual void init();
        virtual void execute();
        virtual void clock();
        virtual void reset();
        virtual void clear();

    private:
        int counter;
};

#endif