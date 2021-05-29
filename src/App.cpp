#include "App.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <box2d/box2d.h>
#include <soloud.h>

App::App(const char* title, int width, int height){
    Setup(title, width, height);
}

App::App(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI){
    Setup(title, width, height, gravity, velocityI, positionI);
}

int App::Setup(const char* title, int width, int height){
  this->width = width;
  this->height = height;

  this->velocityI = 8;
  this->positionI = 3;

  if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
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

  ev = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  world = new b2World(b2Vec2(0,0));
  if (!world) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  soloud = new SoLoud::Soloud;
  if(soloud->init() != 0){
    cout << "ERROR:SoLoud Initialization Failed" << endl;
    return -1;
  }
  return 0;
}

int App::Setup(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI){
  this->width = width;
  this->height = height;

  this->velocityI = velocityI;
  this->positionI = positionI;

  if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
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

  ev = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  world = new b2World(*gravity.ToB2());
  if (!world) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  soloud = new SoLoud::Soloud;
  if(soloud->init() != 0){
    cout << "ERROR:SoLoud Initialization Failed" << endl;
    return -1;
  }
  return 0;
}

App::~App(){
  soloud->deinit();
  delete soloud;
  delete world;
  TTF_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void App::Update(){
  eventList.clear();

  mouseClicks[0] = false;
  mouseClicks[1] = false;
  mouseClicks[2] = false;

  while(SDL_PollEvent(ev)){
    eventList.push_back(ev);

    if(ev->type == SDL_QUIT){
      close = true;
    }

    else if(ev->type == SDL_MOUSEBUTTONDOWN){
      switch (ev->button.button)
      {
      case SDL_BUTTON_LEFT:
        mouseClicks[0] = true;
        break;
      case SDL_BUTTON_MIDDLE:
        mouseClicks[1] = true;
        break;
      case SDL_BUTTON_RIGHT:
        mouseClicks[2] = true;
        break;

      default:
        break;
      }
    }
  }
}

string App::GetInputText(){
  for(int i = 0; i < eventList.size(); i++) { 
    if(eventList[i]->type == SDL_TEXTINPUT){
        return eventList[i]->text.text;
    }
  }
  return "";
}

bool App::IsPressed(string k){
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  if(state[SDL_GetScancodeFromName(k.c_str())]){
    return true;
  }
  return false;
}

void App::PhysicsUpdate(){
  if((unsigned)(1000/physicsFPS) <= SDL_GetTicks()-pastTime){
    for(int i = 0; i < particleSystems.size();){
      particleSystems[i]->Update(this);

      if(SDL_GetTicks() >= (unsigned)particleSystems[i]->GetTime()){
        particleSystems.erase(particleSystems.begin()+i);
      }
      else{
        i++;
      }
    }

    world->Step(1.0f/physicsFPS, velocityI, positionI);
    pastTime = SDL_GetTicks();
  }

  Update();
}

void App::Clear(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void App::Clear(int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}

void App::Clear(Color color){
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(renderer);
}

void App::Present(){
  SDL_RenderPresent(renderer);
}

void App::FillRect(Vec4 rect, int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
  SDL_RenderFillRect(renderer, &tRect);
}

Vec2 App::GetMouse(){
  int x, y;
  SDL_GetMouseState(&x, &y);
  return Vec2((float)x,(float)y);
}

long int App::GetTime() { 
  return SDL_GetTicks();
}

bool App::IsMouseInVec4(Vec4 rect){
  SDL_Point mPos;
  SDL_GetMouseState(&mPos.x, &mPos.y);
  if(rect.x < mPos.x && mPos.x < rect.x + rect.w && rect.y < mPos.y && mPos.y < rect.y + rect.h){
    return true;
  }
  return false;
}

int App::Draw(Texture *texture, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_RenderCopy(renderer, texture->GetData(), NULL, &tRect);
  }
  return 0;
}

int App::Draw(Texture *texture, Vec4 crop, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_Rect tCrop = {(int)crop.x, (int)crop.y, (int)crop.w, (int)crop.h};
    SDL_RenderCopy(renderer, texture->GetData(), &tCrop, &tRect);
  }
  return 0;
}

int App::Draw(Object *object){
  if(object){
    if(!object->IsHidden()){
      Draw(object->GetTexture().get(), object->GetRect() - object->GetOrigin());
    }
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Text *text){
  if(text){
    if(!text->IsHidden()){ 
      text->GetOrigin();
      Draw(text->GetText(this).get(), text->GetRect() - text->GetOrigin());
    }
  }
  else{
    cout << "ERROR:Text is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Button *button){
  if(button){
    if(!button->IsHidden()){ 
      Draw(button->GetTexture().get(), button->GetRect() - button->GetOrigin());
      if(!button->GetText()->IsHidden()){ 
        Draw(button->GetText()->GetText(this).get(), button->GetText()->GetRect() - button->GetText()->GetOrigin());
      }
    }
  }
  else{
    cout << "ERROR:Button is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Particle *particle){
  if(particle){
    if(!particle->IsHidden()){ 
      Draw(particle->GetTexture().get(), particle->GetRect() - particle->GetOrigin());
    }
  }
  else{
    cout << "ERROR:Particle is a nullptr" << endl;
    return -1;
  }
  return 0;
}

void App::DrawParticles(){
  for(int i = 0; i < particles.size(); i++){
    if(!particles[i]->IsHidden()){
      Draw(particles[i]->GetTexture().get(), particles[i]->GetRect() - particles[i]->GetOrigin());
    }
  }

  for(int i = 0; i < particleSystems.size(); i++){
    if(!particleSystems[i]->IsHidden()){
      for(int j = 0; j < particleSystems[i]->GetParticles().size(); j++){
          Draw(particleSystems[i]->GetParticles()[j]->GetTexture().get(), particleSystems[i]->GetParticles()[j]->GetRect() - particleSystems[i]->GetParticles()[j]->GetOrigin());
      }
    }
  }
}

bool App::CheckButton(Button *b){
  if(IsMouseInVec4(b->GetRect())){
    if(ev->type == SDL_MOUSEBUTTONDOWN) {
      if(ev->button.button == SDL_BUTTON_LEFT){
        if(b->GetPrevious() == false){
          b->SetPrevious(true);
          return true;
        }
      }
    }
    else{
      if(b->GetPrevious()){
        b->SetPrevious(false);
      }
      return false;
    }
  }
  return false;
}

int App::SpawnParticle(Particle *particle, Vec2 position, Vec2 velocity){
  if(particle){
    Particle *tmp;
    tmp = new Particle(*particle);

    //Body Setup
    tmp->Create(this, position.x, position.y);

    //Inital Impulse
    tmp->ApplyImpulse(velocity);

    //Timer
    tmp->SetTime(SDL_GetTicks() + tmp->GetLifetime());

    shared_ptr<Particle> sharedParticle(tmp);
    particles.push_back(sharedParticle);

  }
  else{
    cout << "ERROR:Particle is NULL" << endl;
    return -1;
  }
  return 0;
}

int App::StartParticleSystem(ParticleSystem *particleSystem, Vec2 position, int time){
  if(particleSystem){
    ParticleSystem *tmp = new ParticleSystem(*particleSystem);

    if(time == -1){
      tmp->SetTime(-1);
    }
    else{
      tmp->SetTime(SDL_GetTicks()+time);
    }

    tmp->SetPosition(position);

    shared_ptr<ParticleSystem> sharedPS(tmp);
    particleSystems.push_back(sharedPS);
  }
  else{
    cout << "ERROR:ParticleSystem is NULL" << endl;
    return -1;
  }
  return 0;
}

bool App::IsColliding(Object* o1, Object* o2){
  for (b2ContactEdge* edge = o1->GetBody()->GetContactList(); edge; edge = edge->next){
    if(edge->contact->GetFixtureB()->GetBody() == o2->GetBody()){
      if(edge->contact->IsTouching()){
        return true;
      }
    }
  }
  return false;
}

bool App::IsSensorColliding(Object *o, int id){
  for (b2ContactEdge* edge = o->GetBody()->GetContactList(); edge; edge = edge->next){
    if(edge->contact->IsTouching()){
      if((intptr_t)edge->contact->GetFixtureA()->GetUserData().pointer == id){
        return true;
      }
    }
  }
  return false;
}

void App::SetMasterVolume(float value){
  soloud->setGlobalVolume(value);
}