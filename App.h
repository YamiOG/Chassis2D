#ifndef APP_H
#define APP_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class App{
 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event ev;
  int width, height;

  int velocityI, positionI;
  b2Vec2 gravity;
  b2World* world;

  int pFPS;
  int32 pTime;

 public:
  App(){}
  App(const char* title, int width, int height, b2Vec2 setGravity, int sVelocityI, int sPositionI);
  int Setup(const char* title, int width, int height, b2Vec2 setGravity, int sVelocityI, int sPositionI);
  void PhysicsUpdate();
  void SetPhysicsFPS(int setFPS) { pFPS = setFPS; }
  bool CheckEvents(){return SDL_PollEvent(&ev);}

  //Render Cmds
  void RClear();
  void RClear(int r, int g, int b);
  void RFillRect(SDL_Rect rect, int r, int g, int b);
  int Draw(Object* o);
  int Draw(Text* t);
  int Draw(Button *b);
  void RPresent();

  //Set Cmds
  void SetMusicVolume(float value);
  int AddObject(Object* o);

  //Get Cmds
  SDL_Event GetEvent() { return ev; }
  b2World* GetWorld() { return world; }
  SDL_Renderer *GetRenderer(){return renderer;}
  SDL_Window *GetWindow(){return window;}
  SDL_Point GetMouse();
  bool IsMouseInRect(SDL_Rect rect);
  bool IsPressed(int k);
  bool JustPressed(int k);
  bool CheckButton(Button *b);

  //Destructor
  ~App();
};

#endif
