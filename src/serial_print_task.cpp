#include <serial_print_task.h>

void serial_print(void *pvParameters)
{
    while (1)
    {
        Serial.println("serial_print task is Running");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
