#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMEI2CInterface sensorInterface;
LEDController ledController;
bool sensorReady = false;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_SPEED);
    pinMode(LED_BUILTIN, OUTPUT);

    sensorReady = sensorInterface.begin();

    if (!sensorReady)
    {
        Serial.println("BME280 initialization failed.");
    }
}

void loop()
{
    if (!sensorReady)
    {
        return;
    }

    static unsigned long lastTemperatureRead = 0;
    static unsigned long lastLedChange = 0;
    static unsigned long blinkInterval = 1000;
    static bool ledOn = false;

    unsigned long now = millis();

    if (now - lastTemperatureRead >= BMEConstants::TEMPERATURE_READ_INTERVAL_MS)
    {
        lastTemperatureRead = now;

        float temperature = sensorInterface.readTemperature();

        if (isnan(temperature))
        {
            Serial.println("Invalid temperature reading.");
            return;
        }

        Serial.print("Temperature (C): ");
        Serial.println(temperature);

        blinkInterval = ledController.getBlinkInterval(temperature);
    }

    if (now - lastLedChange >= blinkInterval)
    {
        lastLedChange = now;
        ledOn = !ledOn;
        digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
    }
}