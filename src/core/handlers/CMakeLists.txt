
file(GLOB LIB_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

file(GLOB LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(handlers ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(handlers PUBLIC lib)

target_include_directories(handlers 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ../../lib/
    PUBLIC ../
    PUBLIC ../models/
    PUBLIC ../../common/
    PUBLIC ../../common/ui_to_core/
    PUBLIC ../../common/ui_to_core/payloads/
)
