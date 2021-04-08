#ifndef EuclideanRhythmController_h
#define EuclideanRhythmController_h

#include <eurorack.h>
#include <inttypes.h>
#include "../../generators/EuclideanRhythmGenerator.h"

class EuclideanRhythmController {
    public:
        EuclideanRhythmController(uint8_t lengthPin, uint8_t densityPin, uint8_t offsetPin);
        void update();
        void clock();
        void reset();

        bool getOutput() { return generator.getOutput(); }
        uint8_t getPosition() { return generator.getPosition(); }
        uint8_t getLength() { return generator.getLength(); }

        void setMode(EuclideanRhythmGenerator::Mode mode) { generator.setMode(mode); };
        void setFrameLength(uint8_t frameLength) { generator.setFrameLength(frameLength); };

        void debug();

    private:
        LinearInput lengthInput;
        LinearInput densityInput;
        LinearInput offsetInput;

        EuclideanRhythmGenerator generator;

};

#endif