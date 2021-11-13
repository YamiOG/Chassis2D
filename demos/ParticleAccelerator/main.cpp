#include <iostream>
#include <vector>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

bool running = true;

Texture texture;

Timer spawner;

ParticleSystem pSystem;

vector<Particle> particleArray = vector<Particle>();

int main(int argc, char *argv[]){
  app.Setup("ParticleAccelerator", 1500, 800, Vec2(0, 9.8), 5, 5);
  app.SetPhysicsScale(8);

  texture.Setup("icon1.png");

  spawner.Setup(3000);

  pSystem.Setup(0, 180, 1, 2, 50);
  pSystem.SetParticle(Vec4(0, 700, 50, 50), 5000);
  pSystem.SetTexture(&texture);

  while(!app.ShouldClose()){
    app.PhysicsUpdate();

    app.StartParticleSystem(&pSystem, Vec2(300, 700), 10000);

    app.Clear();
    app.DrawParticles();
    app.Present();
  }
  return 0;
}
