#include "vetor.h"
#include "ponto.h"
#include "cmath"

Vetor3D::Vetor3D() {}

Vetor3D::Vetor3D(const Ponto &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

Vetor3D::Vetor3D(float _x, float _y, float _z)  : x(_x), y(_y), z(_z) {}

Vetor3D Vetor3D::operator + (const Vetor3D& v) const {
    return Vetor3D(x + v.x, y + v.y, z + v.z );
}

Vetor3D& Vetor3D::operator += (const Vetor3D& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vetor3D Vetor3D::operator - (const Vetor3D& v) const {
    return Vetor3D(x - v.x, y - v.y, z - v.z );
}

Vetor3D& Vetor3D::operator -= (const Vetor3D& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vetor3D Vetor3D::operator * (float f) const{
    return Vetor3D(x*f, y*f, z*f);
}

Vetor3D& Vetor3D::operator *= (float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vetor3D Vetor3D::operator / (float f) const{
    if (fabs(f) < 0.0004) {
        return *this;
    }
    return Vetor3D(x/f, y/f, z/f);
}

Vetor3D& Vetor3D::operator /= (float f) {
    if (fabs(f) < 0.0004) {
        return *this;
    }

    x /= f;
    y /= f;
    z /= f;
    return *this;
}

float Vetor3D::comprimento() {
    return sqrt(x*x + y*y + z*z );
}

void Vetor3D::normalizar() {
    double comp = this->comprimento();
    x /= comp;
    y /= comp;
    z /= comp;
}

double ProdEsc(const Vetor3D &v1, const Vetor3D &v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vetor3D ProdVet(const Vetor3D& v1, const Vetor3D& v2){
    return Vetor3D((v1.y*v2.z) - (v1.z*v2.y),
                   (v1.z*v2.x) - (v1.x*v2.z),
                   (v1.x*v2.y) - (v1.y*v2.x));
}
