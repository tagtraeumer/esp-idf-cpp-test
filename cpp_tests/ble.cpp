#include "ble.h"
#include "string.h"
#include "Serial.h"

static const char *tag = "WT Bluetooth Device";


void logUUID(const ble_uuid_t *uuid) {
    ble_uuid128_t *test = (ble_uuid128_t *) uuid;
    for (int i = 16 - 1; i >= 0; i--)
        s_print("%i", test->value[i]);
    s_println("");
}

void logUUID(ble_uuid128_t uuid) {
    for (int i = 16 - 1; i >= 0; i--)
        s_print("%i", uuid.value[i]);
    s_println("");
}


void BLEUtil::addService(const char *uuid) {
    s_println("ADD SERVICE %s", uuid);

    ble_uuid_t *bleUuid = convertUUID(uuid);
    const ble_uuid128_t *test = (ble_uuid128_t *) bleUuid;
    logUUID(*test);
    logUUID(bleUuid);

    ble_gatt_svc_def service{
            .type = BLE_GATT_SVC_TYPE_PRIMARY,
            .uuid = bleUuid,
    };

    logUUID(service.uuid);
    services.insert({service, std::list<ble_gatt_chr_def>()});
}

ble_uuid_t *BLEUtil::convertUUID(const char *uuid) {
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

BLEUtil BLESERVICE;