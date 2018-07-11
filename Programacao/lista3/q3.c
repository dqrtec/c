#include <stdio.h>

float melhorTempo(float *vetor, int numVoltas){
	float melhor = vetor[0];
	for(int i=0; i<numVoltas; i++){
		if(melhor > vetor[i])
			melhor = vetor[i];
	}
	return melhor;
}

float piorTempo(float *vetor, int numVoltas){
	float pior = vetor[0];
	for(int i=0; i<numVoltas; i++){
		if(pior < vetor[i])
			pior = vetor[i];
	}
	return pior;	
}

int melhorVolta(float *vetor, int numVoltas){
	int i = 0;
	float melhor = melhorTempo(vetor, numVoltas);
	while(melhor != vetor[i]){
		i++;
	}
	return i+1;
}

int piorVolta(float *vetor, int numVoltas){
	int i = 0;
	float pior = piorTempo(vetor, numVoltas);
	while(pior != vetor[i]){
		i++;
	}
	return i+1;
}

float tempoMedio(float *vetor, int numVoltas){
	float somaVoltas = 0;
	for(int i=0; i<numVoltas; i++){
		somaVoltas += vetor[i];
	}
	return somaVoltas/numVoltas;
}

int main(void){
	int n;
	int melhorVolt, piorVolt; 
	float melhorTemp, piorTemp, media;

	printf("Informe o número de voltas "); scanf("%d", &n);
	float voltas[n];
	for(int i = 0; i<n; i++){
		printf("Tempo da volta %d ", i+1); scanf("%f", &voltas[i]);
	}

	melhorTemp = melhorTempo(voltas, n);
	piorTemp = piorTempo(voltas, n);
	melhorVolt = melhorVolta(voltas, n);
	piorVolt = piorVolta(voltas, n);
	media = tempoMedio(voltas, n);

	printf("Melhor tempo: %.2fs\n", melhorTemp);
	printf("Pior tempo: %.2fs\n", piorTemp);
	printf("Melhor volta: %d\n", melhorVolt);
	printf("Pior volta: %d\n", piorVolt);
	printf("Tempo médio das voltas: %.2fs\n", media);

	return 0;
}