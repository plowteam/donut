cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(donut)

# Set C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# disable in-source builds
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Project Options
if (WIN32)
    option(DONUT_USE_DEBUG_CONSOLE "whether a debug console should be enabled for debug builds, if false debug output is redirected to Visual Studio output" ON)
    option(DONUT_DOWNLOAD_SDL2 "Downloads precompiled SDL2 binaries and uses those." ON)
    option(DONUT_DOWNLOAD_OPENALSOFT "Downloads precompiled OpenAL-Soft binaries and uses those." ON)
endif()

# Default build type to release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
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

include(DownloadLibrary)

# Download precompiled SDL2 on Windows x86_64
if (DONUT_DOWNLOAD_SDL2 AND MSVC)
    set(SDL2_VERSION "2.0.8")

    download_library(http://libsdl.org/release/SDL2-devel-${SDL2_VERSION}-VC.zip "SDL2-${SDL2_VERSION}" SDL2_PREFIX)

    # set(SDL2_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL2-2.0.8")
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

# Download precompiled OpenAL on Windows x86_64
if (DONUT_DOWNLOAD_OPENALSOFT AND MSVC)
    set(OPENAL_VERSION "1.19.1")

    download_library(https://kcat.strangesoft.net/openal-binaries/openal-soft-${OPENAL_VERSION}-bin.zip "openal-soft-${OPENAL_VERSION}-bin" OPENAL_PREFIX)

    set(OPENAL_FOUND YES)
    set(OPENAL_INCLUDE_DIR "${OPENAL_PREFIX}/include" CACHE PATH "Path to OpenAL-Soft headers")
    set(OPENAL_LIBRARY "${OPENAL_PREFIX}/libs/Win64/OpenAL32.lib" CACHE PATH "Path to OpenAL-Soft library")
    set(OPENAL_DLL_DIR "${OPENAL_PREFIX}/bin/Win64/" CACHE PATH "Path to soft_oal.dll")
else()
    find_package(OpenAL REQUIRED)
endif()

if (OPENAL_FOUND)
    add_library(OPENAL INTERFACE)
    target_link_libraries(OPENAL INTERFACE "${OPENAL_LIBRARY}")
    target_include_directories(OPENAL INTERFACE "${OPENAL_INCLUDE_DIR}")
endif()

find_package(Bullet REQUIRED COMPONENTS BulletCollision_Debug BulletDynamics_Debug LinearMath_Debug)

# More Dependencies
add_subdirectory(thirdparty)

# The Code
add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/bin/$<CONFIG>")
