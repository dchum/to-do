message("#### BUILD cui_widgets ####")

add_subdirectory(cdk)

add_library(cui_widgets 
    cui_border.cpp 
    cui_dialog.cpp  
    cui_entry.cpp 
    cui_label.cpp 
    cui_radio.cpp 
    cui_scroll_list.cpp 
    cui_slider.cpp
)

target_include_directories(cui_widgets 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ..
    PUBLIC ${NCURSES_INCLUDE_DIR}
)

target_link_libraries( cui_widgets PUBLIC cdk_lib )
target_link_libraries(cui_widgets PUBLIC ${NCURSES_LIBRARY})