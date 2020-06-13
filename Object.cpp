#include "Object.h"

#include "Chassis2D.h"

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale){
  Setup(x, y, w, h, friction, density, restitution, categoryBits, maskBits, isD, scale);
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale){

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
  return 0;
}

Object::~Object(){
  delete texture;
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

void Object::ApplyConstVelocity(Vec2 v, bool jumping){
  if(body){
    v.Subt(GetVelocity());
    v.Multi(body->GetMass());
    if(jumping){
      v.y = 0;
    }
    body->ApplyLinearImpulse( v.ToB2(), body->GetWorldCenter(), true);
  }
}

void Object::SetSensor(float x, float y, float w, float h, uint16 categoryBits, uint16 maskBits, int id){
  if(body){
    b2FixtureDef tmpFixtureDef;
    b2PolygonShape tmpShape;
    tmpShape.SetAsBox((width/2)/scale, (height/2)/scale, b2Vec2(w/2/scale, h/2/scale), 0);
    tmpFixtureDef.shape = &tmpShape;

    tmpFixtureDef.filter.categoryBits = categoryBits;
    tmpFixtureDef.filter.maskBits = maskBits;

    tmpFixtureDef.isSensor = true;

    b2Fixture *tmpFixture = body->CreateFixture(&tmpFixtureDef);

    tmpFixture->SetUserData((void*)(size_t)id);

  }
  else{
    cout << "ERROR:Object Body is NULL" << endl;
  }
}