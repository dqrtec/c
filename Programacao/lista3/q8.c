#include <stdio.h>

void troca(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void ordena(int *L, int size){
	int aux, i, j;

	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if(L[i] > L[j]){	
				troca(&L[i], &L[j]);
			}
		}
	}
}

int main(void){
	int n, i, x, k;
	printf("Informe a quantidade de elementos da sequencia "); scanf("%d", &n);

	int seq[n];

	for(i=0; i<n; i++){
		printf("Informe o elemento %d da sequencia ", i+1); scanf("%d", &seq[i]);
	}

	ordena(seq, n);

	for(i=0; i<n; i++){
		printf("%d ", seq[i]);
	}
	
	printf("\n");
	
	return 0;
}
