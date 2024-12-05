# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта
project(TestProject)

set(DIRECTORIES
    ${CMAKE_SOURCE_DIR}/../base_class
    ${CMAKE_SOURCE_DIR}/../
)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE)
set(HEADER)

set( SOURCE_FILES
    "baseclass_board.cpp"
    "baseclass_week.cpp"
    "baseclass_task.cpp"
    "baseclass_day.cpp"
    "global_lib.cpp"
)

set( HEADER_FILES
    "baseclass_board.h"
    "baseclass_week.h"
    "baseclass_task.h"
    "baseclass_day.h"
    "global_lib.h"
    "log_duration.h"
)

foreach(FILE_NAME ${SOURCE_FILES})
    foreach(DIR ${DIRECTORIES})

        set(FILE_PATH "${DIR}/${FILE_NAME}")

        if(EXISTS "${FILE_PATH}")
            list(APPEND SOURCE "${FILE_PATH}")
        endif()
    endforeach()
endforeach()

# message(STATUS "Source files: ${SOURCE}")
# message(STATUS "Header files: ${HEADER_FILES}")
# message(STATUS "Main source file: ${CMAKE_SOURCE_DIR}/test_main.cpp")

include_directories(
    ${CMAKE_SOURCE_DIR}/../${INCLUDE}        # Директория на уровень выше
    ${CMAKE_SOURCE_DIR}/../../${INCLUDE}     # Директория на два уровня выше
)

add_executable(test_main ${SOURCE} ${CMAKE_SOURCE_DIR}/test_main.cpp)

