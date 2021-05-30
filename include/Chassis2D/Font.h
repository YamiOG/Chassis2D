#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "Vec4.h"
#include "Color.h"

using namespace std;

typedef struct _TTF_Font TTF_Font;

class Font{
 private:
  TTF_Font *font;
  Color color;
  int size;

  bool rgb;
  int divisor = 1;
 public:
  Font(){}
  Font(const char* location, int size, Color color);
  int Setup(const char* location, int size, Color color);
  Font(const char* location, int size, int r, int g, int b);
  int Setup(const char* location, int size, int r, int g, int b);
  Font(const char* location, int size, int r, int g, int b, int a);
  int Setup(const char* location, int size, int r, int g, int b, int a);
  Font(const char* location, int size, int divisor);
  int Setup(const char* location, int size, int divisor);
  shared_ptr<Texture> GetText(const char* text);
  shared_ptr<Texture> GetText(const char* text, int &iTime);
  bool GetRGB(){ return rgb; }
  void SetDivisor(int divisor) { this->divisor = divisor; }

  ~Font();
};

#endif
