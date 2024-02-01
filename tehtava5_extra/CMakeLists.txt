cmake_minimum_required(VERSION 3.25)
project(tehtava5_extra)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(tehtava5_extra
    main.cpp
    ui.cpp
    device.cpp
    mouse.cpp
    display.cpp
    touchpad.cpp)
