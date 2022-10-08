#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

const int S_WIDTH = 1500, S_HEIGHT = 800;

App app;

Object object, ground, platform[3];

float speed = 200.f;

Font font;
Text data_text;

int main(int argc, char *argv[]){
    app.Setup("PhysicsTester", S_WIDTH, S_HEIGHT, Vec2(0, 9.8f*6.f), 5, 5);
    app.SetWindowIcon("apple.jpg");
    app.SetPhysicsScale(8);

    object.Dynamic(S_WIDTH/2 - 15, 100, 30, 30, 0.f, 1.f, 0.f);
    object.SetSensor(0, 30, 1, 1, 1);
    object.RotationFixed(true);

    ground.Static(0, S_HEIGHT+1, S_WIDTH, 1);

    for(int i = 0; i<3; i++){
        platform[i].Static(S_WIDTH*(i+1)/4 - 100, 700, 200, 10, 0x0002, 0xFFFF);
    }

    font.Setup("Squarewave.ttf", 40, Color(0, 0, 0));
    data_text.Setup(10, 10, "", &font);

    while(!app.ShouldClose()){
        app.PhysicsUpdate();

        object.SetXVelocity(0);
        if(app.IsPressed("a")){
            object.SetXVelocity(-speed);
        }
        if(app.IsPressed("d")){
            object.SetXVelocity(speed);
        }
        if(app.IsPressed("Space") && object.IsSensorColliding(1)){
            object.SetYVelocity(-speed*2);
        }
        if(app.IsPressed("s")){
            app.SetContact(&object, 0x0002, false);
        }

        string physics_data = "Vel.<" +  to_string((int)object.GetVelocity().x) + ", " + to_string((int)object.GetVelocity().y) + ">";
        data_text.SetText(physics_data);

        app.Clear();
        app.FillRect(object.GetRect(), Color(100, 0, 100));

        for(int i = 0; i<3; i++){
            app.FillRect(platform[i].GetRect(), Color(200, 0, 100));
        }

        app.Draw(&data_text);

        app.Present();
    }
    return 0;
}