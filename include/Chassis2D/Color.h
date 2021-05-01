#ifndef COLOR_H
#define COLOR_H

struct SDL_Color;

class Color{
    public:
        int r, g, b, a; 

        Color(){}
        Color(int r, int g, int b) { Set(r, g, b); }
        Color(int r, int g, int b, int a) { Set(r, g, b, a); }

        void Set(int r, int g, int b) { this->r = r; this->g = g; this->b = b; this->a = 255; }
        void Set(int r, int g, int b, int a) { this->r = r; this->g = g; this->b = b; this->a = a; }

        SDL_Color ToSDL();
};

#endif