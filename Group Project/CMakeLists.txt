cmake_minimum_required(VERSION 4.0)
project(Group_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Group_Project main.cpp
        D_PizzaOrders.cpp
        D_PizzaOrders.h
        Pizza.cpp
        Pizza.h)
