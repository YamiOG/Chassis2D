cmake_minimum_required(VERSION 3.7)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

project(Chassis2D VERSION 1.0.0)

add_subdirectory(src)