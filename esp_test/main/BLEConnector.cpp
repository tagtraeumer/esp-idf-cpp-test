#include "BLEConnector.h"
#include "ble.h"
#include "Serial.h"

BLEConnector *BLEConnector::instance = 0;

BLEConnector *BLEConnector::getInstance() {
    if (instance == 0) {
        instance = new BLEConnector();
    }
    return instance;
}

void BLEConnector::init() {
    s_println("Init BLE");

    // Create the BLE Service
    BLESERVICE.addService(wtServiceUUID);

}
