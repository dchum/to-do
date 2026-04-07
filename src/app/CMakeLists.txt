add_library( app_logic STATIC
    application.cpp
)

target_link_libraries(app_logic PRIVATE core_main)
target_link_libraries(app_logic PRIVATE ui_main)


target_include_directories(app_logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(app_logic PRIVATE ../core)
