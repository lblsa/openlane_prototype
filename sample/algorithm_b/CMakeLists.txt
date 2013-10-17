cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(algorithm_b)

include_directories(../../)

openlane_build_component(algorithm_b main.c algo.c)
