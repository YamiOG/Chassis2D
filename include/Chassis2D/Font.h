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
  Color color = Color(0,0,0);
  int size;

 public:
  Font(){}
  Font(const char* location, int size, Color color);
  int Setup(const char* location, int size, Color color);
  Font(const char* location, int size, int r, int g, int b);
  int Setup(const char* location, int size, int r, int g, int b);
  Font(const char* location, int size, int r, int g, int b, int a);
  int Setup(const char* location, int size, int r, int g, int b, int a);

  void SetColor(int r, int g, int b) { color.r = r; color.g = g; color.b = b; }
  void SetColor(int r, int g, int b, int a) { color.r = r; color.g = g; color.b = b; color.a = a; }
  Color GetColor() { return color; }

  shared_ptr<Texture> GetText(const char* text);

  ~Font();
};

#endif
