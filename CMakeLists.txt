cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(donut)

# Set C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Project Options
if (WIN32)
    option(USE_DEBUG_CONSOLE "whether a debug console should be enabled for debug builds, if false debug output is redirected to Visual Studio output" ON)
endif()

# Check that all Git submodules are present
function(check_submodules_present)
    file(READ "${PROJECT_SOURCE_DIR}/.gitmodules" gitmodules)
    string(REGEX MATCHALL "path *= *[^ \t\r\n]*" gitmodules ${gitmodules})
    foreach(module ${gitmodules})
        string(REGEX REPLACE "path *= *" "" module ${module})
        if (NOT EXISTS "${PROJECT_SOURCE_DIR}/${module}/.git")
            message(FATAL_ERROR "Git submodule ${module} not found. "
                    "Please run: git submodule update --init --recursive")
        endif()
    endforeach()
endfunction()
check_submodules_present()

# Disable BUILD_SHARED_LIBS on MSVC because its shit
if (MSVC)
    set(BUILD_SHARED_LIBS OFF)
endif()

# Dependencies
find_package(OpenGL REQUIRED)

# Use bundled SDL2 on Windows x86_64
if (MSVC)
    set(SDL2_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL2-2.0.8")
    set(SDL2_FOUND YES)
    set(SDL2_INCLUDE_DIR "${SDL2_PREFIX}/include" CACHE PATH "Path to SDL2 headers")
    set(SDL2_LIBRARY "${SDL2_PREFIX}/lib/x64/SDL2.lib" CACHE PATH "Path to SDL2 library")
    set(SDL2_DLL_DIR "${SDL2_PREFIX}/lib/x64/" CACHE PATH "Path to SDL2.dll")
else ()
find_package(SDL2 REQUIRED)
endif()

if (SDL2_FOUND)
    add_library(SDL2 INTERFACE)
    target_link_libraries(SDL2 INTERFACE "${SDL2_LIBRARY}")
    target_include_directories(SDL2 INTERFACE "${SDL2_INCLUDE_DIR}")
endif()

# Use bundled OpenAL on Windows x86_64
if (MSVC)
set(OPENALSOFT_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/openal-soft")
set(OPENALSOFT_FOUND YES)
set(OPENALSOFT_INCLUDE_DIR "${OPENALSOFT_PREFIX}/include" CACHE PATH "Path to OpenAL-Soft headers")
set(OPENALSOFT_LIBRARY "${OPENALSOFT_PREFIX}/libs/Win64/OpenAL32.lib" CACHE PATH "Path to OpenAL-Soft library")
set(OPENALSOFT_DLL_DIR "${OPENALSOFT_PREFIX}/bin/Win64/" CACHE PATH "Path to soft_oal.dll")
else()
find_package(OpenALSoft REQUIRED)
endif()

if (OPENALSOFT_FOUND)
    add_library(OPENALSOFT INTERFACE)
    target_link_libraries(OPENALSOFT INTERFACE "${OPENALSOFT_LIBRARY}")
    target_include_directories(OPENALSOFT INTERFACE "${OPENALSOFT_INCLUDE_DIR}")
endif()

find_package(Bullet REQUIRED COMPONENTS BulletCollision_Debug BulletDynamics_Debug LinearMath_Debug)

# More Dependencies
add_subdirectory(thirdparty)

# The Code
add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/bin/$<CONFIG>")
