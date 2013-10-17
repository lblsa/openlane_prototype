add_executable(tests 
    main.cpp 
    module_test.cpp
    module_xml_parser_test.cpp
    component_provider_test.cpp
    )

target_link_libraries(tests openlane gtest)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/valid.xml
    COMMAND cp ../../config/*xml ${CMAKE_CURRENT_BINARY_DIR} # FIXME
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Copy xml files..."
)

add_custom_target (copy_xml ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/valid.xml
    WORKING_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

