#include <iostream>
#include <Box2D/Box2D.h>

#include "Chassis.h"
#include "Object.h"

using namespace std;

const int scale = 16;

Chassis c;

Object o; 

float32 timeStep = 1/60.0f;

bool running = true;

void EventHandler(){
  SDL_Event ev = c.GetEvent();
  while(c.CheckEvents()){
    if(ev.type == SDL_QUIT){
      running = false;
    }
  }
}

void RenderHandler(){
  c.RClear();

  c.RFillRect(o.GetScaledPosition(), 100, 100, 100);

  c.RPresent();
}

int main(int argc, char *argv[]){
  c.Setup("Testing", 1600, 900, b2Vec2(0, 70), 8, 3);
  c.SetPhysicsFPS(60);

  o.Setup(c, 100, 100, 10, 10, 0, 0, 0, true, scale);

  while(running){
    EventHandler();
    RenderHandler();
    c.PhysicsUpdate();
  }
  
  return 0;
}
