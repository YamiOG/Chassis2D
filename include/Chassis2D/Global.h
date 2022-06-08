#ifndef GLOBAL_H
#define GLOBAL_H

#include "Vec2.h"

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;
class b2World;

namespace SoLoud{
  class Soloud;
}

extern int gScale;

extern int gMouseClick[3];
extern Vec2 gMousePosition;

const int MOUSE_LEFT = 0;
const int MOUSE_MIDDLE = 1;
const int MOUSE_RIGHT = 2;

extern SDL_Window *gWindow; 
extern SDL_Renderer *gRenderer;
extern SDL_Event *gEvent;
extern b2World *gWorld;
extern SoLoud::Soloud *gSoloud;

enum Category {
    TERRAIN = 0x0001,
    PLAYER = 0x0002,
    ENEMY = 0x0004,
    PARTICLE = 0x0008,
    SENSOR = 0x0010
};

#endif