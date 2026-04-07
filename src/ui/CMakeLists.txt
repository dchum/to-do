message("#### BUILD ui ####")

add_library(ui_main 
    ui.cpp
    ui.h
)

add_subdirectory(cui)

target_link_libraries(ui_main PUBLIC cui)

target_include_directories(ui_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
