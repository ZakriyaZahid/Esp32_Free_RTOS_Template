//==============================================================================
//
//  blink_task.h
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

uint8_t PERCENTAGE = 20;
#define MAX_SPEED ((250 * PERCENTAGE) / 100)

extern void robo_task(void *pvParameters);
void pwm_setups();

extern uint8_t ROBO_DRIVE_FLAG;
extern uint8_t ROBO_DRIVE_SPEED;

unsigned int ramp_up_time = 50;
unsigned int ramp_down_time = 50;
unsigned int ramp_step_size = 10;

// Define PWM parameters
const int pwmFreq = 10000;   // PWM frequency (5kHz)
const int pwmResolution = 8; // 8-bit resolution (0-255)
const int pwmChannel1 = 0;   // PWM channel for Motor 1
const int pwmChannel2 = 1;   // PWM channel for Motor 2
const int pwmChannel3 = 2;   // PWM channel for Motor 3
const int pwmChannel4 = 3;   // PWM channel for Motor 4