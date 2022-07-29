#include <iostream>

#include <Chassis2D/Chassis2D.h>

using namespace std;

App app;

Object object;

int main(int argc, char *argv[]){
    app.Setup("PhysicsTester", 1500, 800, Vec2(0, 9.8f), 5, 5);
    app.SetPhysicsScale(8);

    object.Dynamic(100, 100, 10, 10, 0.f, 1.f, 0.f, TERRAIN, TERRAIN);

    while(!app.ShouldClose()){
        Vec4 rect = object.GetRect();
        cout << rect.x << endl;

        app.PhysicsUpdate();

        object.SetPosition(Vec2(100,100));

        app.Clear();
        app.FillRect(rect, Color(100, 0, 100));
        app.Present();
    }
    return 0;
}