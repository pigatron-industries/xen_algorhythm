#ifndef EuclideanRhythmGenerator_h
#define EuclideanRhythmGenerator_h

#include <inttypes.h>
#include "RhythmGenerator.h"

class EuclideanRhythmGenerator : public RhythmGenerator {
    public:
        enum Mode {
            FRAME_NONE,
            FRAME_REPEAT,
            FRAME_SINGLE
        };

        EuclideanRhythmGenerator() {}
        bool setLength(uint8_t length);
        bool setDensity(uint8_t density);
        bool setOffset(uint8_t offset);
        bool setMode(Mode mode);

        uint8_t getLength() { return length; }
        uint8_t getDensity() { return density; }
        uint8_t getOffset() { return offset; }

    private:
        uint8_t length, density, offset;
        uint8_t frameLength, frameStart;
        Mode mode;

        void generate();
        int applyOffset(int beat);
};

#endif