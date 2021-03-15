#ifndef SOUND_H
#define SOUND_H

#include <iostream>

#include <soloud.h>
#include <soloud_wav.h>
#include <soloud_wavstream.h>

using namespace std;

namespace SoLoud{
  class Wav;
  class WavStream;
}

class Sound{
 private:
  SoLoud::Wav *sample;
  SoLoud::WavStream *stream;
 public:
  Sound(){}
  Sound(const char* loc, bool music);
  int Setup(const char* loc, bool music);

  //Control
  void Play();
  void Pause();
  void Resume();
  void Stop();
  void SetChunkVolume(float value);

  //Destructor
  ~Sound();
};

#endif
