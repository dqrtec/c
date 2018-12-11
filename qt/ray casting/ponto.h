#ifndef PONTO_H
#define PONTO_H

#include "vetor.h"
#include "cmath"

class Ponto
{
public:
    float x;
    float y;
    float z;

    Ponto() { x = y = z = 0.0; }
    Ponto(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    Ponto operator+(const Vetor3D& v) const {
        return Ponto(x + v.x, y + v.y, z + v.z);
    }

    Ponto& operator+=(const Vetor3D& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    Vetor3D operator-(const Ponto& p) const {
        return Vetor3D(x - p.x, y - p.y, z - p.z);
    }

    Ponto operator-(const Vetor3D& v) const {
        return Ponto(x - v.x, y - v.y, z- v.z);
    }

    Ponto& operator-=(const Vetor3D& v){
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    Ponto operator/(float div) const {
        return Ponto(x/div, y/div, z/div);
    }
    Ponto& operator/=(float div) {
        x /= div; y/= div; z /= div;
        return *this;
    }

    void normalizar() {
        float len = sqrt(x*x + y*y + z*z );
        x/=len; y /= len; z /= len;
    }
};

#endif // PONTO_H
