#include "Global.h"

#include "Chassis2D.h"

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;
class b2World;

namespace SoLoud{
  class Soloud;
}

SDL_Window *c2Window; 
SDL_Renderer *c2Renderer;
SDL_Event *c2Event;
b2World *c2World;
SoLoud::Soloud *c2Soloud;

int c2Scale = 1;

int mouseClick[3] = {0, 0, 0};
Vec2 mousePosition = Vec2(0, 0);