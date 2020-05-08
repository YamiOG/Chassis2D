#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class Particle{
 private:
  int scale;
  int lifetime, time;
  int width, height;
  b2Vec2 velocity;
  Texture *texture;

  b2Body *body;
  b2BodyDef bodyDef;
  b2FixtureDef fixture;
  b2PolygonShape shape;

  float friction, density, restitution;

 public:
  Particle(){}
  Particle(int width, int height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale);
  void Setup(int width, int height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale);

  b2Body *GetBody(){return body;}
  void SetBody(b2Body *sBody) {body = sBody;}
  b2BodyDef *GetBodyDef() {return &bodyDef;}
  b2FixtureDef *GetFixtureDef() {return &fixture;}
  Texture *GetTexture() { return texture; }
  int GetTime() {return time;}
  SDL_Rect GetScaledPosition();
  int GetLifetime() { return lifetime;}

  int Create(int x, int y);
  void ApplyInitalImpulse() { if(body) body->ApplyLinearImpulse( velocity, body->GetWorldCenter(), true);}
  void ApplyImpulse(b2Vec2 v) { if(body) body->ApplyLinearImpulse( v, body->GetWorldCenter(), true);}
  void SetLifetime(int set) {lifetime = set;}
  void SetTime(int set) {time = set;}

  //Destructor
  ~Particle();
};

#endif
