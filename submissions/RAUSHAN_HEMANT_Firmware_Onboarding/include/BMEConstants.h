#pragma once

namespace BMEConstants
{
    constexpr unsigned long SERIAL_SPEED = 115200;
    constexpr unsigned long TEMPERATURE_READ_INTERVAL_MS = 1000;
}

// constexpr means fixed constants
// print temp faster make 1000 to 500 for twice per second