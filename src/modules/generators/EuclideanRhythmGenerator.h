#ifndef EuclideanRhythmGenerator_h
#define EuclideanRhythmGenerator_h

#include <inttypes.h>
#include "RhythmGenerator.h"

class EuclideanRhythmGenerator : public RhythmGenerator {
    public:
        enum FrameMode {
            FRAME_NONE,
            FRAME_SINGLE
        };

        EuclideanRhythmGenerator() {}

        bool setLength(uint8_t length);
        bool setDensity(uint8_t density);
        bool setOffset(uint8_t offset);
        bool setFrameLength(uint8_t frameLength);
        bool setFrameMode(FrameMode frameMode);

        uint8_t getLength() { return length; }
        uint8_t getDensity() { return density; }
        uint8_t getOffset() { return offset; }
        uint8_t getFrameLength() { return frameLength; }
        FrameMode getFrameMode() { return frameMode; }

    private:
        uint8_t length, density, offset;
        uint8_t frameLength;
        FrameMode frameMode;

        void generate();
        int applyOffset(int beat);
};

#endif