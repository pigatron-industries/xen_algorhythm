#ifndef EuclideanChannelController_h
#define EuclideanChannelController_h

#include <eurorack.h>
#include "Controller.h"
#include "channel/EuclideanChannel.h"
#include "Hardware.h"
#include "modules/generators/SequentialGenerator.h"
#include "modules/LogicGate.h"

class EuclideanLogicController : public Controller {
    public:
        enum Mode {
            ASYNCHRONOUS,
            SYNCHRONOUS,
            SYNCHRONOUS_LIMITED,
            DUAL_SEQUENTIAL
        };

        EuclideanLogicController() : Controller(Mode::DUAL_SEQUENTIAL) {}

        virtual void init();
        virtual void update();
        virtual void clock();
        virtual void reset();
        virtual void clear();

        void setMode(Mode mode);

    private:

        EuclideanChannel asyncEuclideanChannels[4] = {
            EuclideanChannel(Hardware::hw.length1, Hardware::hw.density1, Hardware::hw.offset1),
            EuclideanChannel(Hardware::hw.length2, Hardware::hw.density2, Hardware::hw.offset2),
            EuclideanChannel(Hardware::hw.length3, Hardware::hw.density3, Hardware::hw.offset3),
            EuclideanChannel(Hardware::hw.length4, Hardware::hw.density4, Hardware::hw.offset4)
        };

        EuclideanChannel syncEuclideanChannels[4] = {
            EuclideanChannel(Hardware::hw.length1, Hardware::hw.density1, Hardware::hw.offset1),
            EuclideanChannel(Hardware::hw.length1, Hardware::hw.density2, Hardware::hw.offset2),
            EuclideanChannel(Hardware::hw.length1, Hardware::hw.density3, Hardware::hw.offset3),
            EuclideanChannel(Hardware::hw.length1, Hardware::hw.density4, Hardware::hw.offset4)
        };

        EuclideanChannel* euclideanChannels = asyncEuclideanChannels;

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

        void setFrameMode(EuclideanRhythmGenerator::FrameMode frameMode);
        void debug();
        void debugClock();
};

#endif