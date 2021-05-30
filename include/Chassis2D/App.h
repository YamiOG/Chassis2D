#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

#include "Global.h"
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
  vector<SDL_Event*> eventList;
  bool mouseClicks[3];
  bool close = false;

  int width, height;

  int velocityI, positionI;

  int physicsFPS;
  int pastTime;

  vector<shared_ptr<Particle>> particles;
  vector<shared_ptr<ParticleSystem>> particleSystems;

 public:
  App(){}
  App(const char* title, int width, int height);
  int Setup(const char* title, int width, int height);
  App(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);
  int Setup(const char* title, int width, int height, Vec2 gravity, int velocityI, int positionI);

  SDL_Renderer *GetRenderer() {return c2Renderer;}
  SDL_Window *GetWindow() {return c2Window;}
  SDL_Event *GetEvent() { return c2Event; }
  vector<SDL_Event*> GetEventList() { return eventList; }

  void PhysicsUpdate();
  void SetPhysicsFPS(int physicsFPS) { this->physicsFPS = physicsFPS; }
  int GetPhysicsFPS() { return physicsFPS; }

  void Update();
  bool ShouldClose() { return close; }

  //Render Cmds
  void Clear();
  void Clear(int r, int g, int b);
  void Clear(Color color);
  void FillRect(Vec4 rect, int r, int g, int b);
  int Draw(Texture *texture, Vec4 rect);
  int Draw(Texture *texture, Vec4 crop, Vec4 rect);
  int Draw(Object* object);
  int Draw(Particle *particle);
  int Draw(Text* text);
  int Draw(Button *button);
  void DrawParticles();
  void Present();

  SoLoud::Soloud *GetSoLoud() { return c2Soloud; }
  void SetMasterVolume(float value);
  
  b2World* GetWorld() { return c2World; }
  int SpawnParticle(Particle* particle, Vec2 position, Vec2 velocity);
  int StartParticleSystem(ParticleSystem* particleSystem, Vec2 position, int time);

  string GetInputText();
  Vec2 GetMouse();
  long int GetTime();
  bool IsMouseInVec4(Vec4 rect);
  bool IsPressed(string k);
  bool CheckButton(Button *b);
  bool IsColliding(Object* o1, Object* o2);
  bool IsSensorColliding(Object *o, int id);
  bool IsLeftMouse() { return mouseClicks[0]; }
  bool IsMiddleMouse() { return mouseClicks[1]; }
  bool IsRightMouse() { return mouseClicks[2]; }

  //Destructor
  ~App();
};

#endif
