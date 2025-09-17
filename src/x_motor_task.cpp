//==============================================================================
//
//  blink_task.cpp
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
#include <x_motor_task.h>

void x_stepp_motor_task(void *pvParameters)
{
    X_STEPP_MOTOR_SPEED = 50;
    while (1)
    {
        // Serial.println("x motor task is Running");
        if (X_STEPP_MOTOR_FLAG == X_STEPP_MOTOR_Anticlockwise)
        {
            x_stepp_motor_operate(1, X_STEPP_MOTOR_SPEED / 500);
        }
        else if (X_STEPP_MOTOR_FLAG == X_STEPP_MOTOR_Clockwise)
        {
            x_stepp_motor_operate(0, X_STEPP_MOTOR_SPEED / 500);
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void x_stepp_motor_operate(bool dir, uint32_t speed)
{

    digitalWrite(x_stepp_motor_dir, dir);
    while (X_STEPP_MOTOR_FLAG != X_STEPP_MOTOR_STOP)
    {
        digitalWrite(x_stepp_motor_step, HIGH);
        vTaskDelay((X_STEPP_MOTOR_SPEED / speed) / portTICK_PERIOD_MS);
        digitalWrite(x_stepp_motor_step, LOW);
        vTaskDelay((X_STEPP_MOTOR_SPEED / speed) / portTICK_PERIOD_MS);
    }
    digitalWrite(x_stepp_motor_step, LOW);
}
