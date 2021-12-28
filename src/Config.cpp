#include "Config.h"
#include <EEPROM.h>
#include <Arduino.h>

Config Config::data;

void Config::load() {
    int address = 0;
    EEPROM.get(address, data);
}

void Config::saveMode() {
    int address = 0;
    EEPROM.put(address, data.mode);
}
