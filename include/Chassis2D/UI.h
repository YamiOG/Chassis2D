#ifndef UI_H
#define UI_H 

using namespace std;

#include <iostream>
#include <vector>

#include "Global.h"
#include "Class.h"

class UI{
 private:
  vector<Button*> buttonList;
  vector<Text*> textList;
 public:
  void AddButton(Button* button) { buttonList.push_back(button); }
  void AddText(Text* text) { textList.push_back(text); }
  void RemoveButton(Button *button);
  void RemoveText(Text* text);

  vector<Button*> GetButtons() { return buttonList; }
  vector<Text*> GetTexts() { return textList; }
};

#endif