cmake_minimum_required(VERSION 4.0)
project(Chapter_14_example_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chapter_14_example_1 main.cpp
        Passenger.cpp
        Passenger.h
        Car.cpp
        Car.h)
