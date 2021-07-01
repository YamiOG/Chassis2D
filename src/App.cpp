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

  c2Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
  if (!c2Window) {
    cout << "ERROR:Window Creation Failed" << endl;
    return -1;
  }

  c2Renderer = SDL_CreateRenderer(c2Window, -1, 0);
  if (!c2Renderer) {
    cout << "ERROR:Renderer Creation Failed" << endl;
    return -1;
  }

  c2Event = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  c2World = new b2World(b2Vec2(0,0));
  if (!c2World) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  c2Soloud = new SoLoud::Soloud;
  if(c2Soloud->init() != 0){
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

  c2Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
  if (!c2Window) {
    cout << "ERROR:Window Creation Failed" << endl;
    return -1;
  }

  c2Renderer = SDL_CreateRenderer(c2Window, -1, 0);
  if (!c2Renderer) {
    cout << "ERROR:Renderer Creation Failed" << endl;
    return -1;
  }

  c2Event = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  c2World = new b2World(*gravity.ToB2());
  if (!c2World) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  c2Soloud = new SoLoud::Soloud;
  if(c2Soloud->init() != 0){
    cout << "ERROR:SoLoud Initialization Failed" << endl;
    return -1;
  }
  return 0;
}

App::~App(){
  c2Soloud->deinit();
  delete c2Soloud;
  delete c2World;
  TTF_Quit();
  SDL_DestroyRenderer(c2Renderer);
  SDL_DestroyWindow(c2Window);
  SDL_Quit();
}

void App::Update(){
  eventList.clear();

  mouseClick[MOUSE_LEFT] = 0;
  mouseClick[MOUSE_MIDDLE] = 0;
  mouseClick[MOUSE_RIGHT] = 0;

  int x, y;
  SDL_GetMouseState(&x, &y);
  mousePosition.Set((float)x,(float)y);

  while(SDL_PollEvent(c2Event)){
    eventList.push_back(c2Event);

    if(c2Event->type == SDL_QUIT){
      close = true;
    }

    else if(c2Event->type == SDL_MOUSEBUTTONDOWN){
      switch (c2Event->button.button)
      {
      case SDL_BUTTON_LEFT:
        mouseClick[MOUSE_LEFT] = 1;
        break;
      case SDL_BUTTON_MIDDLE:
        mouseClick[MOUSE_MIDDLE] = 1;
        break;
      case SDL_BUTTON_RIGHT:
        mouseClick[MOUSE_RIGHT] = 1;
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
      particleSystems[i]->Update();

      if(SDL_GetTicks() >= (unsigned)particleSystems[i]->GetTime()){
        particleSystems.erase(particleSystems.begin()+i);
      }
      else{
        i++;
      }
    }

    c2World->Step(1.0f/physicsFPS, velocityI, positionI);
    pastTime = SDL_GetTicks();
  }

  Update();
}

void App::Clear(){
  SDL_SetRenderDrawColor(c2Renderer, 255, 255, 255, 255);
  SDL_RenderClear(c2Renderer);
}

void App::Clear(int r, int g, int b){
  SDL_SetRenderDrawColor(c2Renderer, r, g, b, 255);
  SDL_RenderClear(c2Renderer);
}

void App::Clear(Color color){
  SDL_SetRenderDrawColor(c2Renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(c2Renderer);
}

void App::Present(){
  SDL_RenderPresent(c2Renderer);
}

void App::FillRect(Vec4 rect, int r, int g, int b){
  SDL_SetRenderDrawColor(c2Renderer, r, g, b, 255);
  SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
  SDL_RenderFillRect(c2Renderer, &tRect);
}

void App::FillRect(Vec4 rect, int r, int g, int b, int a){
  SDL_SetRenderDrawColor(c2Renderer, r, g, b, a);
  SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
  SDL_RenderFillRect(c2Renderer, &tRect);
}

void App::FillRect(Vec4 rect, Color color){
  SDL_SetRenderDrawColor(c2Renderer, color.r, color.g, color.b, color.a);
  SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
  SDL_RenderFillRect(c2Renderer, &tRect);
}

Vec2 App::GetMouse(){
  return mousePosition;
}

long int App::GetTime() { 
  return SDL_GetTicks();
}

bool App::IsMouseInVec4(Vec4 rect){
  if(rect.x < mousePosition.x && mousePosition.x < rect.x + rect.w && rect.y < mousePosition.y && mousePosition.y < rect.y + rect.h){
    return true;
  }
  return false;
}

int App::Draw(Texture *texture, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_RenderCopy(c2Renderer, texture->GetData(), NULL, &tRect);
  }
  return 0;
}

int App::Draw(Texture *texture, Vec4 crop, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_Rect tCrop = {(int)crop.x, (int)crop.y, (int)crop.w, (int)crop.h};
    SDL_RenderCopy(c2Renderer, texture->GetData(), &tCrop, &tRect);
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
      Draw(text->GetTexture().get(), text->GetRect() - text->GetOrigin());
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
      if(button->GetTexture().get()){
        Draw(button->GetTexture().get(), button->GetRect() - button->GetOrigin());
      }
      else{
        FillRect(button->GetRect(), button->GetColor());
      }
      if(!button->GetText()->IsHidden()){ 
        Draw(button->GetText()->GetTexture().get(), button->GetText()->GetRect() - button->GetText()->GetOrigin());
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

void App::DrawUI(){
  if(ui){
    for(int i = 0; i < ui->GetButtons().size(); i++){
      Draw(ui->GetButtons()[i]);
    }
    for(int i = 0; i < ui->GetTexts().size(); i++){
      Draw(ui->GetTexts()[i]);
    }
  }
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
  c2Soloud->setGlobalVolume(value);
}

bool App::IsLeftMouse() { 
  return mouseClick[MOUSE_LEFT];
}

bool App::IsMiddleMouse() { 
  return mouseClick[MOUSE_MIDDLE];
}

bool App::IsRightMouse() { 
  return mouseClick[MOUSE_RIGHT];
}