cmake_minimum_required(VERSION 4.0)
project(Food_Class_example)

set(CMAKE_CXX_STANDARD 20)

add_executable(Food_Class_example main.cpp
        Food.cpp
        Food.h)
