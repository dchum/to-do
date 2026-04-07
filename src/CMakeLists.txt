cmake_minimum_required(VERSION 3.22)

project(to_do)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_subdirectory(lib)
add_subdirectory(common)
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(app)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE 
    lib
    common
    core_main
    ui_main
    app_logic
)

target_include_directories(main 
    PRIVATE lib
    PRIVATE core
    PRIVATE app
)



