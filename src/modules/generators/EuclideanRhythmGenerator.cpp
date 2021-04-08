#include "EuclideanRhythmGenerator.h"
#include <Arduino.h>

bool EuclideanRhythmGenerator::setLength(uint8_t length) {
    if(this->length != length) {
        this->length = length;
        generate();
        return true;
    }
    return false;
}

bool EuclideanRhythmGenerator::setDensity(uint8_t density) {
    if(this->density != density) {
        this->density = density;
        generate();
        return true;
    }
    return false;
}

bool EuclideanRhythmGenerator::setOffset(uint8_t offset) {
    if(this->offset != offset) {
        this->offset = offset;
        generate();
        return true;
    }
    return false;
}

bool EuclideanRhythmGenerator::setFrameLength(uint8_t frameLength) {
    if(mode != Mode::FRAME_NONE && this->frameLength != frameLength) {
        Serial.println(frameLength);
        this->frameLength = frameLength;
        generate();
        return true;
    }
    return false;
}

bool EuclideanRhythmGenerator::setMode(Mode mode) {
    if(this->mode != mode) {
        this->mode = mode;
        generate();
        return true;
    }
    return false;
}

void EuclideanRhythmGenerator::generate() {
    uint8_t frameStart = 0;
    if(mode == Mode::FRAME_NONE) {
        frameLength = length;
    }
    uint8_t frameStop = frameStart + length - 1;

    rhythm.setLength(frameLength);
    rhythm.clear();
    
    int bucket = 0;
    for(int i = frameStop; i >= frameStart; i--) {
        bucket += density;
        if(bucket >= length) {
            bucket -= length;
            rhythm.setPulse(applyOffset(i), true);
        } else {
            rhythm.setPulse(applyOffset(i), false);
        }
    }
}

int EuclideanRhythmGenerator::applyOffset(int beat) {
    return (beat + offset) % frameLength;
}
