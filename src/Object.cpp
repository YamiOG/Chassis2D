#include "Object.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <box2d/box2d.h>

Object::Object(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isD, int scale){
  Setup(a, x, y, w, h, friction, density, restitution, categoryBits, maskBits, isD, scale);
}

int Object::Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isD, int scale){
  if(a->GetWorld() != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    this->a = a;

    width = w;
    height = h;
    this->scale = scale;

    bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
    shape.SetAsBox((width/2)/scale, (height/2)/scale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = categoryBits;
    fixture.filter.maskBits = maskBits;

    if(isD){
      bodyDef.type = b2_dynamicBody;
      fixture.friction = friction;
      fixture.density = density;
      fixture.restitution = restitution;
    }
    else{
      bodyDef.type = b2_staticBody;
    }

    body = a->GetWorld()->CreateBody(&bodyDef);
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
  if(a != nullptr){
    a->GetWorld()->DestroyBody(body);
    body = nullptr;
    a = nullptr;
  }
}

Vec4 Object::GetRect() {
  if(body){
    return Vec4((body->GetPosition().x * scale) - (width / 2), (body->GetPosition().y * scale) - (height / 2), width, height );
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return Vec4(0.f, 0.f, 0.f, 0.f);
}

int Object::ApplyConstVelocity(Vec2 v){
  if(body){
    v.Subt(GetVelocity());
    v.Multi(body->GetMass());
    body->ApplyLinearImpulse( *v.ToB2(), body->GetWorldCenter(), true);
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
    return -1;
  }
  return 0;
}

int Object::ApplyConstVelocity(Vec2 v, bool jumping){
  if(body){
    v.Subt(GetVelocity());
    v.Multi(body->GetMass());
    if(jumping){
      v.y = 0;
    }
    body->ApplyLinearImpulse( *v.ToB2(), body->GetWorldCenter(), true);
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
    tmpShape.SetAsBox(w/2/scale, h/2/scale, b2Vec2((x-width/2)/scale, (y-height/2)/scale), 0);
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

//void SetBody(b2Body *body) {this->body = body; }
void Object::SetVelocity(Vec2 v) { 
  if(body) body->SetLinearVelocity(*v.ToB2()); 
}

void Object::RotationFixed(bool fixed) { 
  if(body) body->SetFixedRotation(fixed);
}

void Object::ApplyImpulse(Vec2 v) { 
  v.Multi(body->GetMass()); if(body) body->ApplyLinearImpulse( *v.ToB2(), body->GetWorldCenter(), true);
}

Vec2 Object::GetVelocity() { 
  return (body) ? Vec2(body->GetLinearVelocity()) : Vec2(0,0); 
}

void Object::SetActive(bool set) {
   if(body) body->SetAwake(set); 
}

void Object::SetPosition(Vec2 position) { 
  if(body) body->SetTransform(*position.ToB2(), 0);
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