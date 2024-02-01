#include "ui.h"

#include <iostream>

#define IF_INVALID(x)                                   \
    do {                                                \
    if (std::cin.fail()) {                              \
        std::cin.clear();                               \
        std::cin.ignore(32767, '\n');                   \
        std::cout << "Invalid choice!\n" << std::endl;  \
        goto x;                                         \
    }} while(0);

#define WAIT_FOR_INPUT() do{getc(stdin);;putc(0,stdout);getc(stdin);}while(0);


DeviceUI::DeviceUI()
{
    m_mouse = new DeviceMouse;
    m_display = new DeviceDisplay;
    m_touchpad = new DeviceTouchpad;
}


DeviceUI::~DeviceUI()
{
    delete m_mouse;
    delete m_display;
    delete m_touchpad;
}


void DeviceUI::show_menu()
{
repeat:
    std::cout << "DEVICE MENU" << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << "1: Set Mouse Information" << std::endl;
    std::cout << "2: Set Touchpad Information" << std::endl;
    std::cout << "3: Set Display Information" << std::endl;
    std::cout << "4: Show Devices Information" << std::endl;
    std::cout << "5: Finish" << std::endl;


    std::cout << "\nChoose: ";
    int choice = 0;
    std::cin >> choice;

    IF_INVALID(repeat);

    switch (choice) {
    case 1:
        set_mouse_info();
        break;
    case 2:
        set_touchpad_info();
        break;
    case 3:
        set_display_info();
        break;
    case 4:
        show_device_info();
        break;
    case 5:
        std::cout << "Goodbye!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice!\n" << std::endl;
        goto repeat;
    }
}


void DeviceUI::set_mouse_info()
{
    std::cout << "\nSET MOUSE INFORMATION" << std::endl; 
    std::cout << "=====================" << std::endl;

id:
    short id = 0;
    std::cout << "Set Mouse Device ID: ";
    std::cin >> id;

    IF_INVALID(id);

button:
    short button = 0;
    std::cout << "Set Mouse Primary Button (1-2): ";
    std::cin >> button;

    IF_INVALID(button);
    if (button < 1 || button > 2) {
        std::cout << "Invalid choice!\n" << std::endl;
        goto button;
    }

    m_mouse->set_device_id(id);
    m_mouse->set_primary_button(button);

    std::cout << std::endl;
    show_menu();
}


void DeviceUI::set_display_info()
{
    std::cout << "\nSET DISPLAY INFORMATION" << std::endl; 
    std::cout << "=======================" << std::endl;

id:
    short id = 0;
    std::cout << "Set Display Device ID: ";
    std::cin >> id;
    
    IF_INVALID(id);

resolution:
    short resolution = 0;
    std::cout << "Set Display Resolution (1-10): ";
    std::cin >> resolution;
    
    IF_INVALID(resolution);
    if (resolution < 1 || resolution > 10) {
        std::cout << "Invalid choice!\n" << std::endl;
        goto resolution;
    }

    m_display->set_device_id(id);
    m_display->set_resolution(resolution);

    std::cout << std::endl;
    show_menu();
}


void DeviceUI::set_touchpad_info()
{
    std::cout << "\nSET TOUCHPAD INFORMATION" << std::endl; 
    std::cout << "========================" << std::endl;

id:
    short id = 0;
    std::cout << "Set Touchpad Device ID: ";
    std::cin >> id;
    
    IF_INVALID(id);

sensitivity:
    short sensitivity = 0;
    std::cout << "Set Touchpad Sensitivity (1-5): ";
    std::cin >> sensitivity;
    
    IF_INVALID(sensitivity);
    if (sensitivity < 1 || sensitivity > 5) {
        std::cout << "Invalid choice!\n" << std::endl;
        goto sensitivity;
    }

    m_touchpad->set_device_id(id);
    m_touchpad->set_sensitivity(sensitivity);

    std::cout << std::endl;
    show_menu();
}


void DeviceUI::show_device_info()
{
    std::cout << "\nDEVICE INFORMATION" << std::endl; 
    std::cout << "===================" << std::endl;
    std::cout << "Mouse Device ID:\t" << m_mouse->device_id() << std::endl;
    std::cout << "Mouse Primary Button:\t" << m_mouse->primary_button() << std::endl;
    std::cout << "Touchpad Device ID:\t" << m_touchpad->device_id() << std::endl;
    std::cout << "Touchpad Sensitivity:\t" << m_touchpad->sensitivity() << std::endl;
    std::cout << "Display Device ID:\t" << m_display->device_id() << std::endl;
    std::cout << "Display Resolution:\t" << m_display->resolution() << std::endl;

    std::cout << "\n(Enter to continue..)";
    WAIT_FOR_INPUT();
    std::cout << std::endl;
    show_menu();
}
