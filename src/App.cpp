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

  this->velocityI = 1;
  this->positionI = 1;

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

bool App::IsPressed(string k){
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  if(state[SDL_GetScancodeFromName(k.c_str())]){
    return true;
  }
  return false;
}

void App::PhysicsUpdate(){
  if(1000/pFPS <= SDL_GetTicks()-pTime){
    for(int i = 0; i < particleSystems.size();){
      particleSystems[i]->Update(this);

      if(SDL_GetTicks() >= particleSystems[i]->GetTime()){
        particleSystems.erase(particleSystems.begin()+i);
      }
      else{
        i++;
      }
    }

    world->Step(1.0f/pFPS, velocityI, positionI);
    pTime = SDL_GetTicks();
  }
}

bool App::CheckEvents(){
  return SDL_PollEvent(ev);
}

void App::Clear(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void App::Clear(int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}

void App::Present(){
  SDL_RenderPresent(renderer);
}

void App::FillRect(Vec4 rect, int r, int g, int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderFillRect(renderer, rect.ToSDL());
}

/*void App::SetMusicVolume(float value){
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
}*/

SDL_Point App::GetMouse(){
  SDL_Point pos;
  SDL_GetMouseState(&pos.x, &pos.y);
  return pos;
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
    SDL_RenderCopy(renderer, texture->GetData(), NULL, rect.ToSDL());
  }
  else{
    cout << "ERROR:Texture is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Texture *texture, Vec4 crop, Vec4 rect){
  if(texture){
    SDL_RenderCopy(renderer, texture->GetData(), crop.ToSDL(), rect.ToSDL());
  }
  else{
    cout << "ERROR:Texture is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Object *o){
  if(o){
    if(!o->IsHidden()){
      SDL_RenderCopy(renderer, o->GetTexture()->GetData(), NULL, o->GetRect().ToSDL());
    }
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Text *t){
  if(t){
    if(!t->IsHidden()){ 
      SDL_RenderCopy(renderer, t->GetText(this)->GetData(), NULL, t->GetRect().ToSDL());
    }
  }
  else{
    cout << "ERROR:Text is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Button *b){
  if(b){
    if(!b->IsHidden()){ 
      SDL_RenderCopy(renderer, b->GetTexture()->GetData(), NULL, b->GetRect().ToSDL());
      if(!b->GetText()->IsHidden()){ 
        SDL_RenderCopy(renderer, b->GetText()->GetText(this)->GetData(), NULL, b->GetText()->GetRect().ToSDL());
      }
    }
  }
  else{
    cout << "ERROR:Button is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Particle *p){
  if(p){
    if(!p->IsHidden()){ 
      SDL_RenderCopy(renderer, p->GetTexture()->GetData(), NULL, p->GetRect().ToSDL());
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
      SDL_RenderCopy(renderer, particles[i]->GetTexture()->GetData(), NULL, particles[i]->GetRect().ToSDL());
    }
  }

  for(int i = 0; i < particleSystems.size(); i++){
    if(!particleSystems[i]->IsHidden()){
      for(int j = 0; j < particleSystems[i]->GetParticles().size(); j++){
          SDL_RenderCopy(renderer, particleSystems[i]->GetParticles()[j]->GetTexture()->GetData(), NULL, particleSystems[i]->GetParticles()[j]->GetRect().ToSDL());
      }
    }
  }
}

bool App::CheckButton(Button *b){
  if(IsMouseInVec4(b->GetRect())){
    if(ev->type == SDL_MOUSEBUTTONDOWN) {
      if(ev->button.button == SDL_BUTTON_LEFT){
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

int App::SpawnParticle(Particle *p, Vec2 pos, Vec2 velocity){
  if(p){
    Particle *tmp;
    tmp = new Particle(*p);

    //Body Setup
    tmp->Create(this, pos.x, pos.y);

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

int App::StartParticleSystem(ParticleSystem *ps, Vec2 pos, int time){
  if(ps){
    ParticleSystem *tmp = new ParticleSystem(*ps);

    if(time == -1){
      tmp->SetTime(-1);
    }
    else{
      tmp->SetTime(SDL_GetTicks()+time);
    }

    tmp->SetPos(pos);

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

int App::AddContact(Contact *c){
  if(c){
    contacts.push_back(shared_ptr<Contact>(c));
  }
  else{
    cout << "ERROR:Contact is NULL" << endl;
    return -1;
  }
  return 0;
}

/*void App::BeginContact(b2Contact* contact){

}*/

/*void App::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){
  for(int i = 0; i < contacts.size(); i++){
    if(contacts[i]){
      if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(0)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(0)->GetBody()){
        if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(1)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(1)->GetBody()){
          contact->SetEnabled(contacts[i]->GetCollide());
        }
      }
    }
  }
}

void App::EndContact(b2Contact* contact){
  for(int i = 0; i < contacts.size();){
    if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(0)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(0)->GetBody()){
      if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(1)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(1)->GetBody()){
        contacts.erase(contacts.begin()+i);
      }
    }
    else{
      i++;
    }
  }
}*/
