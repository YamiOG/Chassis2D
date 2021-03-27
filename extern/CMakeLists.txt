set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SDL_STATIC OFF)
add_subdirectory(SDL2)
add_library(SDL2::SDL2 ALIAS SDL2)

add_subdirectory(freetype)
add_library(Freetype::Freetype ALIAS freetype)

add_subdirectory(SDL2_ttf)

set(SOLOUD_BACKEND_COREAUDIO OFF)
set(SOLOUD_BACKEND_OPENSLES OFF)
set(SOLOUD_BACKEND_XAUDIO2 OFF)
set(SOLOUD_BACKEND_WINM OFF)
set(SOLOUD_BACKEND_WASAPI OFF)
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/extern/SDL2/include")
add_subdirectory(SoLoud/contrib)

add_subdirectory(Box2D)