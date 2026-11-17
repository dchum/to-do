cmake_minimum_required(VERSION 3.16)

# Позволяет конфигурировать tests как самостоятельный проект:
# cmake -S tests -B build-tests
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(cui_tests LANGUAGES CXX)
endif()

# Поиск ncurses
if(APPLE)
    set(CURSES_NEED_NCURSES TRUE)
elseif(UNIX)
    set(CURSES_NEED_WIDE TRUE)
else()
    message(FATAL_ERROR "Unsupported platform for ncurses")
endif()

find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Пути относительно src/tests
set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(GTEST_DIR "${PROJECT_ROOT}/modules/googletest")
set(INPUT_DIR "${PROJECT_ROOT}/ui/cui/input")
set(COMMON_DIR "${PROJECT_ROOT}/common")
set(MAGIC_ENUM_DIR "${PROJECT_ROOT}/modules/magic_enum/include/magic_enum")
set(JSON_DIR "${PROJECT_ROOT}/modules/json/single_include/nlohmann")

# Google Test
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

add_subdirectory(
    "${GTEST_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/googletest"
    EXCLUDE_FROM_ALL
)

function(configure_test target)
    target_compile_options(${target} PRIVATE
        -Wall
        -Wextra
        -Wno-unused-variable
        -g
    )

    if(APPLE)
        target_compile_definitions(${target} PRIVATE
            NCURSES_WIDECHAR
        )
    endif()

    target_include_directories(${target} PRIVATE
        "${CURSES_INCLUDE_DIRS}"
        "${PROJECT_ROOT}"
        "${PROJECT_ROOT}/utilities"
        "${INPUT_DIR}"
        "${COMMON_DIR}"
        "${MAGIC_ENUM_DIR}"
        "${JSON_DIR}"
    )

    target_link_libraries(${target} PRIVATE
        GTest::gtest_main
        ${CURSES_LIBRARIES}
    )
endfunction()

add_executable(test_config
    test_config.cc
    "${INPUT_DIR}/config.cpp"
    "${INPUT_DIR}/key_input.cpp"
)

configure_test(test_config)

# Второй тест
add_executable(test_convert
    test_convert.cc
    "${INPUT_DIR}/key_input.cpp"
    "${INPUT_DIR}/config.cpp"
)

configure_test(test_convert)

# Третий тест
add_executable(test_input
    test_input.cpp
    "${INPUT_DIR}/key_input.cpp"
    "${INPUT_DIR}/config.cpp"
)

configure_test(test_input)


# Копируем тестовый JSON в каталог сборки.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/bindKeys.json"
    "${CMAKE_CURRENT_BINARY_DIR}/bindKeys.json"
    COPYONLY
)

enable_testing()

add_test(NAME test_config COMMAND test_config)
add_test(NAME test_convert COMMAND test_convert)
add_test(NAME test_input COMMAND test_input)

set_tests_properties(
    test_config
    test_convert
    test_input
    PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
