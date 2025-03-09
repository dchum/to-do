cmake_minimum_required(VERSION 3.22)
project(test_cui)

include_directories(
    src
    ../../pos
    ../../lib
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(test_cui test.cpp)

add_subdirectory(src)

target_link_libraries(test_cui PUBLIC lib_cui)
target_link_libraries(test_cui PUBLIC pos)
target_link_libraries(test_cui PUBLIC global_lib)
target_link_libraries(test_cui PUBLIC cdk_lib)