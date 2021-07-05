#include "UI.h"

void UI::RemoveButton(Button *button){
    for(int i = 0; i < buttonList.size(); i++){
        if(buttonList[i] == button){
            buttonList.erase(buttonList.begin() + i);
            break;
        }
    }
}

void UI::RemoveText(Text* text){
    for(int i = 0; i < textList.size(); i++){
        if(textList[i] == text){
            textList.erase(textList.begin() + i);
            break;
        }
    }
}