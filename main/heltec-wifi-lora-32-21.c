#include <sys/cdefs.h>
#include <string.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "ssd1306.h"
#include "gui.h"
#include "wifi.h"

#define TAG "main"

_Noreturn void app_main(void) {
    SSD1306_t dev;

    ESP_LOGI(TAG, "INTERFACE is i2c");
    ESP_LOGI(TAG, "CONFIG_SDA_GPIO=%d", CONFIG_SDA_GPIO);
    ESP_LOGI(TAG, "CONFIG_SCL_GPIO=%d", CONFIG_SCL_GPIO);
    ESP_LOGI(TAG, "CONFIG_RESET_GPIO=%d", CONFIG_RESET_GPIO);
    i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
    ESP_LOGI(TAG, "Panel is 128x64");
    ssd1306_init(&dev, 128, 64);
    start_wifi();
    xTaskCreate(dummy_gui_task, "dymmy_gui", 2048, (void *) &dev, 1, NULL);


#if 0
    // Fade Out
    for(int contrast=0xff;contrast>0;contrast=contrast-0x20) {
        ssd1306_contrast(&dev, contrast);
        vTaskDelay(40);
    }
#endif
    while (1) {
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
