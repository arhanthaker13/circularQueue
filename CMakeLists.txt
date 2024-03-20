cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(circularQueue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(run
        circularQueue.cpp
        circularQueue.hpp
        main.cpp)