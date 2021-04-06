#ifndef Rhythm_h
#define Rhythm_h

#include <inttypes.h>

#define MAX_LENGTH 32

class Rhythm {
    public:
        Rhythm() {}
        void setLength(uint8_t length) { this->length = length; }
        void setPulse(uint8_t index, bool pulse) { this->rhythm[index] = pulse; }

        void reset() { position = -1; }
        void clock();
        bool getOutput() { return rhythm[position]; }
        bool getStart() { return position == 0; }
        bool getBeat(int i) { return rhythm[i]; }

    private:
        uint8_t length = 8;
        int8_t position = -1;
        bool rhythm[MAX_LENGTH];
};

#endif