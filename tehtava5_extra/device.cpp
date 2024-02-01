#include "device.h"


void Device::set_device_id(short device_id)
{
    m_device_id = device_id;
}


short Device::device_id() const
{
    return m_device_id;
}
