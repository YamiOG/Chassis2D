#include "Global.h"

#include "Chassis2D.h"

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;
class b2World;

namespace SoLoud{
  class Soloud;
}

SDL_Window *gWindow; 
SDL_Renderer *gRenderer;
SDL_Event *gEvent;
b2World *gWorld;
SoLoud::Soloud *gSoloud;

int gScale = 1;

int gMouseClick[3] = {0, 0, 0};
Vec2 gMousePosition = Vec2(0, 0);