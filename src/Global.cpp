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