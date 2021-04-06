#include "EuclideanRhythmGenerator.h"

void EuclideanRhythmGenerator::setLength(uint8_t length) {
    if(this->length != length) {
        this->length = length;
        generate();
    }
}

void EuclideanRhythmGenerator::setDensity(uint8_t density) {
    if(this->density != density) {
        this->density = density;
        generate();
    }
}

void EuclideanRhythmGenerator::setOffset(uint8_t offset) {
    if(this->offset != offset) {
        this->offset = offset;
        generate();
    }
}

#include <Arduino.h>

void EuclideanRhythmGenerator::generate() {
    Serial.println("EuclideanRhythmGenerator::generate");
    Serial.print(length);
    Serial.print(" ");
    Serial.print(density);
    Serial.print(" ");
    Serial.print(offset);
    Serial.println();
    rhythm.setLength(length);

    int bucket = 0;
    for(int i = length-1; i >= 0; i--) {
        bucket += density;
        if(bucket >= length) {
            bucket -= length;
            rhythm.setPulse(applyOffset(i), true);
        } else {
            rhythm.setPulse(applyOffset(i), false);
        }
    }

    for(int i = 0; i < length; i++) {
        Serial.print(rhythm.getBeat(i));
    }
    Serial.println();
}

int EuclideanRhythmGenerator::applyOffset(int beat) {
    return (beat + offset) % length;
}