/*
 * TongSheng TSDZ2 motor controller firmware/
 *
 * Copyright (C) Casainho and Leon, 2019.
 *
 * Released under the GPL License, Version 3
 */

#ifndef _MAIN_H_
#define _MAIN_H_


//#define DEBUG_UART



// motor 
#define PWM_CYCLES_COUNTER_MAX                                    3125  // 5 erps minimum speed -> 1/5 = 200 ms; 200 ms / 64 us = 3125
#define PWM_CYCLES_SECOND                                         15625 // 1 / 64us(PWM period)
#define PWM_DUTY_CYCLE_MAX                                        254
#define MIDDLE_PWM_DUTY_CYCLE_MAX                                 (PWM_DUTY_CYCLE_MAX / 2)

#define PWM_DUTY_CYCLE_RAMP_UP_INVERSE_STEP_DEFAULT               160   // 160 -> 160 * 64 us for every duty cycle increment
#define PWM_DUTY_CYCLE_RAMP_UP_INVERSE_STEP_MIN                   20    // 20 -> 20 * 64 us for every duty cycle increment

#define PWM_DUTY_CYCLE_RAMP_DOWN_INVERSE_STEP_DEFAULT             40    // 40 -> 40 * 64 us for every duty cycle decrement
#define PWM_DUTY_CYCLE_RAMP_DOWN_INVERSE_STEP_MIN                 8     // 8 -> 8 * 64 us for every duty cycle decrement

/*---------------------------------------------------------
  NOTE: regarding duty cycle (PWM) ramping
  
  Do not change these values if not sure of the effects!
  
  A lower value of the duty cycle inverse step will mean
  a faster acceleration. Be careful not to choose too
  low values for acceleration.
---------------------------------------------------------*/



#define MOTOR_ROTOR_OFFSET_ANGLE                                  10
#define MOTOR_ROTOR_ANGLE_90                                      (63  + MOTOR_ROTOR_OFFSET_ANGLE)
#define MOTOR_ROTOR_ANGLE_150                                     (106 + MOTOR_ROTOR_OFFSET_ANGLE)
#define MOTOR_ROTOR_ANGLE_210                                     (148 + MOTOR_ROTOR_OFFSET_ANGLE)
#define MOTOR_ROTOR_ANGLE_270                                     (191 + MOTOR_ROTOR_OFFSET_ANGLE)
#define MOTOR_ROTOR_ANGLE_330                                     (233 + MOTOR_ROTOR_OFFSET_ANGLE)
#define MOTOR_ROTOR_ANGLE_30                                      (20  + MOTOR_ROTOR_OFFSET_ANGLE)

/*---------------------------------------------------------
  NOTE: regarding motor rotor offset 
  
  The motor rotor offset should be as close to 0 as 
  possible. You can try to tune with the wheel in the air,
  full throttle and look at the batttery current. Adjust 
  for the lowest battery current possible.
---------------------------------------------------------*/



#define MOTOR_OVER_SPEED_ERPS                                     520   // motor max speed, protection max value | 30 points for the sinewave at max speed
#define MOTOR_OVER_SPEED_ERPS_EXPERIMENTAL                        700   // experimental motor speed to allow a higher cadence

#define MOTOR_ROTOR_ERPS_START_INTERPOLATION_60_DEGREES           10

/*---------------------------------------------------------
  NOTE: regarding motor start interpolation
  
  This value is the ERPS speed after which a transition 
  happens from sinewave and no interpolation to 
  interpolation 60 degrees. Must be found experimentally 
  but a value of 25 may be good.
---------------------------------------------------------*/



#define ADC_10_BIT_BATTERY_CURRENT_MAX                            106   // 18 amps
#define ADC_10_BIT_MOTOR_PHASE_CURRENT_MAX                        177   // 30 amps

/*---------------------------------------------------------
  NOTE: regarding ADC battery current max
  
  This is the maximum current in ADC steps that the motor 
  will be able to draw from the battery. A higher value 
  will give higher torque figures but the limit of the 
  controller is 16 A and it should not be exceeded.
---------------------------------------------------------*/



// throttle ADC values
#define ADC_THROTTLE_MIN_VALUE                                    47
#define ADC_THROTTLE_MAX_VALUE                                    176

/*---------------------------------------------------------
  NOTE: regarding throttle ADC values

  Max voltage value for throttle, in ADC 8 bits step, 
  each ADC 8 bits step = (5 V / 256) = 0.0195

---------------------------------------------------------*/



// cadence sensor
#define CADENCE_SENSOR_NUMBER_MAGNETS                             20
#define CADENCE_SENSOR_NUMBER_MAGNETS_X2                          (CADENCE_SENSOR_NUMBER_MAGNETS * 2)

#define CADENCE_SENSOR_TICKS_COUNTER_MAX                          300
#define CADENCE_SENSOR_TICKS_COUNTER_MIN                          10000

#define CADENCE_SENSOR_PULSE_PERCENTAGE_X10_DEFAULT               500
#define CADENCE_SENSOR_PULSE_PERCENTAGE_X10_MAX                   800
#define CADENCE_SENSOR_PULSE_PERCENTAGE_X10_MIN                   200

/*-------------------------------------------------------------------------------
  NOTE: regarding the cadence sensor
  
  CADENCE_SENSOR_NUMBER_MAGNETS = 20, this is the number of magnets used for
  the cadence sensor. Was validated on August 2018 by Casainho and jbalat
  
  x = (1/(150RPM/60)) / (0.000064)
  
  6250 / CADENCE_SENSOR_NUMBER_MAGNETS ≈ 313 -> 150 RPM
  
  93750 / CADENCE_SENSOR_NUMBER_MAGNETS ≈ 4688 -> 10 RPM
  
  CADENCE_SENSOR_TICKS_COUNTER_MAX = x / CADENCE_SENSOR_NUMBER_MAGNETS
  

  
  CADENCE_SENSOR_NUMBER_MAGNETS_X2 = 40, this is the number of transitions 
  in one crank revolution
  
  x = (1/(150RPM/60)) / (0.000064)
  
  6250 / CADENCE_SENSOR_NUMBER_MAGNETS_X2 ≈ 156 -> 150 RPM
  
  93750 / CADENCE_SENSOR_NUMBER_MAGNETS_X2 ≈ 2344 -> 10 RPM, or 5 RPM if set to around 4600
  
  CADENCE_SENSOR_TICKS_COUNTER_MAX = x / CADENCE_SENSOR_NUMBER_MAGNETS_X2
  
  
  
  Cadence is calculated by counting how much time passes between two 
  transitions. Depending on if all transitions are measured or simply 
  transitions of the same kind it is important to adjust the calculation of 
  pedal cadence. If measuring all transistions it is also important to 
  adjust for the different spacings between the transitions.
-------------------------------------------------------------------------------*/

// master switch
#define DISPLAY_VLCD_ENABLED                                      1

#if DISPLAY_VLCD_ENABLED
// display parameters (do not edit)
#define DISPLAY_TYPE_NONE                                         0
#define DISPLAY_TYPE_VLCD5                                        1
#define DISPLAY_TYPE_VLCD6                                        2

#define DISPLAY_VLCD_ASSIST_LEVEL_0                               0x10
#define DISPLAY_VLCD_ASSIST_LEVEL_1                               0x40
#define DISPLAY_VLCD_ASSIST_LEVEL_2                               0x02
#define DISPLAY_VLCD_ASSIST_LEVEL_3                               0x04
#define DISPLAY_VLCD_ASSIST_LEVEL_4                               0x08

#define DISPLAY_VLCD_WHEEL_SPEED_ROTATION_UNIT_TIME               2.04

// display
#define DEFAULT_VALUE_DISPLAY_TYPE                                DISPLAY_TYPE_VLCD5  // DISPLAY_TYPE_NONE (TODO) | DISPLAY_TYPE_VLCD5  | DISPLAY_TYPE_VLCD6
#define DEFAULT_VALUE_DISPLAY_CONTROL_FUNCTIONS                   1
#define DEFAULT_VALUE_DISPLAY_ALWAYS_ON                           0
#define DEFAULT_VALUE_DISPLAY_MOTOR_WORKING_KEEPALIVE             1
#define DEFAULT_VALUE_DISPLAY_WHEEL_TURNING_KEEPALIVE             1

// wheel speed sensor
#define WHEEL_SPEED_SENSOR_TICKS_COUNTER_MAX                      135   // something like 200 m/h with a 6'' wheel
#define WHEEL_SPEED_SENSOR_TICKS_COUNTER_MIN                      32767 // could be a bigger number but will make for a slow detection of stopped wheel speed

// default values for bike wheel parameters
#define DEFAULT_VALUE_WHEEL_PERIMETER                             2200  // size in mm, refer: https://www.cateye.com/data/resources/Tire_size_chart_ENG_151106.pdf
#define DEFAULT_VALUE_WHEEL_SPEED_MAX                             35    // 50 km/h

// default values for battery parameters
#define DEFAULT_VALUE_BATTERY_CURRENT_MAX                         12    // 16 amps
#define DEFAULT_VALUE_BATTERY_TARGET_MAX_POWER                    600   // 500 watts
#define DEFAULT_VALUE_BATTERY_CELLS_NUMBER                        14    // 36 V = 10 | 48 V = 13 | 52 V = 14
#define DEFAULT_VALUE_BATTERY_LOW_VOLTAGE_CUT_OFF_X10             441   // 48 V battery, example: (3.0 V * 13 S) = 39.0 V -> 390
#define DEFAULT_VALUE_BATTERY_PACK_INTERNAL_RESISTANCE            130   // 48 V battery, 13S5P measured 130 milliohms

// These are now defined in motor.c, do we want them here instead?
// READ_BATTERY_VOLTAGE_FILTER_COEFFICIENT   2 
// READ_BATTERY_CURRENT_FILTER_COEFFICIENT   2

// motor type parameters (do not edit)
#define MOTOR_TYPE_48V                                            0
#define MOTOR_TYPE_36V                                            1
#define MOTOR_TYPE_48V_EXPERIMENTAL_HIGH_CADENCE_MODE             2
#define MOTOR_TYPE_36V_EXPERIMENTAL_HIGH_CADENCE_MODE             3

// motor type
#define DEFAULT_VALUE_MOTOR_TYPE                                  MOTOR_TYPE_48V 

// default value pedal torque conversion
#define DEFAULT_VALUE_PEDAL_TORQUE_PER_10_BIT_ADC_STEP_X100       67

// default values for power assist
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL_0                        0
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL_1                        6     // 0.6
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL_2                        15    // 1.5
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL_3                        21    // 2.1
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL_4                        30    // 3.0

// default values for torque assist
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_0                       0
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_1                       20
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_2                       50
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_3                       70
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_4                       90

// default values for cadence assist
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_0                      0
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_1                      40
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_2                      70
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_3                      90
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_4                      120

// default value for eMTB assist (sensitivity)
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL_0                         0
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL_1                         5
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL_2                         10    // recommended starting level
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL_3                         15
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL_4                         20

// default values for walk assist
#define DEFAULT_VALUE_WALK_ASSIST_FUNCTION_ENABLED                1     // disabled by default
#define DEFAULT_VALUE_WALK_ASSIST_FUNCTION_STATIC                 0     // adjustable or fixed assist level
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_0                         0
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_1                         25
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_2                         40
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_3                         44
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL_4                         48

// riding mode options
#define DEFAULT_VALUE_RIDING_MODE                                 POWER_ASSIST_MODE  // OFF_MODE | POWER_ASSIST_MODE | TORQUE_ASSIST_MODE | CADENCE_ASSIST_MODE | eMTB_ASSIST_MODE | CADENCE_SENSOR_CALIBRATION_MODE 
#define DEFAULT_VALUE_CADENCE_SENSOR_MODE                         STANDARD_MODE     // STANDARD_MODE | ADVANCED_MODE | CALIBRATION_MODE 

// default values for assist
#define DEFAULT_VALUE_POWER_ASSIST_LEVEL                          DEFAULT_VALUE_POWER_ASSIST_LEVEL_1
#define DEFAULT_VALUE_TORQUE_ASSIST_LEVEL                         DEFAULT_VALUE_TORQUE_ASSIST_LEVEL_1
#define DEFAULT_VALUE_CADENCE_ASSIST_LEVEL                        DEFAULT_VALUE_CADENCE_ASSIST_LEVEL_1
#define DEFAULT_VALUE_eMTB_ASSIST_LEVEL                           DEFAULT_VALUE_eMTB_ASSIST_LEVEL_1
#define DEFAULT_VALUE_WALK_ASSIST_LEVEL                           DEFAULT_VALUE_WALK_ASSIST_LEVEL_1

// default values for lights
// #define DEFAULT_VALUE_LIGHTS_MODE                              0     // NOT REQUIRED? for display only?
#define DEFAULT_VALUE_LIGHTS_ENABLED                              0  
#define DEFAULT_VALUE_LIGHTS_STATE                                0     
#define DEFAULT_VALUE_LIGHTS_CONFIGURATION                        0     // 0 = normal | 1 = flashing | etc

// throttle input or temperature control
#define DEFAULT_VALUE_OPTIONAL_ADC_FUNCTION                       NOT_IN_USE // NOT_IN_USE | TEMPERATURE_CONTROL | THROTTLE_CONTROL 

// default values for motor temperature limit function
#define DEFAULT_VALUE_MOTOR_TEMPERATURE_MIN_LIMIT                 75    // 75 degrees Celsius
#define DEFAULT_VALUE_MOTOR_TEMPERATURE_MAX_LIMIT                 85    // 85 degrees Celsius

// default value for assist without pedal rotation threshold
#define DEFAULT_VALUE_ASSIST_WITHOUT_PEDAL_ROTATION_THRESHOLD     0

// default value for motor acceleration
#define DEFAULT_VALUE_MOTOR_ACCELERATION                          0

// default values for street mode function - needs reworking
#define DEFAULT_VALUE_STREET_MODE_FUNCTION_ENABLED                1     // disabled by default
#define DEFAULT_VALUE_STREET_MODE_ENABLED_ON_STARTUP              0     
#define DEFAULT_VALUE_STREET_MODE_SPEED_LIMIT                     25    // 25 km/h 
#define DEFAULT_VALUE_STREET_MODE_POWER_LIMIT_ENABLED             0
#define DEFAULT_VALUE_STREET_MODE_POWER_LIMIT                     250   // 250 W
// TODO
// #define DEFAULT_VALUE_STREET_MODE_THROTTLE_ENABLED             0     // throttle is disabled in street mode by default
// #define DEFAULT_VALUE_STREET_MODE_CRUISE_ENABLED               0     // cruise is disabled in street mode by default

// default values for cruise function
#define DEFAULT_VALUE_CRUISE_FUNCTION_ENABLED                     0     // TO DO - disabled by default
#define DEFAULT_VALUE_CRUISE_FUNCTION_SET_TARGET_SPEED_ENABLED    0     // disabled by default
#define DEFAULT_VALUE_CRUISE_FUNCTION_TARGET_SPEED                25    // 25 km/h

// ADC battery voltage measurement
#define DEFAULT_VALUE_IMPROVED_BATTERY_VOLTAGE_ACCURACY           1
#define BATTERY_VOLTAGE_PER_10_BIT_ADC_STEP_X10000                859   // conversion value verified with with bluetooth BMS
#define BATTERY_VOLTAGE_PER_10_BIT_ADC_STEP_X1000                 86    // conversion value verified with a cheap power meter (was 87 and 0.5 V too high)
#define BATTERY_VOLTAGE_PER_10_BIT_ADC_STEP_X512                  44    // (X1000 / 1000) * 512

// ADC battery current measurement
#define BATTERY_CURRENT_PER_10_BIT_ADC_STEP_X100                  17    // conversion value verified with a cheap power meter
#define BATTERY_CURRENT_PER_10_BIT_ADC_STEP_X512                  87    // (X100 / 100) * 512 (was incorrectly 102, refer: https://git.io/JvqlL)

// battery levels
#define DISPLAY_VLCD_LI_ION_CELL_VOLTS_X100_OVERVOLTAGE           425
#define DISPLAY_VLCD_LI_ION_CELL_VOLTS_X100_UNDERVOLTAGE          300

#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_0                    300
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_1                    325
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_2                    338
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_3                    360
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_4                    378
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_5                    393
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_6                    406

#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_0                    300
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_1                    330
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_2                    344
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_3                    370
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_4                    396

// display battery levels (do not edit)
#define DISPLAY_VLCD5_BATTERY_LEVEL_0                             0x00
#define DISPLAY_VLCD5_BATTERY_LEVEL_1                             0x02
#define DISPLAY_VLCD5_BATTERY_LEVEL_2                             0x04
#define DISPLAY_VLCD5_BATTERY_LEVEL_3                             0x06
#define DISPLAY_VLCD5_BATTERY_LEVEL_4                             0x08
#define DISPLAY_VLCD5_BATTERY_LEVEL_5                             0x0A
#define DISPLAY_VLCD5_BATTERY_LEVEL_6                             0x0C

#define DISPLAY_VLCD6_BATTERY_LEVEL_0                             0x00
#define DISPLAY_VLCD6_BATTERY_LEVEL_1                             0x02
#define DISPLAY_VLCD6_BATTERY_LEVEL_2                             0x06
#define DISPLAY_VLCD6_BATTERY_LEVEL_3                             0x09
#define DISPLAY_VLCD6_BATTERY_LEVEL_4                             0x0C

#define DISPLAY_VLCD_ASSIST_LEVEL_0                               0x10
#define DISPLAY_VLCD_ASSIST_LEVEL_1                               0x40
#define DISPLAY_VLCD_ASSIST_LEVEL_2                               0x02
#define DISPLAY_VLCD_ASSIST_LEVEL_3                               0x04
#define DISPLAY_VLCD_ASSIST_LEVEL_4                               0x08

// display fault codes, are there any more needed?
#define DISPLAY_VLCD_FAULT_CODE_NO_FAULT                          0
#define DISPLAY_VLCD_FAULT_CODE_TEMPERATURE_PROTECTION            6   
#define DISPLAY_VLCD_FAULT_CODE_EBIKE_WHEEL_BLOCKED               7
#define DISPLAY_VLCD_FAULT_CODE_OVERVOLTAGE                       8

// conversion for EEPROM
#define DEFAULT_VALUE_TARGET_BATTERY_MAX_POWER_X10                (DEFAULT_VALUE_BATTERY_TARGET_MAX_POWER / 10)

#endif
#endif // _MAIN_H_