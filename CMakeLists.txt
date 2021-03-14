add_subdirectory(extern)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(FCL_STATIC_LIBRARY ON)

set(PROJECT_NAME Chassis2D)

project(${PROJECT_NAME} VERSION 0.1.0)

add_subdirectory(src)

add_subdirectory(demos)