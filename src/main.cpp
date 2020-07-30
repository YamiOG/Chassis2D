#include <iostream>
#include <Box2D/Box2D.h>

#include "../chassis/Chassis2D.h"

using namespace std;

const int scale = 16;

App a;

Entity o;
Object g;
Object ground;

Sound s;
Sound m;

Text t;

Button b;

float timeStep = 1.f/60.0f;

bool running = true;

float volume = 100.0f;

Particle p;

ParticleSystem ps;

Timer jumpDelay;
Timer timer;

void EventHandler(){
  SDL_Event ev = a.GetEvent();
  while(a.CheckEvents()){
    if(ev.type == SDL_QUIT){
      running = false;
    }
  }

  Vec2 motion = Vec2(0,o.GetVelocity().y);
  if(a.IsPressed("d")){
    motion.x = 10;
  }
  if(a.IsPressed("a")){
    motion.x = -10;
  }

  if(a.IsPressed("space")){
    if(a.IsSensorColliding(&o, 1)){
      if(jumpDelay.Stopped()){
        o.ApplyImpulse(Vec2(0,-50.0f));
        jumpDelay.Start(700);
      }
    }
  }


  if(a.CheckButton(&b)){
    volume--;
    a.SetMasterVolume(volume);
  }


  o.ApplyConstVelocity(motion, true);
}

void RenderHandler(){
  a.Clear(0, 0, 0);

  a.Draw(&o);

  a.Draw(&t);

  a.Draw(&b);

  a.DrawParticles();

  a.FillRect(o.GetRect(), 200, 100, 1);

  a.FillRect(Vec4(o.GetRect().x+(o.GetRect().w/2), o.GetRect().y+o.GetRect().h, 1, 1), 100, 100, 1);

  a.Present();
}

int main(int argc, char *argv[]){
  a.Setup("Testing", 1600, 900, Vec2(0, 70), 8, 3);
  a.SetPhysicsFPS(60);

  o.Setup(&a, 100, 100, 100, 100, 0, 0.1f, 0, PLAYER, TERRAIN, scale);
  o.RotationFixed(true);

  o.SetTexture(new Texture(&a, "test.png"));

  //Needs to be positioned before ground
  o.SetSensor(o.GetRect().w/2, o.GetRect().h, 0.3f, 0.3f, SENSOR, TERRAIN, 1);

  g.Setup(&a, 0, 900, 1600, 1, 0, 0, 0, TERRAIN, PLAYER | SENSOR, false, scale);

  a.SetMusicVolume(50.0f);

  s.Setup("soundeffect.wav", false);
  s.SetChunkVolume(30.0f);

  m.Setup("DeepSpace.mp3", true);

  Font f = Font("Roboto-Bold.ttf", 100, 10);

  t.Setup(400, 100, "Random text", &f);

  b.Setup(100, 100, 300, 100, new Texture(&a, "test.png"), "Button", &f);

  p.Setup(10, 10, 0.1f, 1.0f, 0.1f, 3000, new Texture(&a, "test.png"), scale);

  ps.Setup(&p, Vec2(0, -5), 1, 1000, 10);

  a.StartParticleSystem(&ps, Vec2(1000, 100), 1000);

  while(running){
    EventHandler();
    RenderHandler();
    a.PhysicsUpdate();
  }
  delete &a;
  return 0;
}
