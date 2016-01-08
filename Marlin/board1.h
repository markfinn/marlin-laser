#ifndef __MOTHERBOARD1_H__
#define __MOTHERBOARD1_H__

/****************************************************************************************
* Arduino Mega pin assignment
*
****************************************************************************************/
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
    #ifndef __AVR_ATmega2560__
        #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
    #endif
#endif


#define LARGE_FLASH true

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define LASER_INTENSITY_PIN 6 // Digital pins 2, 3, 5, 6, 7, 8 are attached to timers we can use
#define LASER_FIRING_PIN    5

#ifdef LASER_POWER_DOWN
    #define LASER_POWER_PIN 9 // This is currently hard-coded to timer2 which services pins 9, 10
#endif // LASER_POWER_DOWN
#ifdef LASER_PERIPHERALS
    #define LASER_PERIPHERALS_PIN       4
    #define LASER_PERIPHERALS_STATUS_PIN          11
#endif // LASER_PERIPHERALS

#define FAN_PIN            9 // (Sprinter config)

//#define CONTROLLERFAN_PIN  10 //Pin used for the fan to cool controller

#if defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL)
    #define KILL_PIN           41
#else
    #define KILL_PIN           -1
#endif

#ifdef ULTRA_LCD

    #ifdef NEWPANEL
        #define LCD_PINS_RS 16
        #define LCD_PINS_ENABLE 17
        #define LCD_PINS_D4 23
        #define LCD_PINS_D5 25
        #define LCD_PINS_D6 27
        #define LCD_PINS_D7 29

        #ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
            #define BEEPER 37

            #define BTN_EN1 31
            #define BTN_EN2 33
            #define BTN_ENC 35

            #define SDCARDDETECT 49
        #elif defined(LCD_I2C_PANELOLU2)
            #define BTN_EN1 47  //reverse if the encoder turns the wrong way.
            #define BTN_EN2 43
            #define BTN_ENC 32
            #define SDSS 53
            #define SDCARDDETECT -1
            #define KILL_PIN 41
        #elif defined(LCD_I2C_VIKI)
            #define BTN_EN1 22  //reverse if the encoder turns the wrong way.
            #define BTN_EN2 7
            #define BTN_ENC -1
            #define SDSS 53
            #define SDCARDDETECT 49
        #else
            //arduino pin which triggers an piezzo beeper
            #define BEEPER 33  // Beeper on AUX-4

            //buttons are directly attached using AUX-2
            #ifdef REPRAPWORLD_KEYPAD
                #define BTN_EN1 64 // encoder
                #define BTN_EN2 59 // encoder
                #define BTN_ENC 63 // enter button
                #define SHIFT_OUT 40 // shift register
                #define SHIFT_CLK 44 // shift register
                #define SHIFT_LD 42 // shift register
            #else
                #define BTN_EN1 37
                #define BTN_EN2 35
                #define BTN_ENC 31  //the click
            #endif

            #ifdef G3D_PANEL
                #define SDCARDDETECT 49
            #else
                #define SDCARDDETECT -1  // Ramps does not use this port
            #endif

        #endif

    #else //old style panel with shift register
        //arduino pin witch triggers an piezzo beeper
        #define BEEPER 33       //No Beeper added

        //buttons are attached to a shift register
        // Not wired this yet
        //#define SHIFT_CLK 38
        //#define SHIFT_LD 42
        //#define SHIFT_OUT 40
        //#define SHIFT_EN 17

        #define LCD_PINS_RS 16
        #define LCD_PINS_ENABLE 17
        #define LCD_PINS_D4 23
        #define LCD_PINS_D5 25
        #define LCD_PINS_D6 27
        #define LCD_PINS_D7 29
    #endif
#endif //ULTRA_LCD

#ifndef SDSUPPORT
    // these pins are defined in the SD library if building with SD support
    #define MAX_SCK_PIN          52
    #define MAX_MISO_PIN         50
    #define MAX_MOSI_PIN         51
    #define MAX6675_SS       53
#else
    #define MAX6675_SS       49
#endif

#endif //__MOTHERBOARD1_H__
