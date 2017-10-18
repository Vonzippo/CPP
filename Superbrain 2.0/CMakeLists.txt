cmake_minimum_required(VERSION 3.6)
project(Superbrain_2_0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Superbrain_2_0 ${SOURCE_FILES})