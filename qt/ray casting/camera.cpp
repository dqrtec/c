#include "camera.h"

Camera::Camera(){
    kCamera = Vetor3D{0.0, 0.0, 1.0};
    posicaoCamera = {0.0, 0.0, 17.0};
    iCamera = Vetor3D{1.0, 0.0, 0.0};
    jCamera = Vetor3D{0.0, 1.0, 0.0};
}

Camera::Camera(int width, int height){
    larguraPixels = width;
    alturaPixels = height;

    iCamera = Ponto{1.0, 0.0, 0.0};
    jCamera = Ponto{0.0, -1.0, 0.0};
    kCamera = Ponto{0.0, 0.0, 1.0};
}

Ray Camera::criarRay(int wImg, int hImg) {
    float xw = (-1.0/2.0) + ((1.0 / larguraPixels) + (wImg *(1.0 / larguraPixels)));// NAO SEI AO CERTO
    float yw = (1.0/2.0) - ((1.0 / alturaPixels) + (hImg * (1.0 / alturaPixels)));// NAO SEI AO CERTO

    Ponto p = posicaoCamera + kCamera*(-1.0) + iCamera*xw + jCamera*yw;// acha o ponto central do pixel
    Vetor3D dir = p - posicaoCamera;// cria o raio subtraindo camera do pixel
    dir.normalizar();// cria vetor unitario

    return Ray(posicaoCamera, dir);
}

Ponto Camera::capturaPosicao() {return this->posicaoCamera;}//retorna posicao da camera

void Camera::setposicaoCamera(Ponto pos) {this->posicaoCamera = pos;}//muda posicao da camera

Vetor3D Camera::getLookAt() {return this->kCamera;}//pega o valor do lookat

void Camera::lookAt(Ponto point ){
    // NAO SEI AO CERTO EXPLICAR
    this->kCamera = this->posicaoCamera - point;
    this->kCamera.normalizar();

    this->iCamera = ProdVet( ( ( point + Ponto(0, 1.0, 0) ) - this->posicaoCamera  ), this->kCamera );
    this->iCamera.normalizar();

    this->jCamera = ProdVet( this->kCamera, this->iCamera  );
}
