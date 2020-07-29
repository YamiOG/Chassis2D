cmake_minimum_required(VERSION 3.7)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(PROJECT_NAME Chassis2D)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

if(WIN32)
    if(CMAKE_CL_64)
        set(CMAKE_PREFIX_PATH "vcpkg/installed/x64-windows")
    else()
        set(CMAKE_PREFIX_PATH "vcpkg/installed/x86-windows")
    endif()
elseif(UNIX)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_PREFIX_PATH "vcpkg/installed/x64-linux")
    endif()
endif()

project(${PROJECT_NAME})

#find_package(SDL2 CONFIG REQUIRED)
message(" [INFO] Found SDL2")
#find_package(sdl2-image CONFIG REQUIRED)
message(" [INFO] Found SDL2-Image")
#find_package(sdl2-mixer CONFIG REQUIRED)
message(" [INFO] Found SDL2-Mixer")
#find_package(sdl2-ttf CONFIG REQUIRED)
message(" [INFO] Found SDL2-TTF")
#find_package(sdl2-net CONFIG REQUIRED)
message(" [INFO] Found SDL2-Net")
find_package(unofficial-box2d CONFIG REQUIRED)
message(" [INFO] Found Box2D")

file(GLOB Sources "chassis/*h" "chassis/*.cpp" "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} ${Sources})

#Linking Libs
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main PRIVATE SDL2::SDL2_image PRIVATE SDL2::SDL2_mixer PRIVATE SDL2::SDL2_ttf PRIVATE SDL2::SDL2_net PRIVATE unofficial::box2d::box2d )
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static PRIVATE SDL2::SDL2_image PRIVATE SDL2::SDL2_mixer PRIVATE SDL2::SDL2_ttf PRIVATE SDL2::SDL2_net PRIVATE unofficial::box2d::box2d )
