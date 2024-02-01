#include "touchpad.h"


void DeviceTouchpad::set_sensitivity(short sensitivity)
{
    m_sensitivity = sensitivity;
}


short DeviceTouchpad::sensitivity() const
{
    return m_sensitivity;
}
