#ifndef RhythmGenerator_h
#define RhythmGenerator_h

#include <inttypes.h>
#include "../Rhythm.h"

class RhythmGenerator {
    public:
        RhythmGenerator() {}
        Rhythm* getRhythm() { return &rhythm; }

        void reset() { rhythm.reset(); }
        void clock() { rhythm.clock(); }
        bool getOutput() { return rhythm.getOutput(); }
        uint8_t getPosition() { return rhythm.getPosition(); }

    protected:
        Rhythm rhythm;
};

#endif