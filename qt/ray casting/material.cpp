#include "material.h"
Material::Material(){}
Material::Material(const Color& amb, const Color& diff, const Color & spec, int k){
    ambient=amb;
    diffuse=diff;
    specular=spec;
    this->k=k;
    this->Ka = 1.0;//coeficiente AMBIENTE
    this->Kd = 1.0;//coeficiente DIFUSA
    this->Ks = 1.0;//coeficiente ESPECULAR
}
Material::Material(const Color& amb, const Color& diff, const Color & spec, int k, float ka, float kd, float ks)
    : ambient(amb), diffuse(diff), specular(spec), k(k), Ka(ka), Kd(kd), Ks(ks){}
