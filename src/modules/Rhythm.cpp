#include "Rhythm.h"

#include <Arduino.h>

void Rhythm::clear() {
    for(uint8_t i = 0; i < length; i++) {
        rhythm[i] = false;
    }
}

void Rhythm::clock() {
    position++;
    if(position >= length) {
        position = 0;
    }
}