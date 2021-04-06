#ifndef EuclideanRhythmGenerator_h
#define EuclideanRhythmGenerator_h

#include <inttypes.h>
#include "RhythmGenerator.h"

class EuclideanRhythmGenerator : public RhythmGenerator {
    public:
        EuclideanRhythmGenerator() {}
        void setLength(uint8_t length);
        void setDensity(uint8_t density);
        void setOffset(uint8_t offset);

        uint8_t getLength() { return length; }
        bool getOutput() { return rhythm.getOutput(); }

    private:
        uint8_t length, density, offset;

        void generate();
        int applyOffset(int beat);
};

#endif