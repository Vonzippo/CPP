cmake_minimum_required(VERSION 3.6)
project(string_to_char)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(string_to_char ${SOURCE_FILES})