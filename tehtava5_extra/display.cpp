#include "display.h"


void DeviceDisplay::set_resolution(short resolution)
{
    m_resolution = resolution;
}


short DeviceDisplay::resolution() const
{
    return m_resolution;
}
