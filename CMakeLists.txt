cmake_minimum_required(VERSION 3.13)
project(Employee)

set(CMAKE_CXX_STANDARD 11)

add_executable(Employee src/main.cpp src/employee.cpp src/employee.h)