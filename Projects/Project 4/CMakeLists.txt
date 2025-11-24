cmake_minimum_required(VERSION 4.0)
project(Project_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_4 main.cpp
        Book.cpp
        Book.h
        Customer.cpp
        Customer.h)
