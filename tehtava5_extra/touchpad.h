#pragma once

#include "device.h"


class DeviceTouchpad final : public Device
{
public:
    DeviceTouchpad() = default;
    void set_sensitivity(short sensitivity);
    short sensitivity() const;

private:
    short m_sensitivity = 3;
};
