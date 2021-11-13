#include "Particle.h"

#include "Chassis2D.h"

#include <box2d/box2d.h>

Particle::Particle(Vec4 rect, int lifetime){
  Setup(rect, lifetime);
}

int Particle::Setup(Vec4 rect, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = rect.w;
    height = rect.h;

    bodyDef.position.Set((rect.x + (width/2))/c2Scale, (rect.y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = 0.0f;
    fixture.density = 1.0f;
    fixture.restitution = 0.6f;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::Particle(Vec4 rect, float friction, float density, float restitution, int lifetime){
  Setup(rect, friction, density, restitution, lifetime);
}

int Particle::Setup(Vec4 rect, float friction, float density, float restitution, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = rect.w;
    height = rect.h;

    bodyDef.position.Set((rect.x + (width/2))/c2Scale, (rect.y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::Particle(Vec4 rect, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  Setup(rect, friction, density, restitution, categoryBits, maskBits, lifetime);
}

int Particle::Setup(Vec4 rect, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = rect.w;
    height = rect.h;

    bodyDef.position.Set((rect.x + (width/2))/c2Scale, (rect.y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::Particle(float x, float y, float w, float h, int lifetime){
  Setup(x, y, w, h, lifetime);
}

int Particle::Setup(float x, float y, float w, float h, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/c2Scale, (y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::Particle(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime){
  Setup(x, y, w, h, friction, density, restitution, lifetime);
}

int Particle::Setup(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/c2Scale, (y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::Particle(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  Setup(x, y, w, h, friction, density, restitution, categoryBits, maskBits, lifetime);
}

int Particle::Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  if(c2World != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/c2Scale, (y + (height/2))/c2Scale);
    shape.SetAsBox((width/2)/c2Scale, (height/2)/c2Scale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = c2World->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;

    this->lifetime = lifetime;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Particle::~Particle(){
  //texture = nullptr;
}
