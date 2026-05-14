cmake_minimum_required(VERSION 3.23)

project(
    CMakeProject
    VERSION 1.0
    DESCRIPTION "My first SDL3 Game"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/$<CONFIG>"
)

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/$<CONFIG>"
)

set(SDL3_DIR "${PROJECT_SOURCE_DIR}/vendor/SDL3-3.4.8/cmake")

find_package(SDL3 REQUIRED)

add_executable(MyGame
    src/main.cpp
)
add_custom_command(TARGET MyGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/vendor/SDL3-3.4.8/x86_64-w64-mingw32/bin/SDL3.dll"
        "$<TARGET_FILE_DIR:MyGame>"
)
target_link_libraries(MyGame PRIVATE SDL3::SDL3)