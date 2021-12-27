#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <eurorack.h>
#include <eurorack_is32fl3738.h>
#include "hwconfig.h"


class Hardware {
    public:
        static Hardware hw;
        void init();

        // Native pins
        DigitalInput(encoderBtnPin, ENCODER_BTN_PIN);

        // Direct connections
        RotaryEncoder encoder = RotaryEncoder(ENCODER_PIN1, ENCODER_PIN2);
        PushButton<> encoderButton = PushButton<>(encoderBtnPin);

        AnalogInput(length1, A3)
        AnalogInput(length2, A2)
        AnalogInput(length3, A1)
        AnalogInput(length4, A0)

        AnalogInput(density1, A7)
        AnalogInput(density2, A6)
        AnalogInput(density3, A5)
        AnalogInput(density4, A4)

        AnalogInput(offset1, A11)
        AnalogInput(offset2, A10)
        AnalogInput(offset3, A9)
        AnalogInput(offset4, A8)

        TriggerInput resetInput = TriggerInput(RESET_PIN);
        TriggerInput clockInput = TriggerInput(CLOCK_PIN);

};

#endif