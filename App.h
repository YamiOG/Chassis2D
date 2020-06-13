#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Vec2.h"

using namespace std;

class App : public b2ContactListener{
 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event ev;
  int width, height;
  float mVol = 1.f;
  float cVol = 1.f;

  int velocityI, positionI;
  b2World* world;

  int pFPS;
  int32 pTime;

  vector<Particle*> particles;
  vector<ParticleSystem*> particleSystems;
  vector<shared_ptr<Contact>> contacts;

 public:
  App(){}
  App(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);
  int Setup(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);
  void PhysicsUpdate();
  void SetPhysicsFPS(int pFPS) { this->pFPS = pFPS; }
  bool CheckEvents(){return SDL_PollEvent(&ev);}

  //Render Cmds
  void Clear();
  void Clear(int r, int g, int b);
  void FillRect(SDL_Rect rect, int r, int g, int b);
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
  int AddObject(Object* o);
  int SpawnParticle(Particle* p, Vec2 pos, Vec2 velocity);
  int StartParticleSystem(ParticleSystem* ps, Vec2 pos);
  int StartParticleSystem(ParticleSystem* ps, Vec2 pos, int time);
  int AddContact(Contact *c);

  //Get Cmds
  SDL_Event GetEvent() { return ev; }
  b2World* GetWorld() { return world; }
  SDL_Renderer *GetRenderer(){return renderer;}
  SDL_Window *GetWindow(){return window;}
  SDL_Point GetMouse();
  Uint32 GetTime() { return SDL_GetTicks(); }
  bool IsMouseInVec4(Vec4 rect);
  bool IsPressed(int k);
  bool JustPressed(int k);
  bool CheckButton(Button *b);
  bool IsColliding(Object* o1, Object* o2);
  bool OnGround(Entity* e);
  bool IsSensorColliding(Object *o, int id);

  //ContactListener
  void BeginContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
  void EndContact(b2Contact* contact);

  //Destructor
  ~App();
};

#endif
