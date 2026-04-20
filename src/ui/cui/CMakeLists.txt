message("#### BUILD cui ####")

add_subdirectory(cui_widgets)

add_library(cui
    cui_container.cpp
    cui_lib.cpp
    cui_main.cpp
    cui_screen.cpp
    cui_surface.cpp
    cui_widget.cpp
    cui_command.cpp
    
    windows/cui_window_main.cpp
    windows/cui_window_setting.cpp
    windows/cui_window_start.cpp

    commands/add_new_task.cpp
)

target_include_directories(cui 
    PRIVATE cui_widgets
    PRIVATE windows
    PRIVATE commands
    PRIVATE iterator
)

target_link_libraries(cui PUBLIC cui_widgets)
target_link_libraries(cui PUBLIC cdk_lib)
target_link_libraries(cui PUBLIC common)

target_include_directories(cui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})