#include "Slider.h"

#include "Chassis2D.h"

Slider::Slider(float x, float y, float w, float h){
    Setup(x, y, w, h);
}

void Slider::Setup(float x, float y, float w, float h){
    rect = Vec4(x, y, w, h);
    percent = 0.0f;
}

Slider::Slider(float x, float y, float w, float h, float percent){
    Setup(x, y, w, h, percent);
}

void Slider::Setup(float x, float y, float w, float h, float percent){
    rect = Vec4(x, y, w, h);
    this->percent = percent;
}