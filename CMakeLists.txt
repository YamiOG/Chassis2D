set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(extern)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(PROJECT_NAME Chassis2D)

project(${PROJECT_NAME} VERSION 1.0.0)

add_subdirectory(src)

add_subdirectory(demos)