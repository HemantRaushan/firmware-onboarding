#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface(int8_t chipSelect)
    : sensor(chipSelect)
{
}

bool BMESPIInterface::begin()
{
    return sensor.begin();
}

float BMESPIInterface::readTemperature()
{
    return sensor.readTemperature();
}