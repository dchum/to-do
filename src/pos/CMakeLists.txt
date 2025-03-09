cmake_minimum_required(VERSION 3.22)

project(pos)

include_directories(
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


add_library(pos ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(pos PRIVATE global_lib)

target_include_directories(pos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
