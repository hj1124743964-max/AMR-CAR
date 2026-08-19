#include "app_tasks.h"

static void LedTask(void *pvParameters);
static void OledTask(void *pvParameters);

void AppTasks_Create(void)
{
    xTaskCreate(LedTask,
    "LedTask",
    128,
    NULL,
    2,
    NULL
    );

    xTaskCreate(OledTask,
    "OledTask",
    128,
    NULL,
    2,
    NULL
    );
}

static void LedTask(void *argument)
{
    (void)argument;

    while (1)
    {
        GPIO_ResetBits(GPIOF, GPIO_Pin_9);
        vTaskDelay(500);
    }
}

static void OledTask(void *argument)
{
    (void)argument;

    while (1)
    {
        OLED_Clear();
        OLED_ShowString(0, 0, "FreeRTOS", 16, 1);
        OLED_Refresh();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}