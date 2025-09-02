cmake_minimum_required(VERSION 3.22)

project(ui)

include_directories(
    cui/cui_widgets
    console_ui
    ../lib
)

file(GLOB LIB_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

file(GLOB LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_subdirectory(console_ui)

add_library(ui ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(ui PUBLIC global_lib)
target_link_libraries(ui PUBLIC cui)

target_include_directories(ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
