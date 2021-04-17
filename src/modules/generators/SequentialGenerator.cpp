#include "SequentialGenerator.h"

SequentialGenerator::SequentialGenerator(Rhythm& rhythm1, Rhythm& rhythm2) :
    rhythm1(rhythm1), 
    rhythm2(rhythm2) {
}

void SequentialGenerator::update() {
    rhythm.setLength(rhythm1.getLength() + rhythm2.getLength());
    uint8_t resultIndex = 0;
    for(uint8_t i = 0; i < rhythm1.getLength(); i++) {
        rhythm.setBeat(resultIndex++, rhythm1.getBeat(i));
    }
    for(uint8_t i = 0; i < rhythm2.getLength(); i++) {
        rhythm.setBeat(resultIndex++, rhythm2.getBeat(i));
    }
}
