#include <main.h>

void setup()
{

  xTaskCreate(
      serial_print,        // Task function
      "Serial Print Task", // Name
      1000,                // Stack size
      NULL,                // Parameters
      1,                   // Priority
      &Serial_Print_Handle // Handle
  );

  xTaskCreate(
      gpio_blink,
      "Blink GPIO Task",
      1000,
      NULL,
      1,
      &blink_gpio_Handle);
  Serial.begin(9600);
}

void loop()
{
}