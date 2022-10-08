#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

Object object, ground;

float speed = 200.f;

Font font1;
Text timer;

int main(int argc, char *argv[]){
    app.Setup("PhysicsTester", 1500, 800, Vec2(0, 9.8f*6.f), 5, 5);
    app.SetWindowIcon("apple.jpg");
    app.SetPhysicsScale(8);

    object.Dynamic(1500/2 - 15, 100, 30, 30, 0.f, 1.f, 0.f, TERRAIN, TERRAIN);
    object.SetSensor(15, 30, 1, 1, 1);

    ground.Static(0, 800, 1500, 1);

    font1.Setup("Squarewave.ttf", 40, Color(0, 0, 0));
    timer.Setup(10, 10, "", &font1);

    while(!app.ShouldClose()){
        Vec4 rect = object.GetRect();

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

        string physics_data = "Vel.<" +  to_string((int)object.GetVelocity().x) + ", " + to_string((int)object.GetVelocity().y) + ">";

        timer.SetText(physics_data);

        app.Clear();
        app.FillRect(rect, Color(100, 0, 100));
        app.Draw(&timer);
        app.Present();
    }
    return 0;
}