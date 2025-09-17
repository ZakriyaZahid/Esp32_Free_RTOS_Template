//==============================================================================
//
//  enum.h
//
//
//==============================================================================
//  FILE INFORMATION
//==============================================================================
//
//  Source:
//
//  Project:    Esp32 RTOS Template
//
//  Author:     Muhammad Zakriya
//
//  Date:       24/13/2025
//
//  Revision:   1.0
//
//==============================================================================
//  FILE DESCRIPTION
//==============================================================================

//==============================================================================
//  INCLUDES
//==============================================================================

#include <Arduino.h>
#define built_in_led 2

#define x_stepp_motor_step 14
#define x_stepp_motor_dir 21

#define y_stepp_motor_step 27
#define y_stepp_motor_dir 19

#define z_stepp_motor_step 26
#define z_stepp_motor_dir 18

#define stepp_motors_conf_1 32
#define stepp_motors_conf_2 33
#define stepp_motors_conf_3 25

#define robo_motor_A_pin_1 18
#define robo_motors_A_pin_2 32
#define robo_motors_B_pin_1 33
#define robo_motors_B_pin_2 25

enum X_sMOTOR_DRIVE
{
    X_STEPP_MOTOR_STOP = 0,
    X_STEPP_MOTOR_Clockwise = 1,
    X_STEPP_MOTOR_Anticlockwise = 2
};

enum Y_sMOTOR_DRIVE
{
    Y_STEPP_MOTOR_STOP = 0,
    Y_STEPP_MOTOR_Clockwise = 1,
    Y_STEPP_MOTOR_Anticlockwise = 2
};

enum Z_sMOTOR_DRIVE
{
    Z_STEPP_MOTOR_STOP = 0,
    Z_STEPP_MOTOR_Clockwise = 1,
    Z_STEPP_MOTOR_Anticlockwise = 2
};

enum ROBO_DRIVE
{
    ROBO_STOP = 0,
    ROBO_FORWARD = 1,
    ROBO_REVERSE = 2,
    ROBO_Clockwise = 3,
    ROBO_Anticlockwise = 4,
    ROBO_LEFT = 5,
    ROBO_RIGHT = 6,
    ROBO_REVERSE_LEFT = 7,
    ROBO_REVERSE_RIGHT = 8
};


