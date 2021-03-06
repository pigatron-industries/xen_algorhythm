#include "EuclideanChannel.h"

EuclideanChannel::EuclideanChannel(AnalogInputPin<>& lengthPin, AnalogInputPin<>& offsetPin, AnalogInputPin<>& densityPin) : 
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
        }
    }
    if(densityInput.update()) {
        change |= updateDensity();
    }
    if(offsetInput.update()) {
        change |= updateOffset();
    }
    return change;
}

bool EuclideanChannel::updateDensity() {
    uint8_t density = (generator.getLength()+1) * densityInput.getValue();
    if(generator.setDensity(density)) {
        return true;
    }
    return false;
}

bool EuclideanChannel::updateOffset() {
    uint8_t offset = generator.getFrameLength() * offsetInput.getValue();
    if(generator.setOffset(offset)) {
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