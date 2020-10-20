#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "host/ble_uuid.h"
#include "Serial.h"
#include <cstring>

extern "C" {
void app_main();
}

#define wtServiceUUID       "8d50CAD0-0000-43c2-a33e-00f937249838"

void logUUID(const ble_uuid_t *uuid) {
    ble_uuid128_t *test = (ble_uuid128_t *) uuid;
    for (int i = 16 - 1; i >= 0; i--)
        s_print("%02x", test->value[i]);
    s_println("");
}

void logUUID(ble_uuid128_t uuid) {
    for (int i = 16 - 1; i >= 0; i--)
        s_print("%02x", uuid.value[i]);
    s_println("");
}

ble_uuid_t *convertUUID(const char *uuid) {
    s_println("convert uuid %s", uuid);
    ble_uuid_t *bleUuid;
    if (strlen(uuid) == 36) {
        ble_uuid128_t temp;
        temp.u.type = BLE_UUID_TYPE_128;

        int n = 0;
        for (int i = 0; i < strlen(uuid);) {
            if (uuid[i] == '-')
                i++;
            std::string s;
            s += uuid[i];
            s += uuid[i + 1];
            uint8_t x = std::stoul(s, nullptr, 16);
            temp.value[15 - n] = x;
            n++;
            i += 2;
        }
        bleUuid = ((ble_uuid_t *) (&temp));
    }
    s_print("-> to ");
    logUUID(bleUuid);

    return bleUuid;
}

void app_main() {

    ble_uuid_t *uuid = convertUUID(wtServiceUUID);
    logUUID(uuid);

    for (int i = 10; i >= 0; i--) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
