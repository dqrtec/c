#ifndef CAMERA_H_
#define CAMERA_H_

#include "vetor.h"
#include "ponto.h"
#include "ray.h"

class Camera {
public:
    int larguraPixels;
    int alturaPixels;
    Vetor3D iCamera;
    Vetor3D jCamera;
    Vetor3D kCamera;
    Ponto posicaoCamera;

    Camera();
    Camera(int width, int height);

    Ray criarRay(int wImg, int hImg);
    Vetor3D getLookAt();
    void lookAt( Ponto point );
    Ponto capturaPosicao();
    void setposicaoCamera(Ponto pos);
};
#endif
