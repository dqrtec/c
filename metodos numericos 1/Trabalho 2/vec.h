#ifndef VEC
#define VEC

#include <iostream>
using namespace std;

class Vec
{
public:
    int lenght;
    float *vetor;

    Vec();
    Vec(int lenght);
    Vec(int lenght,float* vetor);

    Vec operator+(Vec& v);
    Vec& operator+=(Vec& v);
    Vec operator-(Vec& v);
    Vec& operator-=(Vec& v);
    Vec operator*(float escalar);
    Vec& operator*=(float escalar);
    Vec operator/(float escalar);
    Vec& operator/=(float escalar);

    float returnElement(int indiceColunaElemento);
    void show();

    void setColunn(int coluna,float valor);
};
#endif

Vec::Vec(){}

Vec::Vec(int tamanho) {
    lenght = tamanho;
}

Vec::Vec(int tamanho,float* vetorEntrada){
vetor = vetorEntrada;
    lenght = tamanho;
}

float Vec::returnElement(int indiceColunaElemento){
    return vetor[indiceColunaElemento];
}








Vec Vec::operator+(Vec& v) {
    float vetorResultante[lenght];
    for(int i=0; i<lenght; i++ ){
        vetorResultante[i] = vetor[i] + v.vetor[i];
    }
    return Vec(lenght,vetorResultante );
}

Vec& Vec::operator+=(Vec& v){
    for(int i=0; i<lenght; i++ ){
        vetor[i] += v.vetor[i];
    }
    return *this;
}

Vec Vec::operator-(Vec& v) {
    float vetorResultante[lenght];
    for(int i=0; i<lenght; i++ ){
        vetorResultante[i] = vetor[i] - v.vetor[i];
    }
    return Vec(lenght,vetorResultante );
}

Vec& Vec::operator-=(Vec& v){
    for(int i=0; i<lenght; i++ ){
        vetor[i] -= v.vetor[i];
    }
    return *this;
}

Vec Vec::operator*(float escalar){
    float vetorResultante[lenght];
    for(int i=0; i<lenght; i++ ){
        vetorResultante[i] = vetor[i] * escalar;
    }
    return Vec(lenght,vetorResultante );
}

Vec& Vec::operator*=(float escalar) {
    for(int i=0; i<lenght; i++ ){
        vetor[i] *= escalar;
    }
    return *this;
}

Vec Vec::operator/(float escalar){
    float vetorResultante[lenght];
    for(int i=0; i<lenght; i++ ){
        vetorResultante[i] = vetor[i] / escalar;
    }
    return Vec(lenght,vetorResultante );
}

Vec& Vec::operator/=(float escalar) {
    for(int i=0; i<lenght; i++ ){
        vetor[i] /= escalar;
    }
    return *this;
}

void Vec::show(){
    for(int i ;i<lenght ;i++){
        cout<<vetor[i]<<" ";
    }
    cout<<endl;
}

void Vec::setColunn(int coluna,float valor){
    vetor[coluna] = valor;
}
