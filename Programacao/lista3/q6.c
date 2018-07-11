#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, n, aux = 0;
	int op = 1;
	printf("Informe a quantidade de elementos "); scanf("%d", &n);

	int *vetor = (int*) malloc(n*sizeof(int)); 

	for(i=0; i<n; i++){
		printf("Informe o %d elemento ", i+1); scanf("%d", &vetor[i]);
	}

	while(op == 1){
		aux += n;
		printf("Deseja insirir mais elementos? (1/0) "); scanf("%d", &op);
		if(op == 1){
			printf("Informe a quantidade de elementos "); scanf("%d", &n);
			
			vetor = (int*) realloc(vetor, n*sizeof(int));

			for(i=aux; i<aux+n; i++){
				printf("Informe o %d elemento ", i+1); scanf("%d", &vetor[i]);
			}
		}
	}

	for(i=0; i<aux; i++){
		printf("%d ", vetor[i]);
	}

	printf("\n");
	free(vetor);
	return 0;
}