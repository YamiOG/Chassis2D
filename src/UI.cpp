#include "UI.h"

void UI::RemoveText(Text* text){
    for(int i = 0; i < textList.size(); i++){
        if(textList[i] == text){
            textList.erase(textList.begin() + i);
            break;
        }
    }
}