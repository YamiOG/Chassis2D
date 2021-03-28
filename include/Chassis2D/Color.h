#ifndef COLOR_H
#define COLOR_H

class Color{
    public:
        int r, g, b, a; 

        Color(){}
        Color(int r, int g, int b) { this->r = r; this->g = g; this->b = b; this->a = 255; }
        Color(int r, int g, int b, int a) { this->r = r; this->g = g; this->b = b; this->a = a; }
};

#endif