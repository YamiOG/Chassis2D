#include "App.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <box2d/box2d.h>
#include <soloud.h>
#include <stb_image.h>

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
  this->physicsFPS = 60;

  if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
    cout << "ERROR:SDL2 Initialization Failed" << endl;
    return -1;
  }

  gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
  if (!gWindow) {
    cout << "ERROR:Window Creation Failed" << endl;
    return -1;
  }

  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
  if (!gRenderer) {
    cout << "ERROR:Renderer Creation Failed" << endl;
    return -1;
  }

  gEvent = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  gWorld = new b2World(b2Vec2(0,0));
  if (!gWorld) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  gSoloud = new SoLoud::Soloud;
  if(gSoloud->init() != 0){
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
  this->physicsFPS = 60;

  if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
    cout << "ERROR:SDL2 Initialization Failed" << endl;
    return -1;
  }

  gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
  if (!gWindow) {
    cout << "ERROR:Window Creation Failed" << endl;
    return -1;
  }

  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
  if (!gRenderer) {
    cout << "ERROR:Renderer Creation Failed" << endl;
    return -1;
  }

  gEvent = new SDL_Event;

  if(TTF_Init() != 0){
    cout << "ERROR:TTF Initialization Failed" << endl;
    return -1;
  }

  gWorld = new b2World(b2Vec2(gravity.x, gravity.y));
  if (!gWorld) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  gSoloud = new SoLoud::Soloud;
  if(gSoloud->init() != 0){
    cout << "ERROR:SoLoud Initialization Failed" << endl;
    return -1;
  }
  return 0;
}

App::~App(){
  gSoloud->deinit();
  delete gSoloud;
  delete gWorld;
  TTF_Quit();
  delete gEvent;
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
}

void App::SetWindowIcon(const char* location){
  int req_format = STBI_rgb_alpha;
  int orig_format;
  int s_width, s_height;
  unsigned char* data = stbi_load(location, &s_width, &s_height, &orig_format, req_format);
  if (data == NULL) {
      cout << "ERROR:stb_image Failed to load file" << endl;
  }

  int depth = 32;
  int pitch = 4*s_width;

  SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, s_width, s_height, depth, pitch, SDL_PIXELFORMAT_RGBA32);

  SDL_SetWindowIcon(gWindow, surface);
}

void App::Update(){
  eventList.clear();

  gMouseClick[MOUSE_LEFT] = 0;
  gMouseClick[MOUSE_MIDDLE] = 0;
  gMouseClick[MOUSE_RIGHT] = 0;

  int x, y;
  SDL_GetMouseState(&x, &y);
  gMousePosition.Set((float)x,(float)y);

  while(SDL_PollEvent(gEvent)){
    eventList.push_back(gEvent);

    if(gEvent->type == SDL_QUIT){
      close = true;
    }

    else if(gEvent->type == SDL_MOUSEBUTTONDOWN){
      switch (gEvent->button.button)
      {
      case SDL_BUTTON_LEFT:
        gMouseClick[MOUSE_LEFT] = 1;
        break;
      case SDL_BUTTON_MIDDLE:
        gMouseClick[MOUSE_MIDDLE] = 1;
        break;
      case SDL_BUTTON_RIGHT:
        gMouseClick[MOUSE_RIGHT] = 1;
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
  if((1000/physicsFPS) <= SDL_GetTicks()-pastTime){
    for(int i = 0; i < particleSystems.size(); i++){
      particleSystems[i]->Update();

      if(SDL_GetTicks() >= (unsigned)particleSystems[i]->GetTime()){
        particleSystems.erase(particleSystems.begin()+i);
      }
    }

    gWorld->Step(1.0f/physicsFPS, velocityI, positionI);
    pastTime = SDL_GetTicks();
  }

  Update();
}

void App::Clear(){
  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
  SDL_RenderClear(gRenderer);
}

void App::Clear(int r, int g, int b){
  SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
  SDL_RenderClear(gRenderer);
}

void App::Clear(Color color){
  SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(gRenderer);
}

void App::Present(){
  SDL_RenderPresent(gRenderer);
}

void App::FillRect(Vec4 rect, int r, int g, int b){
  FillRect(rect, Color(r, g, b, 255));
}

void App::FillRect(Vec4 rect, int r, int g, int b, int a){
  FillRect(rect, Color(r, g, b, a));
}

void App::FillRect(Vec4 rect, Color color){
  SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
  SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
  SDL_RenderFillRect(gRenderer, &tRect);
}

void App::FillRoundedRect(Vec4 rect, int radius, int r, int g, int b){
  FillRoundedRect(rect, radius, Color(r, g, b, 255));
}

void App::FillRoundedRect(Vec4 rect, int radius, int r, int g, int b, int a){
  FillRoundedRect(rect, radius, Color(r, g, b, a));
}

void App::FillRoundedRect(Vec4 rect, int radius, Color color){
  SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
  SDL_Rect wRect = {(int)rect.x+radius, (int)rect.y, (int)rect.w-(radius*2), (int)rect.h};
  SDL_RenderFillRect(gRenderer, &wRect);
  SDL_Rect hRect = {(int)rect.x, (int)rect.y+radius, (int)rect.w, (int)rect.h-(radius*2)};
  SDL_RenderFillRect(gRenderer, &hRect);

  if(radius >= 1){
    SDL_Point *points = new SDL_Point[(int)pow(radius*2, 2)];

    int count = 0;
    for(int x = 0; x < radius; x++){
      for(int y = 0; y < radius; y++){
        double circle = pow(x, 2) + pow(y, 2) - pow(radius, 2);
        if(circle <= 0.0){
          points[count] = {(int)(rect.x + rect.w) - radius + x, (int)(rect.y) + radius - y - 1};
          points[count+1] = {(int)(rect.x) + radius - x - 1, (int)(rect.y) + radius - y - 1};
          points[count+2] = {(int)(rect.x) + radius - x - 1, (int)(rect.y + rect.h) - radius + y};
          points[count+3] = {(int)(rect.x + rect.w) - radius + x, (int)(rect.y + rect.h) - radius + y};
          count += 4;
        }
      }
    } 
    SDL_RenderDrawPoints(gRenderer, points, (int)pow(radius*2, 2));
    delete[] points;
  }
}

Vec2 App::GetMousePosition(){
  return gMousePosition;
}

long int App::GetTime() { 
  return SDL_GetTicks();
}

bool App::IsMouseInVec4(Vec4 rect){
  if(rect.x < gMousePosition.x && gMousePosition.x < rect.x + rect.w && rect.y < gMousePosition.y && gMousePosition.y < rect.y + rect.h){
    return true;
  }
  return false;
}

int App::Draw(Texture *texture, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_RenderCopy(gRenderer, texture->GetData(), NULL, &tRect);
  }
  else{
    cout << "ERROR:Texture is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Texture *texture, Vec4 crop, Vec4 rect){
  if(texture){
    SDL_Rect tRect = {(int)rect.x, (int)rect.y, (int)rect.w, (int)rect.h};
    SDL_Rect tCrop = {(int)crop.x, (int)crop.y, (int)crop.w, (int)crop.h};
    SDL_RenderCopy(gRenderer, texture->GetData(), &tCrop, &tRect);
  }
  else{
    cout << "ERROR:Texture is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Object *object){
  if(object){
    if(!object->IsHidden()){
      Draw(object->GetTexture().get(), object->GetRect());
    }
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(UIObject* uiObject){
  if(uiObject){
    if(!uiObject->IsHidden()){
      if(uiObject->GetTexture().get()){
        Draw(uiObject->GetTexture().get(), uiObject->GetRect() - uiObject->GetOrigin());
      }
      else{
        FillRoundedRect(uiObject->GetRect() - uiObject->GetOrigin(), uiObject->GetRadius(), uiObject->GetColor());
      }
    }
  }
  else{
    cout << "ERROR:UIObject is a nullptr" << endl;
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

int App::Draw(Particle *particle){
  if(particle){
    if(!particle->IsHidden()){ 
      Draw(particle->GetTexture().get(), particle->GetRect());
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
      Draw(particles[i]->GetTexture().get(), particles[i]->GetRect());
    }
  }

  for(int i = 0; i < particleSystems.size(); i++){
    if(!particleSystems[i]->IsHidden()){
      for(int j = 0; j < particleSystems[i]->GetParticles().size(); j++){
          Draw(particleSystems[i]->GetParticles()[j]->GetTexture().get(), particleSystems[i]->GetParticles()[j]->GetRect());
      }
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

bool App::SetContact(Object* o1, Object* o2, bool enabled){
  for (b2ContactEdge* edge = o1->GetBody()->GetContactList(); edge; edge = edge->next){
    if(edge->contact->GetFixtureB()->GetBody() == o2->GetBody()){
      if(edge->contact->IsTouching()){
        edge->contact->SetEnabled(enabled);
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
  gSoloud->setGlobalVolume(value);
}

bool App::IsMouseClicked(int MOUSE_TYPE){
  return gMouseClick[MOUSE_TYPE];
}

bool App::IsLeftMouse() { 
  return gMouseClick[MOUSE_LEFT];
}

bool App::IsMiddleMouse() { 
  return gMouseClick[MOUSE_MIDDLE];
}

bool App::IsRightMouse() { 
  return gMouseClick[MOUSE_RIGHT];
}

void App::SetPhysicsScale(int scale) { 
  gScale = scale;
}