#include "Sound.h"

Sound::Sound(const char* loc, bool music){
  if(music){
    m = Mix_LoadMUS(loc);
    if(!m){
      isMusic = true;
      cout << "ERROR:Failed To Load The Music" << endl;
    }
  }
  else{
    isMusic = false;
    w = Mix_LoadWAV(loc);
    if(!w){
      cout << "ERROR:Failed To Load The WAV" << endl;
    }
  }
}

int Sound::Setup(const char* loc, bool music){
  if(music){
    m = Mix_LoadMUS(loc);
    if(!m){
      isMusic = true;
      cout << "ERROR:Failed To Load The Music" << endl;
      return 1;
    }
  }
  else{
    w = Mix_LoadWAV(loc);
    if(!w){
      isMusic = false;
      cout << "ERROR:Failed To Load The WAV" << endl;
      return 1;
    }
  }
  return 0;
}

