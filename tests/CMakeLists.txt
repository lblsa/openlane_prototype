add_executable(tests 
    main.cpp 
    module_test.cpp
    module_xml_parser_test.cpp
    component_provider_test.cpp
    )

target_link_libraries(tests openlane gtest)

add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/valid.xml
    COMMAND cp ../../config/*xml ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} # FIXME
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Copy xml files..."
)

add_custom_target (copy_xml ALL
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/valid.xml
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

