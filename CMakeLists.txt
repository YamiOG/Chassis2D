cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME Chassis2D)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

project(${PROJECT_NAME} VERSION 1.0.0)

find_package(SDL2 CONFIG REQUIRED)
message(" [INFO] Found SDL2")
find_package(sdl2-image CONFIG REQUIRED)
message(" [INFO] Found SDL2-Image")
find_package(sdl2-mixer CONFIG REQUIRED)
message(" [INFO] Found SDL2-Mixer")
find_package(sdl2-ttf CONFIG REQUIRED)
message(" [INFO] Found SDL2-TTF")
find_package(unofficial-box2d CONFIG REQUIRED)
message(" [INFO] Found Box2D")

file(GLOB SOURCES "chassis/*h" "chassis/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set_target_properties( ${PROJECT_NAME} 
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main PRIVATE SDL2::SDL2_image PRIVATE SDL2::SDL2_mixer PRIVATE SDL2::SDL2_ttf PRIVATE unofficial::box2d::box2d )