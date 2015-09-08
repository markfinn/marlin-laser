#ifndef __MOTHERBOARD2_H__
#define __MOTHERBOARD2_H__

/****************************************************************************************
* FredrikHson ATMega1284p pin assignment
*
****************************************************************************************/
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega1284P__
    #error Oops!  Make sure you have 'Atmega1284p' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH true // only for beeping

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_STOP_PIN         18

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_STOP_PIN         19

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_STOP_PIN         20

#define X_ENABLE_PIN       14
#define Y_ENABLE_PIN       14
#define Z_ENABLE_PIN       26

#define SDPOWER            -1
#define SDSS               31

#define LASER_INTENSITY_PIN 6 // Digital pins 3,4,6,7,12,13,14,15  are attached to timers we can use
#define LASER_FIRING_PIN    5

#ifdef LASER_POWER_DOWN
    #define LASER_POWER_PIN 9 // This is currently hard-coded to timer2 which services pins 9, 10
#endif // LASER_POWER_DOWN
#ifdef LASER_PERIPHERALS
    #define LASER_PERIPHERALS_PIN       4
    #define LASER_PERIPHERALS_STATUS_PIN          11
#endif // LASER_PERIPHERALS

#define FAN_PIN            9 // (Sprinter config)


#endif //__MOTHERBOARD2_H__
