cmake_minimum_required(VERSION 3.6)
project(ArrayClass)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ArrayClass ${SOURCE_FILES})