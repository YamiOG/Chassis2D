#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App a;

bool running = true;

Object o;


int main(int argc, char *argv[]){
  a.Setup("Textures", 1578, 826, Vec2(0, 70), 8, 3);

  while(running){
    while(a.CheckEvents()){
      if(a.GetEvent()->type == SDL_QUIT){
        running = false;
      }
    }

    a.Clear();


    a.Present();
  }
  return 0;
}
