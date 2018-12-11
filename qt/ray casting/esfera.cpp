#include "esfera.h"

Esfera::Esfera(){}
Esfera::Esfera(const Ponto& center, float radius) : center(center), r(radius) {}

Intersection Esfera::intersect(const Ray ray){
    // FORMULA DA INTERSECAO COM A ESFERA
    Vetor3D c = Vetor3D(center.x, center.y, center.z);
    Vetor3D origin = Vetor3D(ray.o.x, ray.o.y, ray.o.z);
    float alfa = ProdEsc(ray.d, ray.d);
    float beta = 2*(ProdEsc(origin, ray.d) - ProdEsc(ray.d, c) );
    float gama = ProdEsc(c, c) - ProdEsc(c, origin)*2 + ProdEsc(origin, origin) - r*r;
    float delta = beta*beta - 4*alfa*gama;
    Intersection intersectPoint;
    intersectPoint.dist = 0.0;

    if (delta < 0) {
        return intersectPoint;
    }
    else if (delta > 0){
        float sqrtDelta = sqrtf(delta);
        float t0 = (-beta - sqrtDelta)/(2*alfa);
        float t1 = (-beta + sqrtDelta)/(2*alfa);
        float menorT = (t0 < t1)?t0:t1;
        intersectPoint.dist = menorT;
        intersectPoint.point = ray.o + ray.d*intersectPoint.dist;
        intersectPoint.norm  = this->getNormal(intersectPoint.point);
        intersectPoint.material = this->material;
    }
    else if (delta == 0){
        Intersection intersectPoint;
        intersectPoint.dist = -beta/(2*alfa);
        intersectPoint.point = ray.o + ray.d*intersectPoint.dist;
        intersectPoint.material = this->material;
        intersectPoint.norm  = this->getNormal(intersectPoint.point);
    }
    return intersectPoint;
}
