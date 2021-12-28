#include <Arduino.h>

#include "hwconfig.h"
#include "MainController.h"
#include "apps.h"


void setup() {
    Serial.begin(SERIAL_BAUD);
    Serial.println();
    Serial.println("==============================================");
    Serial.println("*     Pigatron Industries Euclidean Logic    *");
    Serial.println("==============================================");
    Serial.println();
    registerApps();
    MainController::instance.init();
}

void loop() {
    MainController::instance.update();
}
