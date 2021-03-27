#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

Sound sGas;

bool running = true;

int main(int argc, char *argv[]){
  app.Setup("Audio", 1578, 826);

  sGas.Setup(&app, "Manuel - Gas Gas Gas.mp3");

  sGas.Play();

  while(running){
    while(app.CheckEvents()){
      if(app.GetEvent()->type == SDL_QUIT){
        running = false;
      }
    }

    app.Clear();
    app.Present();
  }
  return 0;
}