cmake_minimum_required(VERSION 3.23)
project(ADT_Set)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADT_Set
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
