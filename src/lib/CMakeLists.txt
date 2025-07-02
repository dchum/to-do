cmake_minimum_required(VERSION 3.22)

project(lib)

include_directories(
    .
    classes
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


add_subdirectory(classes)

add_library(global_lib ${LIB_SOURCES} ${LIB_INCLUDES})

# target_link_libraries(global_lib PUBLIC lib_classes)

target_include_directories(global_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
