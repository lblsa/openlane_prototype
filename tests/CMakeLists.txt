add_executable(tests 
    main.cpp 
    module_test.cpp
    module_xml_parser_test.cpp
    component_provider_test.cpp
    )
target_link_libraries(tests openlane gtest)
