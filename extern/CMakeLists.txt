set(SDL_STATIC OFF)
add_subdirectory(SDL2)
add_library(SDL2::SDL2 ALIAS SDL2)

add_subdirectory(freetype)
add_library(Freetype::Freetype ALIAS freetype)

add_subdirectory(SDL2_ttf)

set(BOX2D_BUILD_TESTBED OFF)
add_subdirectory(Box2D)

