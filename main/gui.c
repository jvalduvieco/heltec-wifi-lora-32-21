#include <sys/cdefs.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "ssd1306.h"
#include "font8x8_basic.h"

_Noreturn void dummy_gui_task(void *display_handler) {
    SSD1306_t *dev = display_handler;
    while (1) {
        ssd1306_clear_screen(dev, false);
        ssd1306_contrast(dev, 0xff);
        ssd1306_display_text_x3(dev, 0, "Hello", 5, false);
        vTaskDelay(3000 / portTICK_PERIOD_MS);

        ssd1306_display_text(dev, 0, "SSD1306 128x64", 14, false);
        ssd1306_display_text(dev, 1, "ABCDEFGHIJKLMNOP", 16, false);
        ssd1306_display_text(dev, 2, "abcdefghijklmnop", 16, false);
        ssd1306_display_text(dev, 3, "Hello World!!", 13, false);
        //ssd1306_clear_line(&dev, 4, true);
        //ssd1306_clear_line(&dev, 5, true);
        //ssd1306_clear_line(&dev, 6, true);
        //ssd1306_clear_line(&dev, 7, true);
        ssd1306_display_text(dev, 4, "SSD1306 128x64", 14, true);
        ssd1306_display_text(dev, 5, "ABCDEFGHIJKLMNOP", 16, true);
        ssd1306_display_text(dev, 6, "abcdefghijklmnop", 16, true);
        ssd1306_display_text(dev, 7, "Hello World!!", 13, true);
        // Fade Out
        ssd1306_fadeout(dev);
    }

}