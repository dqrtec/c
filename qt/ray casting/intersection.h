#ifndef INTERSECTION
#define INTERSECTION

#include "ponto.h"
#include "material.h"

struct Intersection{
    Material material;
    Vetor3D norm;
    float dist;
    Ponto point;
};

#endif // INTERSECTION
