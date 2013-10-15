cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(openulane)

include_directories(include)

set(CMAKE_CXX_FLAGS "-O0 -ggdb")

add_subdirectory(src)
add_subdirectory(tests)
