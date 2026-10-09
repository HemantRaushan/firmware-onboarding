#include "LEDController.h"

unsigned long LEDController::getBlinkInterval(float temperature)
{
    if (temperature <= 0.0f)
    {
        return 1000;
    }

    if (temperature >= 50.0f)
    {
        return 100;
    }

    return static_cast<unsigned long>(1000.0f - 18.0f * temperature);
}