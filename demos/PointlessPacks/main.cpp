#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;
int scene = 0;

Texture packs[3];
Texture cards[15];

Font font;
Text title;

Vec4 menuPackRect[3] = {
    Vec4(76, 121, 88, 119),
    Vec4(196, 121, 88, 119),
    Vec4(316, 121, 88, 119)
};

Vec4 basePackRect(153, 61, 175, 238);
Vec4 cardRect(165, 80, 150, 200);

int packType = 0;
int cardNumbers[15];
int cardSelect = 0;

Sound music;

int Setup(){
    app.Setup("PointlessPacks", 480, 360);

    font.Setup("Squarewave.ttf", 36, Color(0, 0, 0));
    title.Setup(240, 48, "Pointless Packs", &font);
    title.Center();

    music.Setup(&app, "popcorn_remix.mp3");
    music.SetVolume(0.1f);
    music.Play();

    packs[0].Setup(&app, "images/cheap.png");
    packs[1].Setup(&app, "images/normal.png");
    packs[2].Setup(&app, "images/rich.png");
    for(int i = 0; i < 15; i++){
        cards[i].Setup(&app, "images/" + to_string(i+1) + ".png");
    }
    return 0;
}

int GenerateRandomCards(int amount){
    if(amount <= 15){
        srand(app.GetTime());
        for(int i = 0; i < amount; i++){
            int random = rand() % 15;
            cardNumbers[i] = random;
        }
    }
    else{
        cout << "ERROR:Amount is too high" << endl;
        return -1;
    }
    return 0;
}

void EventHandler(){
    if(scene == 0){
        if(app.IsLeftMouse()){
            for(int i = 0; i < 3; i++){
                if(app.IsMouseInVec4(menuPackRect[i])){
                    packType = i;
                    GenerateRandomCards((packType+1)*5);
                    scene = 1;
                    break;
                }
            }
        }
    }
    else if(scene == 1){
        if(app.IsLeftMouse() && app.IsMouseInVec4(basePackRect)){
            scene = 2;
        }
    }
    else if(scene == 2){
        if(basePackRect.y <= 360){
            basePackRect.y += 0.125;
        }
        else{
            if(app.IsLeftMouse() && app.IsMouseInVec4(cardRect)){
                cardSelect++;
                if(cardSelect > ((packType+1)*5)-1){
                    basePackRect.y = 61;
                    cardSelect = 0;
                    scene = 0;
                }
            }
        }
    }
}

void RenderHandler(){
    app.Clear();

    switch(scene){
        default:
            cout << "ERROR:No Scene" << endl;
            break;
        case 0:
            app.Draw(&title);
            for(int i = 0; i < 3; i++){
                app.Draw(&packs[i], menuPackRect[i]);
            }
            break;
        case 1:
            app.Draw(&packs[packType], basePackRect);
            break;
        case 2:
            app.Draw(&cards[cardNumbers[cardSelect]], cardRect);
            app.Draw(&packs[packType], basePackRect);
            break;
        case 3:
            break;
    }

    app.Present();
}

int main(int argc, char *argv[]){
    Setup();
    while(app.IsOpen()){
        EventHandler();
        RenderHandler();
    }
    return 0;
}
