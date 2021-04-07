#include "EuclideanRhythmGenerator.h"

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

bool EuclideanRhythmGenerator::setMode(Mode mode) {
    if(this->mode != mode) {
        this->mode = mode;
        generate();
        return true;
    }
    return false;
}

#include <Arduino.h>

void EuclideanRhythmGenerator::generate() {
    if(mode == Mode::FRAME_NONE) {
        frameLength = length;
        frameStart = 0;
    }

    rhythm.setLength(frameLength);
    rhythm.clear();

    uint8_t frameStop = frameStart + length - 1;
    
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
    return (beat + offset) % length;
}