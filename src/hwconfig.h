
// Teensy Pins
#if defined(ALGORHYTHM_MKI)
    #define ENCODER_PIN1 7
    #define ENCODER_PIN2 8
    #define ENCODER_BTN_PIN 9
#endif

#if defined(ALGORHYTHM_MKII)
    #define ENCODER_PIN1 4
    #define ENCODER_PIN2 3
    #define ENCODER_BTN_PIN 2
#endif

#define RESET_PIN 2
#define CLOCK_PIN 3

#define OUT_DATA_PIN 4
#define OUT_CLOCK_PIN 5
#define OUT_LATCH_PIN 6

//GPIO expander
#define GPIO_CS_PIN 10
#define GPIO_ADDRESS 0x20

// Other config
#define SERIAL_BAUD 115200
