cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(algorithm_c)

include_directories(../../)

set (SOURCES
    main.cpp
    algo.cpp
)

openlane_build_component(algorithm_c "${SOURCES}")
