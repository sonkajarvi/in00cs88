#pragma once


class Device
{
public:
    Device() = default;
    void set_device_id(short id);
    short device_id() const;

protected:
    short m_device_id = 0;
};
