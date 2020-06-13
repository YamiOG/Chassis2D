#include "App.h"

#include "Chassis2D.h"

App::App(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI){
    this->width = width;
    this->height = height;

    this->velocityI = velocityI;
    this->positionI = positionI;

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

    world = new b2World(gravity.ToB2());
    if (!world) {
        cout << "ERROR:b2World Creation Failed" << endl;
    }

    world->SetContactListener(this);
}

int App::Setup(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI){
  this->width = width;
  this->height = height;

  this->velocityI = velocityI;
  this->positionI = positionI;

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

  world = new b2World(gravity.ToB2());
  if (!world) {
    cout << "ERROR:b2World Creation Failed" << endl;
    return -1;
  }

  world->SetContactListener(this);

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
  for(int i = 0; i < particleSystems.size(); i++){
    if(SDL_GetTicks() >= particleSystems[i]->GetTime()){
      particleSystems.erase(particleSystems.begin()+i);
    }
    else{
      ParticleSystem* ps = particleSystems[i];
      if(ps->GetCount() > 0){
        
      }

      if(SDL_GetTicks() >= ps->GetDelayTime()){
        if(ps->GetCount() < ps->GetAmount()){
          SpawnParticle(ps->GetBaseParticle(), ps->RandomizePosition(ps->GetPosition()), ps->GetParticleVelocity());
          ps->SetCount(ps->GetCount()+1);

          ps->GetSpawnTimes().push_back(SDL_GetTicks());
          ps->SetDelayTime(SDL_GetTicks()+ps->GetDelayTime());
        }
      }

      for(int i = 0; i < ps->GetSpawnTimes().size(); i++){
        if(SDL_GetTicks() >= ps->GetLifetime() + ps->GetSpawnTimes()[i]){
          ps->SetCount(ps->GetCount()-1);

          ps->GetSpawnTimes().erase(ps->GetSpawnTimes().begin()+i);
        }
      }
    }
  }

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

void App::FillRect(SDL_Rect rect, int r, int g, int b){
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

bool App::IsMouseInVec4(Vec4 rect){
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
    SDL_Rect rect = o->GetRect().ToSDL();
    SDL_RenderCopy(renderer, o->GetTexture()->GetData(), NULL, &rect);
  }
  else{
    cout << "ERROR:Object is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Text *t){
  if(t){
    SDL_Rect rect = t->GetRect().ToSDL();
    SDL_RenderCopy(renderer, t->GetText(this)->GetData(), NULL, &rect);
  }
  else{
    cout << "ERROR:Text is a nullptr" << endl;
    return -1;
  }
  return 0;
}

int App::Draw(Button *b){
  if(b){
    SDL_Rect rect = b->GetRect().ToSDL();
    SDL_RenderCopy(renderer, b->GetTexture()->GetData(), NULL, &rect);
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
    SDL_Rect rect = p->GetRect().ToSDL();
    SDL_RenderCopy(renderer, p->GetTexture()->GetData(), NULL, &rect);
  }
  else{
    cout << "ERROR:Particle is a nullptr" << endl;
    return -1;
  }
  return 0;
}

void App::DrawParticles(){
  for(int i = 0; i < particles.size(); i++){
    SDL_Rect rect = particles[i]->GetRect().ToSDL();
    SDL_RenderCopy(renderer, particles[i]->GetTexture()->GetData(), NULL, &rect);
  }
}

bool App::CheckButton(Button *b){
  if(IsMouseInVec4(b->GetRect())){
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

int App::SpawnParticle(Particle *p, Vec2 pos, Vec2 velocity){
  if(p){
    Particle *tmp;
    tmp = new Particle(*p);

    //Body Setup
    tmp->Create(pos.x, pos.y);

    tmp->SetBody(world->CreateBody(tmp->GetBodyDef()));
    tmp->GetBody()->CreateFixture(tmp->GetFixtureDef());
    tmp->GetBody()->SetUserData(tmp);
    
    //Inital Impulse
    tmp->ApplyImpulse(velocity);

    //Timer
    tmp->SetTime(SDL_GetTicks() + tmp->GetLifetime());

    //particles.push_back(shared_ptr<Particle>(tmp));   

    particles.push_back(tmp);   

  }
  else{
    cout << "ERROR:Particle is NULL" << endl;
    return -1;
  }
  return 0;
}

int App::StartParticleSystem(ParticleSystem* ps, Vec2 pos, int time){
  if(ps){
    ParticleSystem *tmp = new ParticleSystem(*ps);

    if(time == -1){
      tmp->SetTime(-1);
    }
    else{
      tmp->SetTime(SDL_GetTicks()+time);
      tmp->SetDelayTime(SDL_GetTicks()+tmp->GetDelayTime());
    }

    tmp->SetPosition(pos);

    particleSystems.push_back(tmp);  
  }
  else{
    cout << "ERROR:ParticleSystem is NULL" << endl;
    return -1;
  }
  return 0;
}

int App::StartParticleSystem(ParticleSystem* ps, Vec2 pos){
  if(ps){
    for(int i = 0; i < ps->GetAmount(); i++){
      SpawnParticle(ps->GetBaseParticle(), ps->RandomizePosition(pos), ps->GetParticleVelocity());
    }
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
      return true;
    }
  }
  return false;
}

bool App::IsSensorColliding(Object *o, int id){
  for (b2ContactEdge* edge = o->GetBody()->GetContactList(); edge; edge = edge->next){
    if((intptr_t)edge->contact->GetFixtureA()->GetUserData() == id){
      return true;
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

void App::BeginContact(b2Contact* contact){
  
}

void App::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){
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
  for(int i = 0; i < contacts.size(); i++){
    if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(0)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(0)->GetBody()){
      if(contact->GetFixtureA()->GetBody() == contacts[i]->GetObject(1)->GetBody() || contact->GetFixtureB()->GetBody() == contacts[i]->GetObject(1)->GetBody()){
        contacts.erase(contacts.begin()+i); 
      }
    }
  }
}
