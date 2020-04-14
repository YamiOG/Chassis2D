#include <iostream>
#include <Box2D/Box2D.h>

#include "Chassis.h"
#include "Object.h"
#include "Texture.h"

using namespace std;

const int scale = 16;

Chassis c;

Object o; 
Object ground;

float32 timeStep = 1/60.0f;

bool running = true;

void EventHandler(){
  SDL_Event ev = c.GetEvent();
  while(c.CheckEvents()){
    if(ev.type == SDL_QUIT){
      running = false;
    }
  }

  b2Vec2 motion = b2Vec2(0,o.GetVelocity().y);
  if(c.IsPressed(SDL_SCANCODE_D)){
    motion.x = 10;
  }
  if(c.IsPressed(SDL_SCANCODE_A)){
    motion.x = -10;
  }
  o.ApplyConstVelocity(motion);
}

void RenderHandler(){
  c.RClear();

  o.Draw(c); 

  c.RPresent();
}

int main(int argc, char *argv[]){
  c.Setup("Testing", 1600, 900, b2Vec2(0, 70), 8, 3);
  c.SetPhysicsFPS(60);

  o.Setup(c, 100, 100, 100, 100, 0, 0, 0, true, scale);
  ground.Setup(c, 0, 900, 1600, 10, 0, 0, 0, false, scale);
  o.SetTexture(Texture(c, "test.png", 1, 1, false));

  while(running){
    EventHandler();
    RenderHandler();
    c.PhysicsUpdate();
  }
  
  return 0;
}
