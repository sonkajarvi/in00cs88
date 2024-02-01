#pragma once

#include "mouse.h"
#include "display.h"
#include "touchpad.h"


class DeviceUI final
{
public:
    DeviceUI();
    ~DeviceUI();
    void show_menu();
    void set_mouse_info();
    void set_display_info();
    void set_touchpad_info();
    void show_device_info();

private:
    DeviceMouse *m_mouse;
    DeviceDisplay *m_display;
    DeviceTouchpad *m_touchpad;
};
