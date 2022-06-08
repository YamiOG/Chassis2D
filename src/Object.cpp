#include "Object.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <box2d/box2d.h>

Object::Object(float x, float y, float w, float h, int categoryBits, int maskBits){
  Setup(x, y, w, h, categoryBits, maskBits);
}

int Object::Setup(float x, float y, float w, float h, int categoryBits, int maskBits){
  return Static(x, y, w, h, categoryBits, maskBits);
}

int Object::Static(float x, float y, float w, float h, int categoryBits, int maskBits){
  if(gWorld != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/gScale, (y + (height/2))/gScale);
    shape.SetAsBox((width/2)/gScale, (height/2)/gScale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    bodyDef.type = b2_staticBody;

    body = gWorld->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }

  return 0;
}

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits){
  Setup(x, y, w, h, friction, density, restitution, categoryBits, maskBits);
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits){
  return Dynamic(x, y, w, h, friction, density, restitution, categoryBits, maskBits);
}

int Object::Dynamic(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits){
  if(gWorld != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/gScale, (y + (height/2))/gScale);
    shape.SetAsBox((width/2)/gScale, (height/2)/gScale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    bodyDef.type = b2_dynamicBody;
    fixture.friction = friction;
    fixture.density = density;
    fixture.restitution = restitution;

    body = gWorld->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic){
  Setup(x, y, w, h, friction, density, restitution, categoryBits, maskBits, isDynamic);
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic){
  if(gWorld != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;

    bodyDef.position.Set((x + (width/2))/gScale, (y + (height/2))/gScale);
    shape.SetAsBox((width/2)/gScale, (height/2)/gScale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    if(isDynamic){
      bodyDef.type = b2_dynamicBody;
      fixture.friction = friction;
      fixture.density = density;
      fixture.restitution = restitution;
    }
    else{
      bodyDef.type = b2_staticBody;
    }

    body = gWorld->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->GetUserData().pointer = (uintptr_t)this;
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}

Object::~Object(){
  if(gWorld != nullptr){
    gWorld->DestroyBody(body);
  }
}

void Object::SetTexture(Texture* t){
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2(0,0);
  size = Vec2(width, height);
}

void Object::SetTexture(Texture* t, int width, int height){
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2(0,0);
  size = Vec2(width, height);
}

void Object::SetTexture(Texture* t, int xOffset, int yOffset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2(xOffset, yOffset);
  size = Vec2(width, height);
}

void Object::SetTexture(Texture* t, Vec2 offset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  this->offset = offset;
  size = Vec2(width, height);
}

void Object::SetTexture(Texture* t, int xOffset, int yOffset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2(xOffset, yOffset);
  this->size = size;
}

void Object::SetTexture(Texture* t, Vec2 offset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  this->offset = offset;
  this->size = size;
}

Vec4 Object::GetCollisionBox(){
  if(body){
    return Vec4((body->GetPosition().x * gScale) - (width / 2) + origin.x, (body->GetPosition().y * gScale) - (height / 2) + origin.x, width, height );
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return Vec4(0.f, 0.f, 0.f, 0.f);
}

Vec4 Object::GetRect() {
  if(body){ 
    return Vec4((body->GetPosition().x * gScale) - (width / 2) + offset.x, (body->GetPosition().y * gScale) - (height / 2) + offset.y, size.x, size.y );
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return Vec4(0.f, 0.f, 0.f, 0.f);
}

int Object::ApplyConstVelocity(Vec2 velocity){
  if(body){
    velocity.Subt(GetVelocity());
    velocity.Multi(body->GetMass());
    body->ApplyLinearImpulse( b2Vec2(velocity.x, velocity.y), body->GetWorldCenter(), true);
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
    return -1;
  }
  return 0;
}

int Object::ApplyConstVelocity(Vec2 velocity, bool jumping){
  if(body){
    velocity.Subt(GetVelocity());
    velocity.Multi(body->GetMass());
    if(jumping){
      velocity.y = 0;
    }
    body->ApplyLinearImpulse( b2Vec2(velocity.x, velocity.y), body->GetWorldCenter(), true);
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
    return -1;
  }
  return 0;
}

void Object::SetSensor(float x, float y, float w, float h, int categoryBits, int maskBits, int id){
  if(body){
    b2FixtureDef tmpFixture;
    b2PolygonShape tmpShape;
    tmpShape.SetAsBox(w/2/gScale, h/2/gScale, b2Vec2((x-width/2)/gScale, (y-height/2)/gScale), 0);
    tmpFixture.shape = &tmpShape;

    tmpFixture.isSensor = true;
    tmpFixture.filter.categoryBits = categoryBits;
    tmpFixture.filter.maskBits = maskBits;

    body->CreateFixture(&tmpFixture)->GetUserData().pointer = (uintptr_t)id;
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
}

void Object::SetVelocity(Vec2 velocity) { 
  if(body) body->SetLinearVelocity(b2Vec2(velocity.x, velocity.y)); 
}

void Object::SetVelocity(float magnitude, float angle){
  if(body){
    b2Vec2 velocity = b2Vec2(cos(angle * M_PI / 180), -sin(angle * M_PI / 180));
    velocity *= magnitude;
    body->SetLinearVelocity(velocity); 
  }
}

void Object::RotationFixed(bool fixed) { 
  if(body) body->SetFixedRotation(fixed);
}

void Object::ApplyImpulse(Vec2 velocity) { 
  velocity.Multi(body->GetMass()); if(body) body->ApplyLinearImpulse(b2Vec2(velocity.x, velocity.y), body->GetWorldCenter(), true);
}

Vec2 Object::GetVelocity() { 
  return (body) ? Vec2(body->GetLinearVelocity()) : Vec2(0,0); 
}

void Object::SetActive(bool set) {
   if(body) body->SetAwake(set); 
}

void Object::SetPosition(Vec2 position) { 
  if(body) body->SetTransform(*Vec2(position - origin).ToB2(), 0);
}

void Object::SetBullet(bool bullet) { 
  if(body) body->SetBullet(bullet); 
}

float Object::GetMass() { 
  return body->GetMass(); 
}

float Object::GetAngle() { 
  return body->GetAngle();
} 

bool Object::IsActive() { 
  return (body) ? body->IsAwake() : false;
}