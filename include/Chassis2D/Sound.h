#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <string>

#include "Global.h"
#include "Class.h"

using namespace std;

namespace SoLoud{
  class Wav;
  class WavStream;
}

class Sound{
 private:
  SoLoud::Wav *sample;
  SoLoud::WavStream *stream;

  bool isWAV;
 public:
  Sound(){}
  Sound(string path);
  int Setup(string path);

  //Control
  void Play();
  void Pause();
  void Resume();
  void Stop();
  void Loop();
  void SetPause(bool set);
  void SetLoop(bool set);
  void SetVolume(float value);

  //Get
  bool IsWAV() { return isWAV; }

  //Destructor
  ~Sound();
};

#endif
