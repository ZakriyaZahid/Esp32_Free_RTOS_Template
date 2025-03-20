#include <blink_task.h>

void gpio_blink(void *pvParameters)
{
    pinMode(blink_gpio, OUTPUT);
    while (1)
    {
        digitalWrite(blink_gpio, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        digitalWrite(blink_gpio, LOW);
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}