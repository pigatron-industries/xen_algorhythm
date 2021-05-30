#ifndef EuclideanChannelController_h
#define EuclideanChannelController_h

#include <eurorack.h>
#include "Controller.h"
#include "channel/EuclideanChannel.h"
#include "modules/generators/SequentialGenerator.h"
#include "modules/LogicGate.h"

class EuclideanLogicController : public Controller {
    public:
        enum Mode {
            ASYNCHRONOUS,
            SYNCHRONOUS,
            DUAL_SEQUENTIAL
        };

        virtual void init();
        virtual void execute();
        virtual void clock();
        virtual void reset();
        virtual void clear();

        void setMode(Mode mode);

    private:
        EuclideanChannel euclideanChannels[4] = {
            EuclideanChannel(A3, A7, A11),
            EuclideanChannel(A2, A6, A10),
            EuclideanChannel(A1, A5, A9),
            EuclideanChannel(A0, A4, A8)
        };

        SequentialGenerator sequentialGenerator[2] = {
            SequentialGenerator(euclideanChannels[0].getRhythm(), euclideanChannels[1].getRhythm()),
            SequentialGenerator(euclideanChannels[2].getRhythm(), euclideanChannels[3].getRhythm()),
        };

        LogicGate logicGates[4] = {
            LogicGate(LogicGate::GateType::AND, euclideanChannels[0].getRhythm(), euclideanChannels[3].getRhythm()),
            LogicGate(LogicGate::GateType::AND, euclideanChannels[1].getRhythm(), euclideanChannels[0].getRhythm()),
            LogicGate(LogicGate::GateType::AND, euclideanChannels[2].getRhythm(), euclideanChannels[1].getRhythm()),
            LogicGate(LogicGate::GateType::AND, euclideanChannels[3].getRhythm(), euclideanChannels[2].getRhythm())
        };

        Mode mode;

        void debugReset();
        void debugClock();
};

#endif