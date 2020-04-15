#ifndef CHASSIS_H
#define CHASSIS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

using namespace std;

class Chassis{
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
  Chassis(){}
  Chassis(const char* title, int width, int height, b2Vec2 setGravity, int sVelocityI, int sPositionI);
  int Setup(const char* title, int width, int height, b2Vec2 setGravity, int sVelocityI, int sPositionI);
  void PhysicsUpdate();
  void SetPhysicsFPS(int setFPS) { pFPS = setFPS; }
  bool CheckEvents(){return SDL_PollEvent(&ev);}

  //Render Cmds
  void RClear();
  void RFillRect(SDL_Rect rect, int r, int g, int b);
  void RPresent();

  //Get Cmds
  SDL_Event GetEvent() { return ev; }
  b2World* GetWorld() { return world; }
  SDL_Renderer *GetRenderer(){return renderer;}
  SDL_Window *GetWindow(){return window;}
  bool IsPressed(int k);
  bool JustPressed(int k);
};

#endif
