#include "App.h"

App::App(const char* title, int w, int h, b2Vec2 setGravity, int sVelocityI, int sPositionI){
    width = w;
    height = h;

    gravity = setGravity;
    velocityI = sVelocityI;
    positionI = sPositionI;

    if( SDL_Init(SDL_INIT_EVERYTHING) == -1){
      cout << "ERROR:SDL2 Initialization Failed" << endl;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
      cout << "ERROR:Window Creation Failed" << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
      cout << "ERROR:Renderer Creation Failed" << endl;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
      cout << "ERROR:SDL_Mixer Initialization Failed" << endl;
    }

    if( TTF_Init() == -1){
      cout << "ERROR:TTF Initialization Failed" << endl;
    }

    world = new b2World(gravity);
    if (!world) {
        cout << "ERROR:b2World Creation Failed" << endl;
    }
}

int App::Setup(const char* title, int w, int h, b2Vec2 setGravity, int sVelocityI, int sPositionI){
  width = w;
  height = h;

  gravity = setGravity;
  velocityI = sVelocityI;
  positionI = sPositionI;

  if( SDL_Init(SDL_INIT_EVERYTHING) == -1){
    cout << "ERROR:SDL2 Initialization Failed" << endl;
    return 1;
  }

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

  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
    cout << "ERROR:SDL_Mixer Initialization Failed" << endl;
    return 1;
  }

  if( TTF_Init() == -1){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return 1;
  }

  world = new b2World(gravity);
  if (!world) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return 1;
  }
  return 0;
}

bool App::IsPressed(int k){
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[k]){
    return true;
  }
  return false;
}

void App::PhysicsUpdate(){
  if(1000/pFPS <= SDL_GetTicks()-pTime){
    world->Step(1.0f/pFPS, velocityI, positionI);
    pTime = SDL_GetTicks();
  }
}

void App::RClear(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void App::RClear(int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}

void App::RPresent(){
  SDL_RenderPresent(renderer);
}

void App::RFillRect(SDL_Rect rect, int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderFillRect(renderer, &rect);
}

void App::SetMusicVolume(float value){
  Mix_VolumeMusic(MIX_MAX_VOLUME * (value/100));
}
