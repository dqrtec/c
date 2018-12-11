#ifndef Esfera_H
#define Esfera_H

#include "ponto.h"
#include "vetor.h"
#include "ray.h"
#include "intersection.h"

class Esfera
{
public:
    float r;
    Ponto center;
    Material material;

    Esfera();
    Esfera(const Ponto& center, float radius);

    Vetor3D getNormal(const Ponto p) { return (p - center)/r; }

    Intersection intersect(const Ray ray);
};

#endif // Esfera_H
