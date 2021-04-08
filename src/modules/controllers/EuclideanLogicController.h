#ifndef EuclideanChannelController_h
#define EuclideanChannelController_h

#include <eurorack.h>
#include "AbstractController.h"
#include "channel/EuclideanChannelController.h"

class EuclideanLogicController : public AbstractController {
    public:
        virtual void init();
        virtual void execute();
        virtual void clock();
        virtual void reset();
        virtual void clear();

        void setMode(EuclideanRhythmGenerator::Mode mode);

    private:
        EuclideanRhythmController euclideanRhythmControllers[CHANNELS] = {
            EuclideanRhythmController(A3, A7, A11),
            EuclideanRhythmController(A2, A6, A10),
            EuclideanRhythmController(A1, A5, A9),
            EuclideanRhythmController(A0, A4, A8)
        };

        EuclideanRhythmGenerator::Mode mode;

        void debugReset();
        void debugClock();
};

#endif