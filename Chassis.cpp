#include "Chassis.h"

Chassis::Chassis(const char* title, int w, int h, b2Vec2 setGravity, int sVelocityI, int sPositionI){
    width = w;
    height = h;

    gravity = setGravity;
    velocityI = sVelocityI;
    positionI = sPositionI;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
        cout << "ERROR:Window Creation Failed" << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        cout << "ERROR:Renderer Creation Failed" << endl;
    }

    world = new b2World(gravity);
    if (!world) {
        cout << "ERROR:b2World Creation Failed" << endl;
    }
}

int Chassis::Setup(const char* title, int w, int h, b2Vec2 setGravity, int sVelocityI, int sPositionI){
    width = w;
    height = h;

    gravity = setGravity;
    velocityI = sVelocityI;
    positionI = sPositionI;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
        cout << "ERROR:Window Creation Failed" << endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        cout << "ERROR:Renderer Creation Failed" << endl;
        return 1;
    }

    world = new b2World(gravity);
    if (!world) {
        cout << "ERROR:b2World Creation Failed" << endl;
        return 1;
    }
    return 0;
}

void Chassis::PhysicsUpdate(){
  if(1000/pFPS <= SDL_GetTicks()-pTime){
    world->Step(1.0f/pFPS, velocityI, positionI);
    pTime = SDL_GetTicks();
  }
}

void Chassis::RClear(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void Chassis::RPresent(){
  SDL_RenderPresent(renderer);
}

void Chassis::RFillRect(SDL_Rect rect, int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderFillRect(renderer, &rect);
}
