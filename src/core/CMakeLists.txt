add_subdirectory(models)

add_library( core_main STATIC
    model.cpp
    model.h
)

target_link_libraries(core_main PRIVATE common)
target_link_libraries(core_main PRIVATE models)

target_include_directories(core_main 
    PUBLIC models
    PUBLIC ../lib/    
)