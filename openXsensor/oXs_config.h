// OpenXsensor https://code.google.com/p/openxsensor/
// started by Rainer Schloßhan

//***********************************************************************************************************************
// Another file in this project (see oXs_config_description.h) provides detailed explanations on how to set up this file.
//***********************************************************************************************************************
//  Note: the oXs_config.h file present on this Google site is not always meaningful.
//       It could be that the combination of active/non active parameters is not consistent.
//       This is just the result of many updates and tests in this document.
//       So take always care to set up the oXs_config.h file according to your needs and check carefully all options.
//       You can also use the oXs configurator in order to generate automatically a valid file.


#ifndef OXS_CONFIG_h
#define OXS_CONFIG_h


// --------- 1 - General protocol ---------
// ***** 1.1 - Multiplex protocol is used (otherwise oXs assumes it is Frsky protocol) *****
//#define MULTIPLEX
// ***** 1.2 - FrSky protocol and device ID (required when Sport protocol is used)  *****
//#define FRSKY_TYPE_SPORT
//#define FRSKY_TYPE_HUB
#define SENSOR_ID    0x1B //0x1B 
// --------- 2 - Serial data pin choice ---------
#define PIN_SERIALTX      2    // The pin which transmits the serial data to the FrSky telemetry receiver

// --------- 3 - PPM settings ---------
//#define PIN_PPM           3       // default is 2 but my own device use 3
#define PPM_MIN_100       980     // default 1500 - 512 ; // pulse width (usec) when TX sends a channel = -100
#define PPM_PLUS_100      1990    // default 1500 + 512 ; // pulse width (usec) when TX sends a channel = +100

// --------- 4 - Vario settings ---------

// ***** 4.1 - Connecting 1 or 2 MS5611 barometric sensor *****
#define VARIO // set as comment if there is no vario
#define SENSOR_IS_BMP180 // set as comment if baro sensor is MS5611
//#define VARIO2 // set as comment if there is no second vario

// ***** 4.2 - Sensitivity predefined by program *****
#define SENSITIVITY_MIN 50
#define SENSITIVITY_MAX 300
#define SENSITIVITY_MIN_AT 100
#define SENSITIVITY_MAX_AT 1000

// ***** 4.3 - Sensitivity adjusted from the TX *****
#define SENSITIVITY_MIN_AT_PPM 10    // sensitivity will be changed by OXS only when PPM signal is between the specified range enlarged by -5 / +5
#define SENSITIVITY_MAX_AT_PPM 40
#define SENSITIVITY_PPM_MIN  20      // common value for vario is 20
#define SENSITIVITY_PPM_MAX 100      // common value for vario is 100

// ***** 4.4 - Hysteresis parameter & Alt compensation based on sensor temp *****
#define VARIOHYSTERESIS 5
//#define ALT_TEMP_COMPENSATION 800

// ***** 4.5 - Vertical speeds calculations *****
#define VARIO_PRIMARY       0        // 0 means first ms5611, 1 means second ms5611 , 2 means vario based on vario 1 + compensation from airspeed , 3 means average of first and second ms5611
#define VARIO_SECONDARY     2        // 0 means first ms5611, 1 means second ms5611 , 2 means vario based on vario 1 + compensation from airspeed , 3 means average of first and second ms5611
#define SWITCH_VARIO_MIN_AT_PPM 10
#define SWITCH_VARIO_MAX_AT_PPM 90

// ***** 4.6 - Analog vertical speed *****
//#define PIN_ANALOG_VSPEED 3
#define ANALOG_VSPEED_MIN -3
#define ANALOG_VSPEED_MAX  3

// --------- 5 - Airspeed settings ---------
//#define AIRSPEED    MS4525

#define AIRSPEED_RESET_AT_PPM   100

#define COMPENSATION_MIN_AT_PPM 60
#define COMPENSATION_MAX_AT_PPM 90
#define COMPENSATION_PPM_MIN  80
#define COMPENSATION_PPM_MAX 140

// --------- 6 - Voltages & Current sensor settings ---------

// ***** 6.1 - Voltage Reference selection (VCC or 1.1V internal) *****
//#define USE_INTERNAL_REFERENCE

// ***** 6.2 - Voltages Analog Pins *****
//#define PIN_VOLTAGE_1 1
//#define PIN_VOLTAGE_2 2
//#define PIN_VOLTAGE_3 3
//#define PIN_VOLTAGE_4 1
//#define PIN_VOLTAGE_5 2
//#define PIN_VOLTAGE_6 3

// ***** 6.3 - Voltage measurements calibration parameters *****
#define OFFSET_1             0
#define MVOLT_PER_STEP_1       4.89
#define OFFSET_2             0
#define MVOLT_PER_STEP_2       10.1
#define OFFSET_3             0
#define MVOLT_PER_STEP_3       15.1
#define OFFSET_4             0
#define MVOLT_PER_STEP_4       1
#define OFFSET_5             0
#define MVOLT_PER_STEP_5       1
#define OFFSET_6             0
#define MVOLT_PER_STEP_6       15.1

// ***** 6.4 - Number of Lipo cells to measure (and transmit to Tx) *****
#define NUMBEROFCELLS 1  // keep this line but set value to 0 (zero) if you do not want to transmit cell voltage.

// ***** 6.5 - Current sensor analog pin *****
//#define PIN_CURRENTSENSOR   3

// ***** 6.6 - Current sensor calibration parameters *****
#define OFFSET_CURRENT_STEPS         0
#define MAMP_PER_STEP                0.9775

// --------- 7 - RPM (rotations per minute) settings ---------
//#define MEASURE_RPM

// --------- 8 - Persistent memory settings ---------
//#define SAVE_TO_EEPROM
//#define PIN_PUSHBUTTON    2   // default is 10 but my own device is 2

// --------- 9 - Data to transmit ---------
// ***** 9.1 - Frsky data *****
#define SETUP_FRSKY_DATA_TO_SEND    \
                        DEFAULTFIELD , ALTIMETER , 1 , 1 , 0 ,\
                        DEFAULTFIELD , VERTICAL_SPEED , 1 , 1 , 0 
//                        T1 , VOLT3 , 1 , 1 ,0 , \
//                        T2 , TEST3 , 1 , 1, 0
/*
                        VSpd , PPM_VSPEED , 1 , 1 ,0 , \
                        DEFAULTFIELD , AIR_SPEED , 1 , 1 ,0 , \
                        AccX , VERTICAL_SPEED , 1 , 1 ,0 , \
                        AccZ , PRANDTL_DTE , 1 , 1 ,0 ,\
                        T1 , VOLT1 , 1 , 1 ,0 , \
                        T2 , VOLT2 , 1, 1, 0 , \
                        DEFAULTFIELD , CURRENTMA , 1, 1, 0 , \
                        DEFAULTFIELD , MILLIAH, 1, 1, 0 , \
                        Fuel , SENSITIVITY , 1, 1, 0
*/
// ***** 9.2 - Multiplex data *****
#define SETUP_MULTIPLEX_DATA_TO_SEND    \
                        3 , ALTIMETER , 1 , 1 , 0 , -16384 , 16383 , \
                        6 , VERTICAL_SPEED , 1 , 1 , 0, -500 , 500 , \
                        5 , REL_ALTIMETER , 1 , 1 , 0 , -16384 , 16383 , \
                        7 , CELL_TOT , 1 , 1 , 0 , -16384 , 16383 , \
                        5 , ALTIMETER_MAX , 1 , 1 , 0 , -16384 , 16383 
// --------- 10 - Sequencer ---------
//#define SEQUENCE_OUTPUTS 0b100000  
#define SEQUENCE_UNIT 100
#define SEQUENCE_m100    1 , 0b100000 , 1 , 0b000000 , 1   , 0b100000 , 1 , 0b000000 
#define SEQUENCE_m75     1 , 0b100000 , 1 , 0b000000 , 2 , 0b100000 , 2 , 0b000000
#define SEQUENCE_m50     5 , 0b100000 , 5 , 0b000000
#define SEQUENCE_m25     5 , 0b100000 , 5 , 0b000000 , 0   , 0b100000
#define SEQUENCE_0       3 , 0b100000 , 1 , 0b000000
#define SEQUENCE_25      2 , 0b100000 , 2 , 0b000000
#define SEQUENCE_50      5 , 0b100000 , 5 , 0b000000
#define SEQUENCE_75      7 , 0b100000 , 7 , 0b000000
#define SEQUENCE_100     8 , 0b100000 , 8 , 0b000000
#define SEQUENCE_LOW    10 , 0b100000 ,10 , 0b000000   // sequence for Low voltage
//#define SEQUENCE_MIN_VOLT_6 4000 // sequence_100 will be activated if voltage 6 is lower that the value.
#define SEQUENCE_MIN_CELL   3000 // sequence_100 will be activated if lowest cell is lower that the value.
// --------- 11 - Reserved for developer. DEBUG must be activated here when we want to debug one or several functions in some other files. ---------
//#define DEBUG

#ifdef DEBUG
#include "HardwareSerial.h"
#endif

#endif// End define OXS_CONFIG_h

