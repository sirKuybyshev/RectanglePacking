cmake_minimum_required(VERSION 3.16)
project(RectanglePacking)

set(CMAKE_CXX_STANDARD 20)

add_executable(RectanglePacking main.cpp Rectangle.cpp Rectangle.h Coordinates.cpp Coordinates.h Bin.cpp Bin.h)