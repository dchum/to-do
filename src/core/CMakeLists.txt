add_subdirectory(models)
add_subdirectory(handlers)

add_library( core_main STATIC
    model.cpp
    model.h
    handler.h
    handler.cpp
)

target_link_libraries(core_main PRIVATE common)
target_link_libraries(core_main PRIVATE models)
target_link_libraries(core_main PRIVATE handlers)

target_include_directories(core_main 
    PUBLIC models
    PUBLIC ../lib/    
)