#include "cena.h"
#include <list>
#include <float.h>

Cena::Cena(){}

bool Cena::intersecao(const Ray& ray, Intersection &intersecao){
    float dist = FLT_MAX;
    Intersection closest;   //queremos a interseção mais próxima

    for(std::vector<Esfera*>::iterator iter = objetos.begin(); iter != objetos.end(); iter++) {//percorre objetos do cenario
        Intersection inter = (*iter)->intersect(ray);// ve o T(distancia) que um objeto ta da camera
        if( inter.dist > 0.0 && inter.dist<=dist ){//selecionar o objeto de menor distancia
            dist = inter.dist;
            closest = inter;
        }
    }
    if ( dist == FLT_MAX )return false;
    intersecao = closest;
    return true;
}

void Cena::adLuz(const Ponto& centro, float r, float g, float b){
    Luz luz;
    luz.cor.definirCor(r, g, b);
    luz.posicao = centro;
    luzes.push_back(luz);
}

void Cena::adEsfera(const Ponto& centro, float raio, Material mat){
    Esfera *s = new Esfera(centro, raio);
    s->material=mat;
    objetos.push_back(s);// adiciona objeto em um vetor
}
