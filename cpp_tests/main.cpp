#include <iostream>
#include "Serial.h"
#include "uuid.h"
#include "ble.h"

#define wtServiceUUID       "8d50CAD0-0000-43c2-a33e-00f937249838"
int main() {

    printf("Hello world!\n");

    BLESERVICE.addService(wtServiceUUID);


    return 0;
}
