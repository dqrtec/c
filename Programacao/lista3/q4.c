#include <stdio.h>
#define N 10
int calcEscalar(int *vetor1, int *vetor2, int numElementos){
	int escalar = 0;
	for(int i=0; i<numElementos; i++){
		escalar += (vetor1[i] * vetor2[i]);
	}
	return escalar;
}

int main(void){
	int escalar;
	int vetor1[N], vetor2[N];
	for(int i=0; i<N; i++){
		printf("Informe o elemento %d do conjunto 1 ", i); scanf("%d", &vetor1[i]);
		printf("Informe o elemento %d do conjunto 2 ", i); scanf("%d", &vetor2[i]);
	}

	escalar = calcEscalar(vetor1, vetor2, N);
	printf("O produto escalar é %d\n", escalar);
	return 0;
}