cmake_minimum_required(VERSION 3.22)
project(main)

message("\nBUILD MASTER VERSION!!!\n")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

find_library(NCURSES_LIBRARY ncurses)
find_path(NCURSES_INCLUDE_DIR ncurses.h)

if (NOT NCURSES_LIBRARY OR NOT NCURSES_INCLUDE_DIR)
    message(FATAL_ERROR "ncurses not found!")
endif()

include_directories(${NCURSES_INCLUDE_DIR})

add_executable(main main.cpp)

add_subdirectory(pos)
add_subdirectory(lib)
add_subdirectory(ui)

target_link_libraries(main PUBLIC ${NCURSESW_LIBRARY})

target_link_libraries(main PUBLIC pos)
target_link_libraries(main PUBLIC global_lib)
target_link_libraries(main PUBLIC ui)
