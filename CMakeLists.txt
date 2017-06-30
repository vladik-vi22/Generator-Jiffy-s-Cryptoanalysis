cmake_minimum_required(VERSION 3.7)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp linear_register.cpp linear_register.h)
add_executable(lab3 ${SOURCE_FILES})