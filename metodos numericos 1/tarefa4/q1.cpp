#include <iostream>
using namespace std;

float divi(int inicio,int fim, float* x, float* y){
		if (inicio == fim){
			return y[inicio];
		}
		float saida = (divi(inicio+1,fim,x,y) - divi(inicio,fim-1,x,y))/(x[fim] - x[inicio]);
		cout<<"saida "<<inicio<<" - "<<fim <<" -- > "<<saida<<endl;
		return saida;
	}

int main(int argc, char const *argv[]){
	int n=4;
	float x[] ={20,30,45,55};
	float y[] ={0.99807,0.99826,0.99849,0.99919};
	float entrada=25;
	float saida=0;
	float l[n];

	for (int i = 0; i < n; i++){
		l[i]=1;
		for (int j = 0; j < n; j++){
			if (i!=j){
				l[i] *= (entrada-x[j])/(x[i]-x[j]);
			}
		}
		cout<<"l"<<i<<" = "<< l[i] <<endl;
		saida += (y[i]*l[i]);
	}

	cout<<l[0]<<" "<<l[1]<<" "<<l[2]<<" "<<endl;
	cout<<"lagranje ="<<saida<<endl;

	float somador = 0;
	float multiplicador;
	for (int i = 0; i < n; ++i){
		multiplicador = 1;
		for (int j = 0; j < i; j++){
			multiplicador*= (entrada-x[j]);
		}
		somador += multiplicador * divi(0,i,x,y);
	}

	cout<<somador<<endl;
	
return 0;
}