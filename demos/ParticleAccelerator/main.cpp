#include <iostream>
#include <vector>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

bool running = true;

Texture texture;

ParticleSystem pSystem;

int main(int argc, char *argv[]){
  app.Setup("ParticleAccelerator", 1500, 800, Vec2(0, 9.8), 5, 5);
  app.SetPhysicsScale(8);

  texture.Setup("icon1.png");

  pSystem.Setup(0, 180, 1, 10, 50);
  pSystem.SetParticle(Vec4(0, 700, 50, 50), 1000);
  pSystem.SetTexture(&texture);

  app.StartParticleSystem(&pSystem, Vec2(300, 700), -1);

  while(!app.ShouldClose()){
    app.PhysicsUpdate();
    app.Clear();
    app.DrawParticles();
    app.Present();
  }
  return 0;
}
