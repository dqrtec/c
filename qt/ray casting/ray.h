#ifndef RAY
#define RAY

#include "ponto.h"
#include "vetor.h"

class Ray
{
public:
    Ponto o;
    Vetor3D d;

    Ray(){};
    Ray(const Ponto& p, const Vetor3D& v) : o(p), d (v) { }

    Ponto operator()(float t)const{
        return o + d*t;
    }

    Vetor3D ray() {
        Vetor3D ray;
        ray = (d-o);
        ray.normalizar();
        return ray;
    }
};

#endif // RAY
