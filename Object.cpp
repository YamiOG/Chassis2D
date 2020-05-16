#include "Object.h"

#include "Chassis2D.h"

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int setScale){

  width = w;
  height = h;
  scale = setScale;

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
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int setScale){

  width = w;
  height = h;
  scale = setScale;

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
  return 0;
}

Object::~Object(){
  delete texture;
}

SDL_Rect Object::GetScaledPosition() {
  SDL_Rect rect = {0,0,0,0};
  if(body){
    rect = { (int)((body->GetPosition().x * scale) - (width / 2)), (int)((body->GetPosition().y * scale) - (height / 2)), (int)width, (int)height };
  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
  return rect;
}

void Object::ApplyConstVelocity(Vec2 v){
  if(body){
    v.Subt(GetVelocity());
    v.Multi(body->GetMass());
    body->ApplyLinearImpulse( v.ToB2(), body->GetWorldCenter(), true);
  }
}

void Object::SetMaskBit(uint16 maskBit){
}
