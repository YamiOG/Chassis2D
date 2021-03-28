#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;

class b2World;
class b2Contact;

namespace SoLoud{
  class Soloud;
}

class App{
 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event *ev = new SDL_Event;
  int width, height;
  float mVol = 1.f;
  float cVol = 1.f;

  b2World* world;
  int velocityI, positionI;

  int pFPS;
  Uint32 pTime;

  SoLoud::Soloud *soloud;
  
  vector<shared_ptr<Particle>> particles;
  vector<shared_ptr<ParticleSystem>> particleSystems;
  vector<shared_ptr<Contact>> contacts;

 public:
  App(){}
  App(const char* title, int width, int height);
  App(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);

  int Setup(const char* title, int width, int height);
  int Setup(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);

  void PhysicsUpdate();
  void SetPhysicsFPS(int pFPS) { this->pFPS = pFPS; }
  bool CheckEvents();

  //Render Cmds
  void Clear();
  void Clear(int r, int g, int b);
  void FillRect(Vec4 rect, int r, int g, int b);
  int Draw(Texture *texture, Vec4 rect);
  int Draw(Texture *texture, Vec4 crop, Vec4 rect);
  int Draw(Object* o);
  int Draw(Text* t);
  int Draw(Button *b);
  int Draw(Particle *p);
  void DrawParticles();
  void Present();

  //Set Cmds
  void SetMusicVolume(float value);
  void SetSFXVolume(float value);
  void SetMasterVolume(float value);
  int SpawnParticle(Particle* p, Vec2 pos, Vec2 velocity);
  int StartParticleSystem(ParticleSystem* ps, Vec2 pos);
  int StartParticleSystem(ParticleSystem* ps, Vec2 pos, int time);
  int AddContact(Contact *c);

  //Get Cmds
  SDL_Event *GetEvent() { return ev; }
  b2World* GetWorld() { return world; }
  SDL_Renderer *GetRenderer(){return renderer;}
  SDL_Window *GetWindow(){return window;}
  SDL_Point GetMouse();
  Uint32 GetTime() { return SDL_GetTicks(); }
  bool IsMouseInVec4(Vec4 rect);
  bool IsPressed(string k);
  bool CheckButton(Button *b);
  bool IsColliding(Object* o1, Object* o2);
  bool OnGround(Entity* e);
  bool IsSensorColliding(Object *o, int id);
  SoLoud::Soloud *GetSoLoud() { return soloud; }

  //ContactListener
  /*void BeginContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
  void EndContact(b2Contact* contact);*/

  //Destructor
  ~App();
};

#endif
