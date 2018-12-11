#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    float r;
    float g;
    float b;

    Color(float red = 0, float green = 0, float blue = 0);
    void definirCor(float red, float green, float blue);
    Color operator*(const Color& c) const;
    Color& operator*=(const Color& c);
};
#endif // COLOR_H
