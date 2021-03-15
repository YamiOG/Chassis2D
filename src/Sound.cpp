#include "Sound.h"

#include "Chassis2D.h"

#include <soloud.h>
#include <soloud_wav.h>
#include <soloud_wavstream.h>

Sound::Sound(const char* loc, bool music){
  Setup(loc, music);
}

int Sound::Setup(const char* loc, bool music){
  return 0;
}

Sound::~Sound(){
}

void Sound::Play(){
  
}

void Sound::Pause(){
}

void Sound::Resume(){
}

void Sound::Stop(){
}

void Sound::SetChunkVolume(float value){
}