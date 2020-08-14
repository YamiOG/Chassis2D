#include "Particle.h"

#include "Chassis2D.h"

Particle::Particle(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale){
  Setup(width, height, friction, density, restitution, lifetime, texture, scale);
}

int Particle::Setup(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale){
  this->width = width;
  this->height = height;
  this->lifetime = lifetime;

  shared_ptr<Texture> sharedTex(texture);
  this->texture = sharedTex;

  this->scale = scale;

  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  return 0;
}

int Particle::Create(App *a, int x, int y){
  if(a->GetWorld() != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    this->a = a; 

    bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
    shape.SetAsBox((width/2)/scale, (height/2)/scale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = PARTICLE;
    fixture.filter.maskBits = NULL;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = a->GetWorld()->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->SetUserData(this);
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::~Particle(){
}
