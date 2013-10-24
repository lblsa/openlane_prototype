cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(sample)

include_directories(../../)

set (SOURCES
    main.cpp
)

add_executable(sample "${SOURCES}")

target_link_libraries(sample openlane)

add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sample.sh
    COMMAND cp ${CMAKE_SOURCE_DIR}/scripts/sample.sh ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Copy sample.sh..."
)

add_custom_target (sample.sh ALL
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sample.sh
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

