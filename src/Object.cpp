#include "Object.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <box2d/box2d.h>

Object::Object(float x, float y, float w, float h){
  Setup(x, y, w, h);
}

int Object::Setup(float x, float y, float w, float h){
  return Static(x, y, w, h);
}

int Object::Static(float x, float y, float w, float h){
  if(gWorld != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;
    texSize = Vec2(w, h);

    bodyDef.position.Set((x + (width/2))/gScale, (y + (height/2))/gScale);
    shape.SetAsBox((width/2)/gScale, (height/2)/gScale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = 0x0001;
    fixture.filter.maskBits = 0xFFFF;

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
    texSize = Vec2(w, h);

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

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution){
  Setup(x, y, w, h, friction, density, restitution);
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution){
  return Dynamic(x , y, w, h, friction, density, restitution);
}

int Object::Dynamic(float x, float y, float w, float h, float friction, float density, float restitution){
  if(gWorld != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

    width = w;
    height = h;
    texSize = Vec2(w, h);

    bodyDef.position.Set((x + (width/2))/gScale, (y + (height/2))/gScale);
    shape.SetAsBox((width/2)/gScale, (height/2)/gScale);
    fixture.shape = &shape;

    fixture.filter.categoryBits = 0x0001;
    fixture.filter.maskBits = 0xFFFF;

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
    texSize = Vec2(w, h);

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
    texSize = Vec2(w, h);

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
  texSize = Vec2(width, height);
}

void Object::SetTexture(Texture* t, int width, int height){
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2(0,0);
  texSize = Vec2((float)width, (float)height);
}

void Object::SetTexture(Texture* t, int xOffset, int yOffset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2((float)xOffset, (float)yOffset);
  texSize = Vec2((float)width, (float)height);
}

void Object::SetTexture(Texture* t, Vec2 offset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  this->offset = offset;
  texSize = Vec2((float)width, (float)height);
}

void Object::SetTexture(Texture* t, int xOffset, int yOffset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  offset = Vec2((float)xOffset, (float)yOffset);
  this->texSize = size;
}

void Object::SetTexture(Texture* t, Vec2 offset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(new Texture(*t));
  texture = sharedTexture;

  this->offset = offset;
  this->texSize = size;
}

Vec4 Object::GetCollisionBox(){
  if(body){
    Vec2 scaledPosition = Vec2(body->GetPosition()) * (float)gScale;
    return Vec4( scaledPosition.x - (width / 2), scaledPosition.y - (height / 2), width, height );
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return Vec4(0.f, 0.f, 0.f, 0.f);
}

Vec4 Object::GetRect() {
  if(body){ 
    Vec2 scaledPosition = Vec2(body->GetPosition()) * (float)gScale;
    Vec2 position = Vec2( scaledPosition.x - (width / 2), scaledPosition.y - (height / 2) );
    return Vec4( position.x + offset.x, position.y + offset.y, texSize.x, texSize.y );
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return Vec4(0.f, 0.f, 0.f, 0.f);
}

int Object::ApplyConstSpeed(Vec2 velocity){
  if(body){
    velocity.Subt(GetVelocity());
    velocity.Multi(body->GetMass());
    velocity.Div((float)gScale);
    body->ApplyLinearImpulse( b2Vec2(velocity.x, velocity.y), body->GetWorldCenter(), true);
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
    return -1;
  }
  return 0;
}

int Object::ApplyConstSpeed(Vec2 velocity, bool jumping){
  if(body){
    velocity.Subt(GetVelocity());
    velocity.Multi(body->GetMass());
    velocity.Div((float)gScale);
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

void Object::SetSensor(float xOffset, float yOffset, float w, float h, int categoryBits, int maskBits, int id){
  if(body){
    b2FixtureDef tmpFixture;
    b2PolygonShape tmpShape;
    tmpShape.SetAsBox(w/2/gScale, h/2/gScale, b2Vec2((xOffset-width/2)/gScale, (yOffset-height/2)/gScale), 0);
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

bool Object::IsSensorColliding(int id){
  for (b2ContactEdge* edge = body->GetContactList(); edge; edge = edge->next){
    if(edge->contact->IsTouching()){
      if((intptr_t)edge->contact->GetFixtureA()->GetUserData().pointer == id){
        return true;
      }
    }
  }
  return false;
}
void Object::SetVelocity(Vec2 velocity) { 
  velocity.Div((float)gScale);
  if(body) body->SetLinearVelocity(b2Vec2(velocity.x, velocity.y)); 
}

void Object::SetVelocity(float magnitude, float angle){
  if(body){
    b2Vec2 velocity = b2Vec2((float)cos(angle * M_PI / 180), (float)-sin(angle * M_PI / 180));
    velocity *= magnitude;
    velocity *= (1.f/gScale);
    body->SetLinearVelocity(velocity); 
  }
}

void Object::SetAngularVelocity(float magnitude){
  if(body){
    body->SetAngularVelocity(magnitude);
  }
}

void Object::RotationFixed(bool fixed) { 
  if(body) body->SetFixedRotation(fixed);
}

void Object::ApplyImpulse(Vec2 impulse) { 
  impulse.Div((float)gScale);
  impulse.Multi(body->GetMass());
  if(body) body->ApplyLinearImpulse(b2Vec2(impulse.x, impulse.y), body->GetWorldCenter(), true);
}

Vec2 Object::GetVelocity() { 
  return (body) ? Vec2(body->GetLinearVelocity()) * (float)gScale : Vec2(0,0); 
}

void Object::SetActive(bool set) {
   if(body) body->SetAwake(set); 
}

void Object::SetPosition(Vec2 position) { 
  if(body) {
    Vec2 centeredPosition = position + Vec2(width/2, height/2);
    body->SetTransform(b2Vec2(centeredPosition.x/gScale, centeredPosition.y/gScale), 0);
  }
}

void Object::SetPosition(Vec2 position, float angle) { 
  if(body) {
    Vec2 centeredPosition = position + Vec2(width/2, height/2);
    body->SetTransform(b2Vec2(centeredPosition.x/gScale, centeredPosition.y/gScale), angle);
  }
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

void Object::SetGravityScale(float value){
  body->SetGravityScale(value);
}

float Object::GetGravityScale(){
  return body->GetGravityScale();
}