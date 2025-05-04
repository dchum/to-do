cmake_minimum_required(VERSION 3.22)
project(console_ui)

include_directories(
    cui_widgets
    ../../lib
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


add_subdirectory(cui_widgets)

add_library(console_ui ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(console_ui PUBLIC cui_widgets)
# target_link_libraries(console_ui PUBLIC global_lib)
# target_link_libraries(console_ui PUBLIC cdk_lib)

target_include_directories(console_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})