#ifndef VETOR3D_H
#define VETOR3D_H

class Ponto;

class Vetor3D
{
public:
    float x;
    float y;
    float z;
    float comprimento();
    void normalizar();

    Vetor3D();
    Vetor3D(const Ponto& p);
    Vetor3D(float _x, float _y, float _z);

    Vetor3D operator+(const Vetor3D& v) const;
    Vetor3D& operator+=(const Vetor3D& v);
    Vetor3D operator-(const Vetor3D& v) const;
    Vetor3D& operator-=(const Vetor3D& v);
    Vetor3D operator*(float f) const;
    Vetor3D& operator*=(float f);
    Vetor3D operator/(float f) const;
    Vetor3D& operator/=(float f);
};

double ProdEsc(const Vetor3D& v1, const Vetor3D& v2);
Vetor3D ProdVet(const Vetor3D& v1, const Vetor3D& v2);
#endif // VETOR3D_H
