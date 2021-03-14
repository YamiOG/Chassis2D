#include "Vec4.h"

#include "Chassis2D.h"

Vec4::Vec4(SDL_Rect *p) { 
    this->x = (float)p->x; 
    this->y = (float)p->y; 
    this->w = (float)p->w; 
    this->h = (float)p->h;
}

SDL_Rect *Vec4::ToSDL() { 
    SDL_Rect rect = {(int)x, (int)y, (int)w, (int)h};
    return &rect;
}