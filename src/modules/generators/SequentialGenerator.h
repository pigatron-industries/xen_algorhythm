#ifndef SequentialGenerator_h
#define SequentialGenerator_h

#include <inttypes.h>
#include "RhythmGenerator.h"

class SequentialGenerator : public RhythmGenerator {
    public:
        SequentialGenerator(Rhythm& rhythm1, Rhythm& rhythm2);
        void update();

    private:
        Rhythm& rhythm1;
        Rhythm& rhythm2;
};

#endif