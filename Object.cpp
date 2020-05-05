#include "Object.h"

#include "Chassis2D.h"

Object::Object(float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale){
  /*b2BodyDef bodyDef;
  b2FixtureDef fixture;
  b2PolygonShape shape;*/

  width = w;
  height = h;
  scale = setScale;

  bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
  shape.SetAsBox((width/2)/scale, (height/2)/scale);
  fixture.shape = &shape;

  if(isD){
    bodyDef.type = b2_dynamicBody;
    fixture.density = density;
    fixture.friction = friction;
    fixture.restitution = restitution;
  }
  else{
    bodyDef.type = b2_staticBody;
  }
  //body = a.GetWorld()->CreateBody(&bodyDef);
  //body->CreateFixture(&fixture);

  //body->SetUserData(this);
}

int Object::Setup(float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale){
  /*b2BodyDef bodyDef;
    b2FixtureDef fixture;
  b2PolygonShape shape;*/

  width = w;
  height = h;
  scale = setScale;

  bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
  shape.SetAsBox((width/2)/scale, (height/2)/scale);
  fixture.shape = &shape;

  if(isD){
    bodyDef.type = b2_dynamicBody;
    fixture.density = density;
    fixture.friction = friction;
    fixture.restitution = restitution;
  }
  else{
    bodyDef.type = b2_staticBody;
  }
  //body = a.GetWorld()->CreateBody(&bodyDef);
  //body->CreateFixture(&fixture);

  //body->SetUserData(this);
  return 0;
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

void Object::ApplyConstVelocity(b2Vec2 v){
  if(body){
    v -= GetVelocity();
    v *= body->GetMass();
    body->ApplyLinearImpulse( v, body->GetWorldCenter(), true);
  }
}

Object::~Object(){
  delete texture;
}
