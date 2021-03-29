#include "Color.h"

#include "Chassis2D.h"

#include <SDL.h>

SDL_Color Color::ToSDL(){
    SDL_Color color = {r, g, b, a};
    return color;
}