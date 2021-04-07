#ifndef Rhythm_h
#define Rhythm_h

#include <inttypes.h>

#define MAX_LENGTH 32

class Rhythm {
    public:
        Rhythm() {}
        void setLength(uint8_t length) { this->length = length; }
        void setPulse(uint8_t index, bool pulse) { this->rhythm[index] = pulse; }
        void clear();

        void reset() { position = -1; finished = false; }
        void clock();
        bool getOutput() { return rhythm[position]; }
        uint8_t getPosition() { return position; }
        bool isFinished() { return finished; }
        bool getBeat(int i) { return rhythm[i]; }

    private:
        uint8_t length = 8;
        int8_t position = -1;
        bool finished = false;
        bool rhythm[MAX_LENGTH];
};

#endif