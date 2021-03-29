#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;
Sound song;
Font font;
Text text;

bool running = true;

int main(int argc, char *argv[]){
  app.Setup("Audio", 300, 100);

  font.Setup("Squarewave.ttf", 30, 3);
  
  text.Setup(150, 50, "popcorn_remix.mp3", &font);

  song.Setup(&app, "popcorn_remix.mp3");
  song.Play();

  while(running){
    /*while(app.CheckEvents()){
      if(app.ShouldClose()){
        running = false;
      }
    }*/

    app.Clear(0, 0, 0);

    app.Draw(&text);

    app.Present();
  }
  return 0;
}