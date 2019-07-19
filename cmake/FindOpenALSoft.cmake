# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
FindOpenALSoft
----------

Locate OpenAL This module defines OPENALSOFT_LIBRARY OPENALSOFT_FOUND, if
false, do not try to link to OpenAL OPENALSOFT_INCLUDE_DIR, where to find
the headers

I copied a bunch of shit from FindSDL2

#]=======================================================================]

find_path(OPENALSOFT_INCLUDE_DIR al.h
  HINTS
    ENV OPENALDIR
  PATH_SUFFIXES include/AL include/OpenAL include AL OpenAL
  PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(_OpenALSoft_ARCH_DIR libs/Win64)
else()
  set(_OpenALSoft_ARCH_DIR libs/Win32)
endif()

find_library(OPENAL_LIBRARY
  NAMES OpenAL al openal OpenAL32
  HINTS
    ENV OPENALDIR
  PATH_SUFFIXES libx32 lib64 lib libs64 libs ${_OpenALSoft_ARCH_DIR}
  PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /sw
  /opt/local
  /opt/csw
  /opt
)

unset(_OpenAL_ARCH_DIR)

include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OpenAL  DEFAULT_MSG  OPENALSOFT_LIBRARY OPENALSOFT_INCLUDE_DIR)

mark_as_advanced(OPENAL_LIBRARY OPENAL_INCLUDE_DIR)