struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;

extern SDL_Window *c2_window; 
extern SDL_Renderer *c2_renderer;
extern SDL_Event *c2_event;

enum Category {
    TERRAIN = 0x0001,
    PLAYER = 0x0002,
    ENEMY = 0x0004,
    PARTICLE = 0x0008,
    SENSOR = 0x0010
};