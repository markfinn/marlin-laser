#ifndef PINS_H
#define PINS_H

#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1

#if MOTHERBOARD == 1
    /****************************************************************************************
    * Arduino Mega pin assignment
    *
    ****************************************************************************************/
    #include "motherboard/board1.h"
#endif
#if MOTHERBOARD == 2
    /****************************************************************************************
    * FredrikHson ATMega1284p pin assignment
    *
    ****************************************************************************************/
    #include "motherboard/board2.h"

#endif
/****************************************************************************************
* Duemilanove w/ ATMega328P pin assignment
*
****************************************************************************************/
//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#ifdef X_STOP_PIN
    #if X_HOME_DIR < 0
        #define X_MIN_PIN X_STOP_PIN
        #define X_MAX_PIN -1
    #else
        #define X_MIN_PIN -1
        #define X_MAX_PIN X_STOP_PIN
    #endif
#endif

#ifdef Y_STOP_PIN
    #if Y_HOME_DIR < 0
        #define Y_MIN_PIN Y_STOP_PIN
        #define Y_MAX_PIN -1
    #else
        #define Y_MIN_PIN -1
        #define Y_MAX_PIN Y_STOP_PIN
    #endif
#endif

#ifdef Z_STOP_PIN
    #if Z_HOME_DIR < 0
        #define Z_MIN_PIN Z_STOP_PIN
        #define Z_MAX_PIN -1
    #else
        #define Z_MIN_PIN -1
        #define Z_MAX_PIN Z_STOP_PIN
    #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
    #if defined( X_MAX_PIN )
        #undef X_MAX_PIN
        #define X_MAX_PIN          -1
    #endif
    #if defined( Y_MAX_PIN )
        #undef Y_MAX_PIN
        #define Y_MAX_PIN          -1
    #endif
    #if defined( Z_MAX_PIN )
        #undef Z_MAX_PIN
        #define Z_MAX_PIN          -1
    #endif
#endif

#ifdef DISABLE_MIN_ENDSTOPS
    #define X_MIN_PIN          -1
    #define Y_MIN_PIN          -1
    #define Z_MIN_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, \
        X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, \
        X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, \
        Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, \
        Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, \
        Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, \
        FAN_PIN }
#endif
