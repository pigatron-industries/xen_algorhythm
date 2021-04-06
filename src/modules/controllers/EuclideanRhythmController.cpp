#include "EuclideanRhythmController.h"

EuclideanRhythmController::EuclideanRhythmController(uint8_t lengthPin, uint8_t offsetPin, uint8_t densityPin) : 
    lengthInput(lengthPin, -5, 5, 1, 17),
    densityInput(densityPin, -5, 5, 0, 1),
    offsetInput(offsetPin, -5, 5, 0, 1) {

}

void EuclideanRhythmController::update() {
    if(lengthInput.update()) {
        generator.setLength(lengthInput.getValue());
    }
    if(densityInput.update()) {
        uint8_t density = generator.getLength() * densityInput.getValue();
        generator.setDensity(density);
    }
    if(offsetInput.update()) {
        uint8_t offset = generator.getLength() * offsetInput.getValue();
        generator.setOffset(offset);
    }
}

void EuclideanRhythmController::clock() {
    generator.clock();
}

void EuclideanRhythmController::reset() {
    generator.reset();
}
