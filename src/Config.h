#ifndef Config_h
#define Config_h

#include <inttypes.h>

class Mode {
    public:
        uint8_t controllerIndex;
        uint8_t controllerMode;
};

class Config {

    public:
        static Config data;
        Mode mode;

        static void load();
        static void saveMode();
    
};

#endif
