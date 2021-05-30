#pragma once

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;
class b2World;

extern SDL_Window *c2Window; 
extern SDL_Renderer *c2Renderer;
extern SDL_Event *c2Event;
extern b2World *c2World;

enum Category {
    TERRAIN = 0x0001,
    PLAYER = 0x0002,
    ENEMY = 0x0004,
    PARTICLE = 0x0008,
    SENSOR = 0x0010
};