cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(donut)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Project Options

if (WIN32)
    option(USE_DEBUG_CONSOLE "whether a debug console should be enabled for debug builds, if false debug output is redirected to Visual Studio output" ON)
endif()

# Dependencies
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

add_subdirectory(thirdparty)
add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
