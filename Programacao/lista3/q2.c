#include <stdio.h>
#define N 10
int menorElemento(int *vetor, int n){
	int menorNum = vetor[0];
	for(int i=0; i<n; i++){
		if(menorNum > vetor[i])
			menorNum = vetor[i];
	}
	return menorNum;
}

int maiorElemento(int *vetor, int n){
	int maiorNum = vetor[0];
	for(int i=0; i<n; i++){
		if(maiorNum < vetor[i])
			maiorNum = vetor[i];
	}
	return maiorNum;
}

int main(void){

	int vetor[N] = {8, 4, 2, 9, 0, 1, 5, 3, 6, 7};
	int menor = menorElemento(vetor, N);
	int maior = maiorElemento(vetor, N);
	printf("Menor: %d Maior: %d\n", maior, menor);
	return 0;
}
