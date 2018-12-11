#include <iostream>
#include "vec.h"
#include "matriz.h"

using namespace std;

void gauss();
void LU();
float erroJacob(Vec x1,Vec x2);
void gauss_jacobi();
void gauss_sal();

int main(){
    cout.precision(3);

    //cria um vetor
    float la[n] = {10,2,2};
    Vec v(n,la);

    //retorna o 2 elemento do vetor
    float coluna2 = v.returnElement(2);

    //muda o valor do 2 elemento
    v.setColunn(2, 15.2);


    gauss_sal();
    return 0;
}

void gauss_sal(){
    Matiz M;
    int n =3;
    float erro = 0.5;
    Vec l1,l2,l3,B,d,aux;

    float la[n] = {10,2,2};
    l1 = Vec(n,la);

    float lb[n] = {1,10,2};
    l2 = Vec(n,lb);

    float lc[n] = {2,-7,-10};
    l3 = Vec(n,lc);

    Vec lista[3] = {l1,l2,l3};

    float ld[n] = {28,7,-17};
    B = Vec(n,ld);

    float le[n] = {0,0,0};
    aux = Vec(n,le);

    M = Matiz(3,lista);

    float lf[n];
    lf[0]= B.returnElement(0)/M.linhas[0].returnElement(0) ;
    lf[1]= (B.returnElement(1)+(-1*M.linhas[1].returnElement(0)*lf[0])) /M.linhas[1].returnElement(1),
    lf[2]= (B.returnElement(2) +(-1*M.linhas[2].returnElement(0)*lf[0]) +(-1*M.linhas[2].returnElement(1)*lf[1]) )/M.linhas[2].returnElement(2);
    d = Vec(n,lf);


    float erroD = erroJacob(aux,d);

    cout<<erro<<endl;

    while(erro<erroD){
        cout<<"--------------------------"<<endl;
        float lg[n] = {d.returnElement(0),d.returnElement(1),d.returnElement(2)};
        aux = Vec(n,lg);

        aux.show();
        d.show();

        float valorx;
        for(int i =0; i<n ; i++){
            valorx = B.returnElement(i);
            for(int j =0; j<n ; j++){
                if(i==j){
                }else if(j>i){
                    valorx-= M.linhas[i].returnElement(j) * aux.returnElement(j);
                }else{
                    valorx-= M.linhas[i].returnElement(j) * d.returnElement(j);
                }
            }
            d.setColunn(i, valorx / M.linhas[i].returnElement(i) );
        }
        aux.show();
        d.show();
        cout<<endl;

        erroD = erroJacob(aux,d);
    }

    cout<<endl;

    cout<<d.returnElement(0)<<" "<<d.returnElement(1)<<" "<<d.returnElement(2)<<" ";

}




void gauss_jacobi(){
    Matiz M;
    int n =3;
    float erro = 0.5;
    Vec l1,l2,l3,B,d,aux;

    float la[n] = {10,2,2};
    l1 = Vec(n,la);

    float lb[n] = {1,10,2};
    l2 = Vec(n,lb);

    float lc[n] = {2,-7,-10};
    l3 = Vec(n,lc);

    Vec lista[3] = {l1,l2,l3};

    float ld[n] = {28,7,-17};
    B = Vec(n,ld);

    float le[n] = {0,0,0};
    aux = Vec(n,le);

    M = Matiz(3,lista);

    float lf[n] = {B.returnElement(0)/M.linhas[0].returnElement(0),
                   B.returnElement(1)/M.linhas[1].returnElement(1),
                   B.returnElement(2)/M.linhas[2].returnElement(2)};
    d = Vec(n,lf);


    float erroD = erroJacob(aux,d);

    cout<<erro<<endl;

    while(erro<erroD){
        cout<<"--------------------------"<<endl;
        float lg[n] = {d.returnElement(0),d.returnElement(1),d.returnElement(2)};
        aux = Vec(n,lg);

        aux.show();
        d.show();

        float valorx;
        for(int i =0; i<n ; i++){
            valorx = B.returnElement(i);
            for(int j =0; j<n ; j++){
                if(i!=j){
                    valorx-= M.linhas[i].returnElement(j) * aux.returnElement(j);
                }
            }
            d.setColunn(i, valorx / M.linhas[i].returnElement(i) );
        }
        aux.show();
        d.show();
        cout<<endl;

        erroD = erroJacob(aux,d);
    }

    cout<<endl;

    cout<<d.returnElement(0)<<" "<<d.returnElement(1)<<" "<<d.returnElement(2)<<" ";

}

float erroJacob(Vec x1,Vec x2){
    float maiorX2=0;
    float maiorDiferenca = 0;
    for(int i=0;i<3;i++){
        if( abs(x2.returnElement(i)) > maiorX2 )maiorX2 = abs(x2.returnElement(i)) ;
        if( abs( x2.returnElement(i) - x1.returnElement(i) ) > maiorDiferenca ) maiorDiferenca = abs( x2.returnElement(i) - x1.returnElement(i) );
    }
    return maiorDiferenca/maiorX2 ;
}

void LU(){
    cout.precision(2);
    int n = 3;
    float la[n]={20,7,9};
    Vec l1(3,la);
    float lb[n]={7,30,8};
    Vec l2(3,lb);
    float lc[n]={9,8,30};
    Vec l3(3,lc);
    Vec lista[n];
    lista[0]=l1;
    lista[1]=l2;
    lista[2]=l3;

    Matiz Mu = Matiz(n,lista);

    float la1[n]={1,0,0};
    Vec l11(3,la1);
    float lb1[n]={0,1,0};
    Vec l21(3,lb1);
    float lc1[n]={0,0,1};
    Vec l31(3,lc1);
    Vec lista1[n];
    lista1[0]=l11;
    lista1[1]=l21;
    lista1[2]=l31;
    Matiz Ml = Matiz(n,lista1);

    float resposta[3] = {16,38,38};

    for (int i = 0; i < n; i++){
        for (int j = i+1 ; j < n; j++){

            float a = Mu.linhas[i].returnElement(i);
            float b = Mu.linhas[j].returnElement(i);// m[j][i];
            Ml.linhas[j].setColunn(i,b/a);

            Vec aux = (Mu.linhas[i]*(b/a));
            Mu.linhas[j] -= aux;
        }
    }

    for(int i=0;i<n;i++){
        cout<<Ml.linhas[i].vetor[0]<<" "<<Ml.linhas[i].vetor[1]<<" "<<Ml.linhas[i].vetor[2]<<" "<<endl;
    }
    cout<<"-------------------------------------------"<<endl<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<Mu.linhas[i].vetor[0]<<" "<<Mu.linhas[i].vetor[1]<<" "<<Mu.linhas[i].vetor[2]<<" "<<endl;
    }

    float valorY[n]={16,38,38};

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"valor antes-- "<<valorY[i]<<endl;
            valorY[i]-= Ml.linhas[i].returnElement(j) * valorY[j];
            cout<<"linha "<<i+1<<"  --> " <<valorY[i]<<endl<<endl;
        }
        cout<<endl<<endl<<endl<<endl;
        valorY[i]/= Ml.linhas[i].returnElement(i);
    }

    cout<<"valor de Y = {"<<valorY[0] <<" "<< valorY[1] <<" " << valorY[2] <<"}"<<endl;

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            valorY[i]-= Mu.linhas[i].returnElement(j) * valorY[j];
        }
        valorY[i]/= Mu.linhas[i].returnElement(i);
        cout<<valorY[i]<<" ";

    }



}




















void gauss(){
    int n = 3;
    float la[n]={20,7,9};
    Vec l1(3,la);
    float lb[n]={7,30,8};
    Vec l2(3,lb);
    float lc[n]={9,8,30};
    Vec l3(3,lc);
    Vec lista[n];
    lista[0]=l1;
    lista[1]=l2;
    lista[2]=l3;

    Matiz M = Matiz(n,lista);
    float resposta[3] = {16,38,38};

    for (int i = 0; i < 3; i++){
        cout<<M.linhas[i].vetor[0]<<" "<<M.linhas[i].vetor[1]<<" "<<M.linhas[i].vetor[2]<<" "<<endl;
        for (int j = i+1 ; j < 3; j++){

            float a = M.linhas[i].returnElement(i);
            float b = M.linhas[j].returnElement(i);// m[j][i];

            resposta[j] = resposta[j] - ( resposta[i] * b/a );
            Vec aux = (M.linhas[i]*(b/a));
            M.linhas[j] -= aux;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            resposta[i]-= M.linhas[i].returnElement(j) * resposta[j];
        }
        resposta[i]/= M.linhas[i].returnElement(i);
        cout<<resposta[i]<<" ";
    }
}
