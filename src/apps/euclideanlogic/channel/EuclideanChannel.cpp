#include "EuclideanChannel.h"

EuclideanChannel::EuclideanChannel(uint8_t lengthPin, uint8_t offsetPin, uint8_t densityPin) : 
    lengthInput(lengthPin, -5, 5, 1, 17),
    densityInput(densityPin, -5, 5, 0, 1),
    offsetInput(offsetPin, -5, 5, 0, 1) {
}

bool EuclideanChannel::update() {
    bool change = false;
    if(lengthInput.update()) {
        if(generator.setLength(lengthInput.getValue())) {
            updateDensity();
            updateOffset();
            change = true;
            debug();
        }
    }
    if(densityInput.update()) {
        updateDensity();
        change = true;
    }
    if(offsetInput.update()) {
        updateOffset();
        change = true;
    }
    return change;
}

bool EuclideanChannel::updateDensity() {
    uint8_t density = (generator.getLength()+1) * densityInput.getValue();
    if(generator.setDensity(density)) {
        debug();
        return true;
    }
    return false;
}

bool EuclideanChannel::updateOffset() {
    uint8_t offset = generator.getFrameLength() * offsetInput.getValue();
    if(generator.setOffset(offset)) {
        debug();
        return true;
    }
    return false;
}

void EuclideanChannel::clock() {
    generator.clock();
}

void EuclideanChannel::reset() {
    generator.reset();
}

void EuclideanChannel::debug() {
    Serial.print(generator.getLength());
    Serial.print(" ");
    Serial.print(generator.getDensity());
    Serial.print(" ");
    Serial.print(generator.getOffset());
    Serial.println();

    for(int i = 0; i < generator.getFrameLength(); i++) {
        Serial.print(generator.getRhythm().getBeat(i));
    }
    Serial.println();
}