#include "Config.h"
#include <EEPROM.h>
#include <Arduino.h>

Config Config::data;

void Config::load() {
    int address = 0;
    EEPROM.get(address, data);
    Serial.println("load");
    Serial.println(data.mode.controllerIndex);
}

void Config::saveMode() {
    int address = 0;
    EEPROM.put(address, data.mode);
    Serial.println("save");
    Serial.println(data.mode.controllerIndex);
}
