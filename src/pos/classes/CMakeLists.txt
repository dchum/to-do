cmake_minimum_required(VERSION 3.22)

project(base_class)

include_directories(
    ../../lib
    search
    ..
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


add_library(base_class ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(base_class PUBLIC global_lib)

target_include_directories(base_class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
