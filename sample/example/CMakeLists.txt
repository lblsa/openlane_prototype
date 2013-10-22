cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(sample)

include_directories(../../)

set (SOURCES
    main.cpp
)

add_executable(sample "${SOURCES}")

target_link_libraries(sample openlane)
