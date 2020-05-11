#include "App.h"

#include "Chassis2D.h"

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
    return -1;
  }

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
  if (!window) {
    cout << "ERROR:Window Creation Failed" << endl;
    return -1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    cout << "ERROR:Renderer Creation Failed" << endl;
    return -1;
  }

  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
    cout << "ERROR:SDL_Mixer Initialization Failed" << endl;
    return -1;
  }

  if( TTF_Init() == -1){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  world = new b2World(gravity);
  if (!world) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }
  return 0;
}

App::~App(){
  delete world;
  TTF_Quit();
  Mix_CloseAudio();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool App::IsPressed(int k){
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[k]){
    return true;
  }
  return false;
}

void App::PhysicsUpdate(){
  for(int i = 0; i < particles.size(); i++){
    if(SDL_GetTicks() >= particles[i]->GetTime()){
      world->DestroyBody(particles[i]->GetBody());
      particles.erase(particles.begin()+i);
    }
  }

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
  Mix_VolumeMusic(MIX_MAX_VOLUME * (value/100.f));
  mVol = value/100.f;
}

void App::SetSFXVolume(float value){
  Mix_Volume(-1, MIX_MAX_VOLUME * (value/100.f));
  cVol = value/100.f;
}

void App::SetMasterVolume(float value){
  Mix_VolumeMusic(MIX_MAX_VOLUME * (value/100.f) * mVol);
  Mix_Volume(-1, MIX_MAX_VOLUME * (value/100.f) * cVol);
}

SDL_Point App::GetMouse(){
  SDL_Point pos;
  SDL_GetMouseState(&pos.x, &pos.y);
  return pos;
}

bool App::IsMouseInRect(SDL_Rect rect){
  SDL_Point mPos;
  SDL_GetMouseState(&mPos.x, &mPos.y);
  if(rect.x < mPos.x && mPos.x < rect.x + rect.w && rect.y < mPos.y && mPos.y < rect.y + rect.h){
    return true;
  }
  return false;
}

int App::AddObject(Object* o){
  if(o){
    o->SetBody(world->CreateBody(o->GetBodyDef()));
    o->GetBody()->CreateFixture(o->GetFixtureDef());
    o->GetBody()->SetUserData(o);
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return 1;
  }
  return 0;
}

int App::Draw(Object *o){
  if(o){
    SDL_Rect rect = o->GetScaledPosition();
    SDL_RenderCopy(renderer, o->GetTexture()->GetTexture(), NULL, &rect);
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Text *t){
  if(t){
    SDL_Rect rect = t->GetRect();
    SDL_RenderCopy(renderer, t->GetText(this), NULL, &rect);
  }
  else{
    cout << "ERROR:Text is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Button *b){
  if(b){
    SDL_Rect rect = b->GetRect();
    SDL_RenderCopy(renderer, b->GetTexture()->GetTexture(), NULL, &rect);
    Draw(b->GetText());
  }
  else{
    cout << "ERROR:Button is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Particle *p){
  if(p){
    SDL_Rect rect = p->GetScaledPosition();
    SDL_RenderCopy(renderer, p->GetTexture()->GetTexture(), NULL, &rect);
  }
  else{
    cout << "ERROR:Particle is a nullptr" << endl;
    return -1;
  }
  return 0;
}

void App::DrawParticles(){
  for(int i = 0; i < particles.size(); i++){
    SDL_Rect rect = particles[i]->GetScaledPosition();
    SDL_RenderCopy(renderer, particles[i]->GetTexture()->GetTexture(), NULL, &rect);
  }
}

bool App::CheckButton(Button *b){
  if(IsMouseInRect(b->GetRect())){
    if(ev.type == SDL_MOUSEBUTTONDOWN) {
      if(ev.button.button == SDL_BUTTON_LEFT){
        if(b->GetPrev() == false){
          b->SetPrev(true);
          return true;
        }
      }
    }
    else{
      if(b->GetPrev()){
        b->SetPrev(false);
      }
      return false;
    }
  }
  return false;
}

int App::SpawnParticle(Particle *p, int x, int y, float dX, float dY){
  if(p){
    Particle *tmp;
    tmp = new Particle(*p);

    //Body Setup
    tmp->Create(x, y);

    tmp->SetBody(world->CreateBody(tmp->GetBodyDef()));
    tmp->GetBody()->CreateFixture(tmp->GetFixtureDef());
    tmp->GetBody()->SetUserData(tmp);
    
    //Inital Impulse
    tmp->ApplyImpulse(b2Vec2(dX, dY));

    //Timer
    tmp->SetTime(SDL_GetTicks() + tmp->GetLifetime());

    particles.push_back(tmp);   
  }
  else{
    cout << "ERROR:Particle is NULL" << endl;
    return -1;
  }
  return 0;
}

