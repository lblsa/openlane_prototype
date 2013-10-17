macro (openlane_build_component _target _list)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall")

add_library(${_target}
    SHARED
    ${_list}
)

set_target_properties (${_target}
    PROPERTIES
    LINK_FLAGS "${LINK_FLAGS} -Wl,--version-script=${CMAKE_SOURCE_DIR}/scripts/component.ld"
)

endmacro (openlane_build_component)
