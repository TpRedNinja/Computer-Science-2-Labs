cmake_minimum_required(VERSION 4.0)
project(Project_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_1 main.cpp Random_Password_Generator.cpp Random_Password_Generator.h
        Login.h
        Rock_Paper_Scissors.h
        Login.cpp
        Rock_Paper_Scissors.cpp)
