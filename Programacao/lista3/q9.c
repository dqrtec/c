// parametros da funcao insuficiente - repeticoes(int numero);

#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int linhas, int colunas){
	int i, j;
	int **matriz = (int**) malloc(linhas*sizeof(int*));
	for(i=0; i<linhas; i++){
		matriz[i] = (int*) malloc(colunas*sizeof(int));
		for(j=0; j<colunas; j++){
			matriz[i][j] = 0;
		}
	}
	return matriz;
}

void desalocaMatriz(int **matriz){
	return free(matriz);
}

int repeticoes(int **matriz, int numero, int m, int n){
	int i, j, rep = 0;

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(matriz[i][j] == numero)
				rep += 1;
		}
	}
	return rep;
}

int main(void){

	int m, n, i, j, numero, repeticao;
	printf("Informe a quantidade de linhas e colunas "); scanf("%d %d", &m, &n);

	// Aloca um vetor de ponteiros
	// Como seria a alocacao de uma matriz de 3 dimensoes
	
	int **matriz = alocaMatriz(m, n);

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("Informe o elemento de posicão %dx%d ", i+1, j+1); scanf("%d", &matriz[i][j]);
		}
	}
	printf("Informe o numero que deseja verificar "); scanf("%d", &numero);

	repeticao = repeticoes(matriz, numero, m, n);
	printf("O número %d se repete %d vezes\n", numero, repeticao);

	desalocaMatriz(matriz);
	return 0;
}