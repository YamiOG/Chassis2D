#include "Color.h"

#include "Chassis2D.h"

#include <SDL.h>

SDL_Color Color::ToSDL(){
    SDL_Color color = {(Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a};
    return color;
}