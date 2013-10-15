add_library(openlane STATIC 
    module.cpp
    xml_parser.cpp
    module_xml_parser.cpp
    )

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
target_link_libraries(openlane dl expat)
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
