#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	float x[] ={30,60,90};
	float y[] ={27,58,100};
	float entrada=80;
	float saida=0;
	float l[3];

	for (int i = 0; i < 3; i++){
		l[i]=1;
		for (int j = 0; j < 3; j++){
			if (i!=j){
				l[i] *= (entrada-x[j])/(x[i]-x[j]);
			}
		}
		saida += (y[i]*l[i]);
	}

	cout<<l[0]<<" "<<l[1]<<" "<<l[2]<<" "<<endl;
	cout<<saida;
	
return 0;
}