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
  vector<UIObject*> uiObjectList;
 public:
  void AddText(Text* text) { textList.push_back(text); }
  void AddUIObject(UIObject* uiObject) { uiObjectList.push_back(uiObject); }
  void RemoveText(Text* text);
  //void RemoveUIObject(Button *button);

  vector<Button*> GetButtons() { return buttonList; }
  vector<Text*> GetTexts() { return textList; }
  vector<UIObject*> GetUIObjects() { return uiObjectList; }
};

#endif