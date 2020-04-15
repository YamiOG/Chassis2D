#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Sound{
 private:
  Mix_Chunk *w;
  Mix_Music *m;
  bool isMusic;
 public:
  Sound(){}
  Sound(const char* loc, bool music);
  int Setup(const char* loc, bool music);

};

#endif
