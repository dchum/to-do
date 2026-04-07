message("#### BUILD cdk ####")

add_library(cdk_lib
    cdk_int.h
    alphalist.c
    alphalist.h
    binding.c
    button.c
    buttonbox.c
    cdk_objs.c
    cdk.c
    cdkscreen.c
    dialog.c
    entry.c
    label.c
    radio.c
    traverse.c
    draw.c
    cdk_objs.c
    slider.c
    cdk_display.c
    scroller.c 
    scroll.c
)

find_library(NCURSES_LIBRARY ncurses)
find_path(NCURSES_INCLUDE_DIR ncurses.h)

if (NOT NCURSES_LIBRARY OR NOT NCURSES_INCLUDE_DIR)
    message(FATAL_ERROR "ncurses not found!")
endif()

target_link_libraries(cdk_lib PUBLIC ${NCURSES_LIBRARY})

target_include_directories(cdk_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(cdk_lib PUBLIC ${NCURSES_INCLUDE_DIR})
