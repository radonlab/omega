cmake_minimum_required(VERSION 3.14)
project(omega VERSION 0.0.1 LANGUAGES C)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

set(CMAKE_C_STANDARD 99)

# Build Options
option(OMEGA_BUILD_TOOLS "Build PEG parser generator" OFF)

include(CTest)

# Declare project scope variables
set(OMEGA_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(OMEGA_SOURCE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Generate config files
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/omgconf.h.in
  ${CMAKE_CURRENT_SOURCE_DIR}/include/omega/omgconf.h
  @ONLY
)

# Initialize project
add_subdirectory(omega)
add_subdirectory(cmd)

if(OMEGA_BUILD_TOOLS)
  add_subdirectory(tools)
endif()
