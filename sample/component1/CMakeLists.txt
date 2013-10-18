cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(component1)

include_directories(../../)

set (SOURCES
    main.cpp
    component.cpp
)

openlane_build_component(component1 "${SOURCES}")
