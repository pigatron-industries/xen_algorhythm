#ifndef EuclideanChannelController_h
#define EuclideanChannelController_h

#include <eurorack.h>
#include "AbstractController.h"
#include "channel/EuclideanChannel.h"

class EuclideanLogicController : public AbstractController {
    public:
        virtual void init();
        virtual void execute();
        virtual void clock();
        virtual void reset();
        virtual void clear();

        void setMode(EuclideanRhythmGenerator::Mode mode);

    private:
        EuclideanChannel euclideanChannels[4] = {
            EuclideanChannel(A3, A7, A11),
            EuclideanChannel(A2, A6, A10),
            EuclideanChannel(A1, A5, A9),
            EuclideanChannel(A0, A4, A8)
        };

        EuclideanRhythmGenerator::Mode mode;

        void debugReset();
        void debugClock();
};

#endif