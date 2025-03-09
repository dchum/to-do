cmake_minimum_required(VERSION 3.22)

project(cdk_lib)

file(GLOB LIB_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

file(GLOB LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# foreach(FILE ${LIB_INCLUDES})
#     message(${FILE})
# endforeach()

add_library(cdk_lib ${LIB_SOURCES} ${LIB_INCLUDES})

target_include_directories(cdk_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_cui PUBLIC cdk_lib pos global_lib ${NCURSESW_LIBRARY})
