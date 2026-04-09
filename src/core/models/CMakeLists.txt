# add_subdirectory(search)

file(GLOB LIB_INCLUDES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

file(GLOB LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(models ${LIB_SOURCES} ${LIB_INCLUDES})

target_link_libraries(models PUBLIC lib)

target_include_directories(models 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ../../lib/
    # PUBLIC search    
)
