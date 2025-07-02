cmake_minimum_required(VERSION 3.22)

project(pos)

include_directories(
    ../
    base_class
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

add_subdirectory(base_class)

add_library(pos ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(pos PUBLIC global_lib)
target_link_libraries(pos PUBLIC base_class)

target_include_directories(pos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
