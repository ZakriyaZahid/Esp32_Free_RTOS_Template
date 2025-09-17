//==============================================================================
//
//  main.cpp
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
#include <main.h>

void setup()
{

  xTaskCreate(
      x_stepp_motor_task,   // Task function
      "x_stepp_motor_task", // Name
      1000,                 // Stack size
      NULL,                 // Parameters
      1,                    // Priority
      &x_stepp_motor_Handle // Handle
  );

  xTaskCreate(
      y_stepp_motor_task,
      "y_stepp_motor_task",
      1000,
      NULL,
      1,
      &y_stepp_motor_Handle);

  xTaskCreate(
      robo_task,
      "robo_task",
      1000,
      NULL,
      1,
      &robo_Handle);

  set_pins_mode();
  initialize_pins_states();
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    cmd = Serial.readStringUntil('\n');
    // Read the incoming data
    // byte incomingByte = Serial.read();
    // char c = (char)incomingByte;
    // Serial.println(c);
    digitalWrite(built_in_led, !digitalRead(built_in_led));
    // digitalWrite(built_in_led, HIGH);

    // Check for newline as the end of a string

    stepper_handler(cmd);
    robo_handler(cmd);
    misc_cmd_handler(cmd);

    //   if ()
    //   {
    //     // Serial.printf("Shahzad %d \r\n", motor_drive_flag);
    //     if (c == 'i')
    //     {
    //     }
    //     else if (c == 'a')
    //     {
    //     }
    //   }

    //   else
    //   {
    //   }
    // }
  }
  // Serial.println("serial task is Running");
  vTaskDelay(10 / portTICK_PERIOD_MS);
}

void set_pins_mode()
{
  pinMode(x_stepp_motor_step, OUTPUT);
  pinMode(x_stepp_motor_dir, OUTPUT);

  pinMode(y_stepp_motor_step, OUTPUT);
  pinMode(y_stepp_motor_dir, OUTPUT);

  pinMode(z_stepp_motor_step, OUTPUT);
  pinMode(z_stepp_motor_dir, OUTPUT);

  pinMode(robo_motor_A_pin_1, OUTPUT);
  pinMode(robo_motors_A_pin_2, OUTPUT);
  pinMode(robo_motors_B_pin_1, OUTPUT);
  pinMode(robo_motors_B_pin_2, OUTPUT);

  pinMode(stepp_motors_conf_1, OUTPUT);
  pinMode(stepp_motors_conf_2, OUTPUT);
  pinMode(stepp_motors_conf_3, OUTPUT);

  pinMode(built_in_led, OUTPUT);
}

void initialize_pins_states()
{
  digitalWrite(x_stepp_motor_step, LOW);
  digitalWrite(x_stepp_motor_dir, LOW);

  digitalWrite(y_stepp_motor_step, LOW);
  digitalWrite(y_stepp_motor_dir, LOW);

  digitalWrite(z_stepp_motor_step, LOW);
  digitalWrite(z_stepp_motor_dir, LOW);

  digitalWrite(robo_motor_A_pin_1, LOW);
  digitalWrite(robo_motors_A_pin_2, LOW);
  digitalWrite(robo_motors_B_pin_1, LOW);
  digitalWrite(robo_motors_B_pin_2, LOW);

  digitalWrite(stepp_motors_conf_1, LOW);
  digitalWrite(stepp_motors_conf_2, LOW);
  digitalWrite(stepp_motors_conf_3, LOW);

  digitalWrite(built_in_led, LOW);
}

void set_motors_conf(bool a, bool b, bool c)
{
  digitalWrite(stepp_motors_conf_1, a);
  digitalWrite(stepp_motors_conf_2, b);
  digitalWrite(stepp_motors_conf_3, c);
}

void stepper_handler(String &cmd)
{
  if (cmd == "JB1_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Anticlockwise;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Anticlockwise;
  }
  else if (cmd == "JB1_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB2_1")
  {
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Anticlockwise;
  }
  else if (cmd == "JB2_0")
  {
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB3_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Clockwise;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Anticlockwise;
  }
  else if (cmd == "JB3_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB4_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Anticlockwise;
  }
  else if (cmd == "JB4_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB5_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  else if (cmd == "JB5_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB6_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Clockwise;
  }
  else if (cmd == "JB6_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB7_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Anticlockwise;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Clockwise;
  }
  else if (cmd == "JB7_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB8_1")
  {
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Clockwise;
  }
  else if (cmd == "JB8_0")
  {
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
  if (cmd == "JB9_1")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_Clockwise;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_Clockwise;
  }
  else if (cmd == "JB9_0")
  {
    X_STEPP_MOTOR_FLAG = X_STEPP_MOTOR_STOP;
    Y_STEPP_MOTOR_FLAG = Y_STEPP_MOTOR_STOP;
  }
}

void robo_handler(String &cmd)
{
  if (cmd == "RB1_1")
  {
    ROBO_DRIVE_FLAG = ROBO_FORWARD;
  }
  else if (cmd == "RB1_0")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
  if (cmd == "RB2_1")
  {
    ROBO_DRIVE_FLAG = ROBO_Anticlockwise;
  }
  else if (cmd == "RB2_0")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
  if (cmd == "RB3_1")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
  else if (cmd == "RB3_0")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
  if (cmd == "RB4_1")
  {
    ROBO_DRIVE_FLAG = ROBO_Clockwise;
  }
  else if (cmd == "RB4_0")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
  if (cmd == "RB5_1")
  {
    ROBO_DRIVE_FLAG = ROBO_REVERSE;
  }
  else if (cmd == "RB5_0")
  {
    ROBO_DRIVE_FLAG = ROBO_STOP;
  }
}

void misc_cmd_handler(String &cmd)
{
  if (cmd == "B1_1")
  {
  }
  else if (cmd == "B1_0")
  {
  }
  if (cmd == "B2_1")
  {
  }
  else if (cmd == "B2_0")
  {
  }
  if (cmd == "B3_1")
  {
  }
  else if (cmd == "B3_0")
  {
  }
  if (cmd == "B4_1")
  {
  }
  else if (cmd == "B4_0")
  {
  }
  if (cmd == "B5_1")
  {
  }
  else if (cmd == "B5_0")
  {
  }
  if (cmd == "B6_1")
  {
  }
  else if (cmd == "B6_0")
  {
  }
}

// if (debug_enable == 1)
// {
//   Serial.println("ramp_up_time_edit_enabled");
// }