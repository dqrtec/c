#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material
{
public:
    int k;
    float Ka;
    float Kd;
    float Ks;
    Color ambient;
    Color diffuse;
    Color specular;

    Material();
    Material(const Color& amb, const Color& diff, const Color& spec, int k);
    Material(const Color& amb, const Color& diff, const Color& spec, int k, float ka, float kd, float ks);
};

#endif // MATERIAL_H
