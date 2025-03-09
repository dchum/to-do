cmake_minimum_required(VERSION 3.22)

project(lib_cui)

include_directories(
    ..
    ../../../pos/
    ../../../lib/
    cdk/
)

add_subdirectory(cdk)

file(GLOB LIB_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

file(GLOB LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(lib_cui ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(lib_cui PUBLIC cdk_lib)
target_link_libraries(lib_cui PUBLIC pos)
target_link_libraries(lib_cui PUBLIC global_lib)
