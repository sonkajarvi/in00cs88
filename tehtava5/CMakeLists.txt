cmake_minimum_required(VERSION 3.25)
project(tehtava5)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(tehtava5
    main.cpp
    asunto.cpp
    kerros.cpp
    katutaso.cpp
    kerrostalo.cpp)
