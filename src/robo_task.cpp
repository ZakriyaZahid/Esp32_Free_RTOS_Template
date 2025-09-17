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
#include <robo_task.h>

void robo_task(void *pvParameters)
{
    pwm_setups();
    ROBO_DRIVE_SPEED = 50;
    while (1)
    {
        // Serial.println("robo task is Running");
        if (ROBO_DRIVE_FLAG == ROBO_FORWARD)
        {
        }
        else if (ROBO_DRIVE_FLAG == ROBO_REVERSE)
        {
        }
        else if (ROBO_DRIVE_FLAG == ROBO_Clockwise)
        {
        }
        else if (ROBO_DRIVE_FLAG == ROBO_Clockwise)
        {
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void robo_operate(bool dir, uint32_t speed)
{

    digitalWrite(x_stepp_motor_dir, dir);
    while (ROBO_DRIVE_FLAG != ROBO_STOP)
    {
    }
}

void pwm_setups()
{
    ledcSetup(pwmChannel1, pwmFreq, pwmResolution);
    ledcAttachPin(robo_motor_A_pin_1, pwmChannel1);

    ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
    ledcAttachPin(robo_motors_A_pin_2, pwmChannel2);

    ledcSetup(pwmChannel3, pwmFreq, pwmResolution);
    ledcAttachPin(robo_motors_B_pin_1, pwmChannel1);

    ledcSetup(pwmChannel4, pwmFreq, pwmResolution);
    ledcAttachPin(robo_motors_B_pin_2, pwmChannel2);
}

void robo_drive_forward(void)
{

    digitalWrite(robo_motor_A_pin_1, LOW);
    digitalWrite(robo_motors_A_pin_2, HIGH);

    digitalWrite(robo_motors_B_pin_1, LOW);
    digitalWrite(robo_motors_B_pin_2, HIGH);

    int16_t i = 0;

    for (; i < MAX_SPEED; i += ramp_step_size)
    {
        ledcWrite(pwmChannel2, i);
        ledcWrite(pwmChannel4, i);
        vTaskDelay(ramp_up_time / portTICK_PERIOD_MS);
    }

    while (ROBO_DRIVE_FLAG == ROBO_FORWARD)
    {
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
    for (; i > 0; i -= ramp_step_size)
    {
        ledcWrite(pwmChannel2, i);
        ledcWrite(pwmChannel4, i);
        // vTaskDelay(ramp_down_time - 20/ portTICK_PERIOD_MS);
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}