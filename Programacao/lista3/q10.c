#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int linhas, int colunas){
	int i, j;
	int **matriz = (int**) malloc(linhas* sizeof(int*));
	for(i=0; i<linhas; i++){
		matriz[i] = (int*) malloc(colunas* sizeof(int));
		for(j=0; j<linhas; j++){
			matriz[i][j] = 0;
		}
	}
	return matriz;
}

void desalocaMatriz(int **matriz){
	return free(matriz);
}

int **matrizEscalar(int **matriz, int escalar, int linhas, int colunas){
	int i, j;
	for(i=0; i<linhas; i++){
		for(j=0; j<linhas; j++){
			matriz[i][j] = matriz[i][j]* escalar;
		}
	}
	return matriz;
}

int main(void){

	int m, n, escalar;
	int i, j;

	printf("Informe a quantidade de linhas e colunas "); scanf("%d %d", &m, &n);
	printf("Informe o escalar "); scanf("%d", &escalar);

	int **matriz = alocaMatriz(m, n);

	// Preenche matriz
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("Informe o elemento de posicão %dx%d ", i+1, j+1); scanf("%d", &matriz[i][j]);
			
		}
	}
	
	// Matriz Original
	printf("\nMatriz Original\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", matriz[i][j]);
		}
			printf("\n");
	}
	
	// Matriz Escalar
	printf("\nMatriz Escalar\n");
	matrizEscalar(matriz, escalar, m, n);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", matriz[i][j]);
		}
			printf("\n");
	}

	desalocaMatriz(matriz);

	return 0;
}