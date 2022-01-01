#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <eurorack.h>
#if defined(ALGORHYTHM_MKII)
    #include <eurorack_mcp23s17.h>
#endif
//#if defined(ALGORHYTHM_MKI)
    #include <eurorack_hc595.h>
//#endif
#include "hwconfig.h"


class Hardware {
    public:
        static Hardware hw;
        void init();
        void updateOutputs();

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

        #if defined(ALGORHYTHM_MKII)
            #define GATE_OUTPUTS 12
            MCP23S17Device mcp23s17Device = MCP23S17Device(GPIO_CS_PIN, GPIO_ADDRESS);
            DigitalInputPin<MCP23S17Device>& clockInputPin = mcp23s17Device.pins[4];
            DigitalInputPin<MCP23S17Device>& resetInputPin = mcp23s17Device.pins[5];
            DigitalInputPin<MCP23S17Device>& rotateInputPin = mcp23s17Device.pins[6];
            DigitalInputPin<MCP23S17Device>& chnageInputPin = mcp23s17Device.pins[7];
            GateInput<MCP23S17Device> clockInput = GateInput<MCP23S17Device>(clockInputPin);
            GateInput<MCP23S17Device> resetInput = GateInput<MCP23S17Device>(resetInputPin);
            DigitalOutputPin<MCP23S17Device>* gateOutputs[12] = {
                &mcp23s17Device.pins[8],
                &mcp23s17Device.pins[9],
                &mcp23s17Device.pins[10],
                &mcp23s17Device.pins[11],
                &mcp23s17Device.pins[12],
                &mcp23s17Device.pins[13],
                &mcp23s17Device.pins[14],
                &mcp23s17Device.pins[15],
                &mcp23s17Device.pins[0],
                &mcp23s17Device.pins[1],
                &mcp23s17Device.pins[2],
                &mcp23s17Device.pins[3]
            }; 
        #endif

        #if defined(ALGORHYTHM_MKI)
            #define GATE_OUTPUTS 8
            TriggerInput resetInput = TriggerInput(RESET_PIN);
            TriggerInput clockInput = TriggerInput(CLOCK_PIN);
            HC595Device hc595Device = HC595Device(OUT_CLOCK_PIN, OUT_LATCH_PIN, OUT_DATA_PIN);
            DigitalOutputPin<HC595Device>* gateOutputs[8] = {
                &hc595Device.pins[0],
                &hc595Device.pins[1],
                &hc595Device.pins[2],
                &hc595Device.pins[3],
                &hc595Device.pins[4],
                &hc595Device.pins[5],
                &hc595Device.pins[6],
                &hc595Device.pins[7]
            }; 
        #endif

};

#endif