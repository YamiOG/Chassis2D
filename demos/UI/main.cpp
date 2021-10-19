#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

UIObject uiObject;

bool running = true;

int main(int argc, char *argv[]){
  app.Setup("UI", 400, 400);

  uiObject.Setup(200, 200, 100, 100);
  uiObject.SetColor(170, 0, 0);
  uiObject.SetOriginCenter(true);
  uiObject.SetRadius(10);

  while(!app.ShouldClose()){
    app.Update();

    app.Clear();
    app.Draw(&uiObject);
    app.Present();
  }
  return 0;
}
