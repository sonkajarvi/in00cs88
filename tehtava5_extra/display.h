#pragma once

#include "device.h"


class DeviceDisplay final : public Device
{
public:
    DeviceDisplay() = default;
    void set_resolution(short resolution);
    short resolution() const;

private:
    short m_resolution = 1;
};
