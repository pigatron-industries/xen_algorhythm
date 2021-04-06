#include "EuclideanRhythmController.h"

EuclideanRhythmController::EuclideanRhythmController(uint8_t lengthPin, uint8_t offsetPin, uint8_t densityPin) : 
    lengthInput(lengthPin, -5, 5, 1, 17),
    densityInput(densityPin, -5, 5, 1, 17),
    offsetInput(offsetPin, -5, 5, 1, 17) {

}

void EuclideanRhythmController::update() {
    if(lengthInput.update()) {
        generator.setLength(lengthInput.getValue());
    }
    if(densityInput.update()) {
        generator.setDensity(densityInput.getValue());
    }
    if(offsetInput.update()) {
        generator.setOffset(offsetInput.getValue());
    }
}

void EuclideanRhythmController::clock() {
    generator.clock();
}

void EuclideanRhythmController::reset() {
    generator.reset();
}
