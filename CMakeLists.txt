cmake_minimum_required(VERSION 3.31)
project(RT)

set(CMAKE_CXX_STANDARD 20)

add_executable(RT main.cpp
        Vec3.cpp
        Vec3.h
        Color.cpp
        Color.h
        Color.cpp)
