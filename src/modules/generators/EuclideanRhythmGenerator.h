#ifndef EuclideanRhythmGenerator_h
#define EuclideanRhythmGenerator_h

#include <inttypes.h>
#include "RhythmGenerator.h"

class EuclideanRhythmGenerator : public RhythmGenerator {
    public:
        enum Mode {
            FRAME_NONE,
            FRAME_SINGLE
        };

        EuclideanRhythmGenerator() {}

        bool setLength(uint8_t length);
        bool setDensity(uint8_t density);
        bool setOffset(uint8_t offset);
        bool setFrameLength(uint8_t frameLength);
        bool setMode(Mode mode);

        uint8_t getLength() { return length; }
        uint8_t getDensity() { return density; }
        uint8_t getOffset() { return offset; }
        uint8_t getFrameLength() { return frameLength; }
        Mode getMode() { return mode; }

    private:
        uint8_t length, density, offset;
        uint8_t frameLength;
        Mode mode;

        void generate();
        int applyOffset(int beat);
};

#endif