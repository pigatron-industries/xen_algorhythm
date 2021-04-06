#include <Arduino.h>

#include "hwconfig.h"
#include "MainController.h"

// hardware

MainController mainController = MainController();


void setup() {
    Serial.begin(SERIAL_BAUD);
    Serial.println();
    Serial.println("==============================================");
    Serial.println("*     Pigatron Industries Euclidean Logic    *");
    Serial.println("==============================================");
    Serial.println();
    mainController.init();
}

void loop() {
    mainController.execute();
}
