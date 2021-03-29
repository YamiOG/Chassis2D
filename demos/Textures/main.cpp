#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App a;

bool running = true;

Texture texture;

int main(int argc, char *argv[]){
  a.Setup("Textures", 1578, 826);

  texture.Setup(&a, "icon1.png");

  while(running){
    /*while(a.CheckEvents()){
      if(a.ShouldClose()){
        running = false;
      }
    }*/

    a.Clear();
    a.Draw(&texture, Vec4(0, 0, 1578, 826));
    a.Present();
  }
  return 0;
}
