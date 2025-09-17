//==============================================================================
//
//  serial_print_task.cpp
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
#include <y_motor_task.h>

void y_stepp_motor_task(void *pvParameters)
{
    Y_STEPP_MOTOR_SPEED = 50;
    while (1)
    {
        // Serial.println("y motor task is Running");
        if (Y_STEPP_MOTOR_FLAG == Y_STEPP_MOTOR_Anticlockwise)
        {
            y_stepp_motor_operate(1, Y_STEPP_MOTOR_SPEED / 500);
        }
        else if (Y_STEPP_MOTOR_FLAG == Y_STEPP_MOTOR_Clockwise)
        {
            y_stepp_motor_operate(0, Y_STEPP_MOTOR_SPEED / 500);
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void y_stepp_motor_operate(bool dir, uint32_t speed)
{

    digitalWrite(y_stepp_motor_dir, dir);
    while (Y_STEPP_MOTOR_FLAG != X_STEPP_MOTOR_STOP)
    {
        digitalWrite(y_stepp_motor_step, HIGH);
        vTaskDelay((Y_STEPP_MOTOR_SPEED / speed) / portTICK_PERIOD_MS);
        digitalWrite(y_stepp_motor_step, LOW);
        vTaskDelay((Y_STEPP_MOTOR_SPEED / speed) / portTICK_PERIOD_MS);
    }
    digitalWrite(y_stepp_motor_step, LOW);
}
