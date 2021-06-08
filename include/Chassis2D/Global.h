#ifndef GLOBAL_H
#define GLOBAL_H

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;
class b2World;

namespace SoLoud{
  class Soloud;
}

#define MOUSE_LEFT = 0;
#define MOUSE_MIDDLE = 1;
#define MOUSE_RIGHT = 2;

extern SDL_Window *c2Window; 
extern SDL_Renderer *c2Renderer;
extern SDL_Event *c2Event;
extern b2World *c2World;
extern SoLoud::Soloud *c2Soloud;

enum Category {
    TERRAIN = 0x0001,
    PLAYER = 0x0002,
    ENEMY = 0x0004,
    PARTICLE = 0x0008,
    SENSOR = 0x0010
};

#endif