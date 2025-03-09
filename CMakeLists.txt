cmake_minimum_required(VERSION 3.22)
project(test_cui)


find_library(NCURSESW_LIBRARY ncursesw)
find_path(NCURSESW_INCLUDE_DIR ncursesw/ncurses.h)

if (NOT NCURSESW_LIBRARY OR NOT NCURSESW_INCLUDE_DIR)
    message(FATAL_ERROR "ncursesw not found!")
endif()

include_directories(${NCURSESW_INCLUDE_DIR})

add_subdirectory(src/pos)
add_subdirectory(src/lib)
add_subdirectory(src/ui/console_ui)