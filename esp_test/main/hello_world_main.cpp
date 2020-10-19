#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "BLEConnector.h"

extern "C" {
void app_main();
}

BLEConnector *ble;

void app_main() {
    printf("Hello world!\n");

    ble = BLEConnector::getInstance();
    ble->init();

    for (int i = 10; i >= 0; i--) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
