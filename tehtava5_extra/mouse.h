#pragma once

#include "device.h"


class DeviceMouse final : public Device
{
public:
    DeviceMouse() = default;
    void set_primary_button(short button);
    short primary_button() const;

private:
    short m_primary_button = 1;
};
