#ifndef EuclideanChannel_h
#define EuclideanChannel_h

#include <eurorack.h>
#include <inttypes.h>
#include "modules/generators/EuclideanRhythmGenerator.h"

class EuclideanChannel {
    public:
        EuclideanChannel(AnalogInputPin<>& lengthPin, AnalogInputPin<>& densityPin, AnalogInputPin<>& offsetPin);
        bool update();
        void clock();
        void reset();

        bool getOutput() { return generator.getOutput(); }
        uint8_t getPosition() { return generator.getPosition(); }
        uint8_t getLength() { return generator.getLength(); }
        Rhythm& getRhythm() { return generator.getRhythm(); }

        void setFrameMode(EuclideanRhythmGenerator::FrameMode frameMode) { generator.setFrameMode(frameMode); };
        void setFrameLength(uint8_t frameLength) { generator.setFrameLength(frameLength); };

        void debug();

    private:
        LinearInput<> lengthInput;
        LinearInput<> densityInput;
        LinearInput<> offsetInput;

        EuclideanRhythmGenerator generator;

        bool updateDensity();
        bool updateOffset();

};

#endif