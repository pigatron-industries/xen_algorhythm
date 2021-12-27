#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    analogReadResolution(12);

    // Wire.setSDA(SDA_PIN);
    // Wire.setSCL(SCL_PIN);
    // Wire.setClock(I2C_SPEED);
    // Wire.begin();
}
