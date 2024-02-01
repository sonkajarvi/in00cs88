#include "mouse.h"


void DeviceMouse::set_primary_button(short button)
{
    m_primary_button = button;
}


short DeviceMouse::primary_button() const
{
    return m_primary_button;
}
