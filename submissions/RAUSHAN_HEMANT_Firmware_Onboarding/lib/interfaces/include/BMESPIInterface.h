#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface(int8_t chipSelect);

    bool begin();
    float readTemperature();

private:
    Adafruit_BME280 sensor;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;