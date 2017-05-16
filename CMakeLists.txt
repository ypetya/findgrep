cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(findgrep.cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(findgrep findgrep.cpp
        WalkDirectoryTree.cpp WalkDirectoryTree.h
        MeasureRuntime.cpp MeasureRuntime.h)
