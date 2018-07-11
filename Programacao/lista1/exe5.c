#include <stdio.h>

int main(void){
	int n1, n2, n3, aux, cond, i;
	//int vetor[3];

	printf("Informe 3 números separados por espaço: ");
	scanf("%d %d %d", &n1, &n2, &n3);

	int vetor[3] = {n1, n2, n3};

	i = 0;
	aux = 0;
	while(vetor[0] > vetor[1] || vetor[1] > vetor[2]){
		if(i == 2)
			i = 0;
		if(vetor[i] > vetor[i+1]){
			aux = vetor[i+1];
			vetor[i+1] = vetor[i];
			vetor[i] = aux;
		}
		i++;
	}

	printf("Ordem crescente: %d %d %d \n", vetor[0], vetor[1], vetor[2]);
	printf("Maior número: %d \n", vetor[2]);

	return 0;
}

