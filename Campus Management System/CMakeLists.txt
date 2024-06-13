cmake_minimum_required(VERSION 3.28)
project(assigment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(assigment2 main.cpp
        room.cpp
        room.h
        office.h
        office.cpp
        classroom.cpp
        classroom.h
        building.cpp
        building.h
        university.cpp
        university.h)
