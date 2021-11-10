#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;
Sound song;
Font font;
Text text;
Timer changeTime;

bool tColor = false;

int main(int argc, char *argv[]){
  app.Setup("Audio", 300, 100);

  font.Setup("Squarewave.ttf", 30, 255, 192, 203);
  
  text.Setup(150, 50, "popcorn_remix.mp3", &font);
  text.SetOriginCenter(true);

  song.Setup("popcorn_remix.mp3");
  song.Play();

  changeTime = Timer(475);

  while(!app.ShouldClose()){
    app.Update();

    if(changeTime.Stopped()){
      if(tColor){
        font.SetColor(255, 192, 203);
        text.SetPosition(145, 45);
        tColor = !tColor;
      }
      else{
        font.SetColor(102, 102, 255);
        text.SetPosition(155, 55);
        tColor = !tColor;
      }
      changeTime.Start();
    }

    app.Clear(0, 0, 0);
    app.Draw(&text);
    app.Present();
  }
  return 0;
}