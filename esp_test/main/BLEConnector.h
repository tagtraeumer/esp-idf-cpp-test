//
// Created by lieve on 12/06/2020.
//

#ifndef WATERTHING_IDF_BLECONNECTOR_H
#define WATERTHING_IDF_BLECONNECTOR_H

#include "string"

#define wtServiceUUID       "8d50CAD0-0000-43c2-a33e-00f937249838"

class BLEConnector {
public:
    static BLEConnector *getInstance();

private:
    static BLEConnector *instance;

    BLEConnector() = default;

public:
    void init();

};

#endif //WATERTHING_IDF_BLECONNECTOR_H
