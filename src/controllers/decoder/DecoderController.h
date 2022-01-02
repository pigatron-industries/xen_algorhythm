#ifndef DecoderController_h
#define DecoderController_h

#include <eurorack_dsp.h>
#include "Controller.h"
#include "Hardware.h"

class DecoderController : public Controller {
    public:
        enum Mode {
            SYNCHRONOUS,
            ASYNCHRONOUS
        };

        DecoderController() : Controller(Mode::ASYNCHRONOUS) {}

        virtual void init();
        virtual void update();
        virtual void clock();
        virtual void reset();
        virtual void clear();

    private:

        void decode();
};

#endif