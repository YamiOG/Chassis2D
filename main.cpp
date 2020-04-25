#include <iostream>
#include <Box2D/Box2D.h>

#include "Chassis2D.h"

using namespace std;

const int scale = 16;

App a;

Object o; 
Object ground;

Sound s;
Sound m;

Text t;

float32 timeStep = 1/60.0f;

bool running = true;

void EventHandler(){
  SDL_Event ev = a.GetEvent();
  while(a.CheckEvents()){
    if(ev.type == SDL_QUIT){
      running = false;
    }
  }

  b2Vec2 motion = b2Vec2(0,o.GetVelocity().y);
  if(a.IsPressed(SDL_SCANCODE_D)){
    motion.x = 10;
    s.Play();
  }
  if(a.IsPressed(SDL_SCANCODE_A)){
    motion.x = -10;
    s.Play();
  }
  o.ApplyConstVelocity(motion);
}

void RenderHandler(){
  a.RClear(0, 0, 0);

  o.Draw(a); 

  t.Draw(a);

  a.RPresent();
}

int main(int argc, char *argv[]){
  a.Setup("Testing", 1600, 900, b2Vec2(0, 70), 8, 3);
  a.SetPhysicsFPS(60);

  o.Setup(a, 100, 100, 100, 100, 0, 0, 0, true, scale);
  ground.Setup(a, 0, 900, 1600, 10, 0, 0, 0, false, scale);
  o.SetTexture(Texture(a, "test.png", 1, 1, false));

  a.SetMusicVolume(50.0f);

  s.Setup("soundeffect.wav", false);
  s.SetVolume(30.0f);

  m.Setup("DeepSpace.mp3", true);
  m.Play();

  Font f = Font("Roboto-Bold.ttf", 100, 0, 0, 200, true);
  f.SetDivisor(10);

  t.Setup(400, 100, f, "Random text");

  while(running){
    EventHandler();
    RenderHandler();
    a.PhysicsUpdate();
  }
  
  return 0;
}
