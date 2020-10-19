#ifndef WATERTHING_IDF_BLE_H
#define WATERTHING_IDF_BLE_H

#include "string"
#include "list"
#include "uuid.h"
#include "gatt.h"

#include <unordered_map>

static size_t hashUuid(const ble_uuid128_t &uuid) {
    const char *value = (char *) &uuid.value;
    size_t result = 0;
    size_t s = 16;
    const size_t prime = 31;
    for (size_t i = 0; i < s; ++i) {
        result = value[i] + (result * prime);
    }
    return result;
}


class ServiceHash {
public:
    size_t operator()(const ble_gatt_svc_def &p) const {
        ble_uuid128_t uuid = (ble_uuid128_t &&) p.uuid;
        size_t result = hashUuid(uuid);
        return result;
    }
};

class ServiceEqual {
public:
    bool operator()(ble_gatt_svc_def const &t1, ble_gatt_svc_def const &t2) const {
        ble_uuid128_t uuid1 = (ble_uuid128_t &&) t1.uuid;
        ble_uuid128_t uuid2 = (ble_uuid128_t &&) t2.uuid;
        return uuid1.value == uuid2.value;
    }
};

class BLEUtil {
private:

    std::unordered_map<ble_gatt_svc_def, std::list<ble_gatt_chr_def>, ServiceHash, ServiceEqual> services;

    ble_uuid_t *convertUUID(const char *uuid);


public:
    BLEUtil() {
    };

    void addService(const char *uuid);

};


extern BLEUtil BLESERVICE;


#endif //WATERTHING_IDF_BLE_H
