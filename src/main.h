//==============================================================================
//
//  main.h
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
#include <enum.h>

#define blink_gpio 4
bool debug_enable = 0;

TaskHandle_t x_stepp_motor_Handle;
TaskHandle_t y_stepp_motor_Handle;
TaskHandle_t robo_Handle;

void x_stepp_motor_task(void *pvParameters);
void y_stepp_motor_task(void *pvParameters);
void robo_task(void *pvParameters);

void set_pins_mode();
void initialize_pins_states();
void set_motors_conf(bool, bool, bool);

void stepper_handler(String &);
void robo_handler(String &);
void misc_cmd_handler(String &);

uint8_t X_STEPP_MOTOR_FLAG = 0;
uint8_t Y_STEPP_MOTOR_FLAG = 0;
uint8_t Z_STEPP_MOTOR_FLAG = 0;
uint8_t ROBO_DRIVE_FLAG = 0;
String cmd;

uint8_t X_STEPP_MOTOR_SPEED = 0;
uint8_t Y_STEPP_MOTOR_SPEED = 0;
uint8_t Z_STEPP_MOTOR_SPEED = 0;
uint8_t ROBO_DRIVE_SPEED = 0;
