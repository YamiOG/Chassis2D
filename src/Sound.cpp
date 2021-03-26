#include "Sound.h"

#include "Chassis2D.h"

#include <soloud.h>
#include <soloud_wav.h>
#include <soloud_wavstream.h>

Sound::Sound(App *app, string path){
  Setup(app, path);
}

int Sound::Setup(App *app, string path){
  if(!path.empty()){
    string extension = path.substr(path.find_last_of(".")+1, path.size());
    if(extension == "wav"){
      isWAV = true;
      sample = new SoLoud::Wav;
      sample->load(path.c_str());
    }
    else{
      isWAV = false;
      stream = new SoLoud::WavStream;
      stream->load(path.c_str());
    }
  }
  else{
    cout << "ERROR:Path is empty" << endl;
  }

  if(app){
    this->app = app;
  }
  else{
    cout << "ERROR:App is NULL" << endl;
  }

  return 0;
}

Sound::~Sound(){
  if(isWAV){
    sample->stop();
    delete sample;
  }
  else{
    stream->stop();
    delete stream;
  }
}

void Sound::Play(){
  if(isWAV){
    app->GetSoLoud()->play(*sample);
  }
  else{
    app->GetSoLoud()->play(*stream);
  }
}

void Sound::Pause(){
  if(isWAV){
    sample->setInaudibleBehavior(false, true);
  }
  else{
    stream->setInaudibleBehavior(false, true);
  }
}

void Sound::Resume(){
  if(isWAV){
    sample->setInaudibleBehavior(false, false);
  }
  else{
    stream->setInaudibleBehavior(false, false);
  }
}

void Sound::SetPause(bool set){
  if(isWAV){
    sample->setInaudibleBehavior(false, set);
  }
  else{
    stream->setInaudibleBehavior(false, set);
  }
}

void Sound::Stop(){
  if(isWAV){
    sample->stop();
  }
  else{
    stream->stop();
  }
}

void Sound::SetVolume(float value){
  if(isWAV){
    sample->setVolume(value);
  }
  else{
    stream->setVolume(value);
  }
}

void Sound::SetLoop(bool set){
  if(isWAV){
    sample->setLooping(set);
  }
  else{
    stream->setLooping(set);
  }
}

void Sound::Loop(){
  if(isWAV){
    sample->setLooping(true);
  }
  else{
    stream->setLooping(true);
  }
}