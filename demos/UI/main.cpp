#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

UI ui;

UIObject uiObject;
Button button;

bool running = true;

int main(int argc, char *argv[]){
  app.Setup("UI", 400, 400);
  app.SetUI(&ui);

  uiObject.Setup(200, 200, 100, 100);
  uiObject.SetColor(170, 0, 0);
  uiObject.SetOriginCenter(true);
  uiObject.SetRadius(10);

  button.Setup(20, 200, 30, 30);
  button.SetColor(0, 200, 0);
  button.SetOriginCenter(true);
  button.SetRadius(5);

  ui.AddUIObject(&uiObject);
  ui.AddButton(&button);

  while(!app.ShouldClose()){
    app.Update();

    app.Clear();
    app.DrawUI();
    app.Present();
  }
  return 0;
}
