#ifndef RhythmGenerator_h
#define RhythmGenerator_h

#include <inttypes.h>
#include "../Rhythm.h"

class RhythmGenerator {
    public:
        RhythmGenerator() {}
        Rhythm& getRhythm() { return rhythm; }

        void reset() { rhythm.reset(); }
        void clock() { rhythm.clock(); }
        bool getPulse() { return rhythm.getOutput(); }
        bool getStart() { return rhythm.getStart(); }

    protected:
        Rhythm rhythm;
};

#endif