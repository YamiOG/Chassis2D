#include "Sound.h"

Sound::Sound(const char* loc, bool music){
  if(music){
    m = Mix_LoadMUS(loc);
    if(!m){
      cout << "ERROR:Failed To Load The Music" << endl;
    }
  }
  else{
    w = Mix_LoadWAV(loc);
    if(!w){
      cout << "ERROR:Failed To Load The WAV" << endl;
    }
  }
  isMusic = music;
}

int Sound::Setup(const char* loc, bool music){
  if(music){
    m = Mix_LoadMUS(loc);
    if(!m){
      cout << "ERROR:Failed To Load The Music" << endl;
      return 1;
    }
  }
  else{
    w = Mix_LoadWAV(loc);
    if(!w){
      cout << "ERROR:Failed To Load The WAV" << endl;
      return 1;
    }
  }
  isMusic = music;
  return 0;
}

void Sound::Play(){
  if(isMusic){
    if( Mix_PlayingMusic() == 0 ) {
      if(Mix_PlayMusic(m, -1) == -1){
        cout << "ERROR:Music Failed To Play" << endl;
      }
    }
  }
  else{
    Mix_PlayChannel(-1, w, 0);
  }
}

void Sound::Pause(){
  if(isMusic){
    Mix_PauseMusic();
  }
  else{
    cout << "WARNING:This is Not Music File" << endl;
  }
}

void Sound::Resume(){
  if(isMusic){
    if(Mix_PausedMusic() == 1){
      Mix_ResumeMusic();
    }
    else{
      cout << "WARNING:This Music was Not Paused" << endl;
    }
  }
  else{
    cout << "WARNING:This is Not Music File" << endl;
  }
}

void Sound::Stop(){
  if(isMusic){
    Mix_HaltMusic();
  }
  else{
    cout << "WARNING:This is Not Music File" << endl;
  }
}

void Sound::SetVolume(float value){
  if(isMusic){
    cout << "WARNING:This is Not a WAV File" << endl;
  }
  else{
    Mix_VolumeChunk(w, MIX_MAX_VOLUME * (value/100));
  }
}
