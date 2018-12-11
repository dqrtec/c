#ifndef CENA_H
#define CENA_H

#include <vector>
#include "esfera.h"

struct Luz {
    Color cor;
    Ponto posicao;
    //float atenuacao;
};

class Cena
{
public:
    std::vector<Esfera*> objetos;
    std::vector<Luz> luzes;

    Cena();

    void adLuz(const Ponto& center, float r, float g, float b);
    void adEsfera(const Ponto& centro, float raio, Material mat);
    bool intersecao(const Ray& raio, Intersection &intersecao);
};
#endif // CENA_H
