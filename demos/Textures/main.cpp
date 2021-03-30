#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

bool running = true;

Texture texture;

int main(int argc, char *argv[]){
  app.Setup("Textures", 1578, 826);

  texture.Setup(&app, "icon1.png");

  while(app.IsOpen()){
    app.Clear();
    app.Draw(&texture, Vec4(0, 0, 1578, 826));
    app.Present();
  }
  return 0;
}
