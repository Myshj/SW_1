cmake_minimum_required(VERSION 3.3)
project(SW_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Allocator.cpp Allocator.h Block.cpp Block.h)
add_executable(SW_1 ${SOURCE_FILES})