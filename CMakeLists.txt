cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(openlane)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/OpenLane.cmake)

include_directories(include)

add_subdirectory(src)
add_subdirectory(sample)
add_subdirectory(tests)
