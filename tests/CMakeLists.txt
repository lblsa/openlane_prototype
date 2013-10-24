add_executable(tests 
    main.cpp 
    module_test.cpp
    module_xml_parser_test.cpp
    component_provider_test.cpp
    )

target_link_libraries(tests openlane gtest)

add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/component_a.xml
    COMMAND cp ${CMAKE_SOURCE_DIR}/config/*xml ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND cp ${CMAKE_SOURCE_DIR}/scripts/tests.sh ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Copy xml files..."
)

add_custom_target (copy_xml ALL
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/component_a.xml
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

