#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;
Sound song;
Font font;
Text text;

int main(int argc, char *argv[]){
  app.Setup("Audio", 300, 100);

  font.Setup("Squarewave.ttf", 30, 4);
  
  text.Setup(150, 50, "popcorn_remix.mp3", &font);
  text.SetOriginCenter(true);

  song.Setup(&app, "popcorn_remix.mp3");
  song.Play();

  while(!app.ShouldClose()){
    app.Update();

    app.Clear(0, 0, 0);
    app.Draw(&text);
    app.Present();
  }
  return 0;
}