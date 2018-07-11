#include <stdio.h>

int main(void){

	int m, n;
	int i, j, somatorio;

	printf("Informe o número de linhas e colunas da matriz Amxn "); scanf("%d %d", &m, &n);

	int matriz[m][n];
	int vetor[n][1];
	int resultado[m][1];

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("Informe o elemento da coordenada (%d, %d) ", i+1, j+1); scanf("%d", &matriz[i][j]);
		}
	}

	for(j=0; j<n; j++){
		printf("Informe o elemento da posicao %d do vetor Vnx1 ", j+1); scanf("%d", &vetor[j][0]);
	}

	for(i=0; i<m; i++){
		somatorio = 0;

		for(j=0; j<n; j++){
			somatorio += (matriz[i][j] * vetor[j][0]);
		}
		resultado[i][0] = somatorio;
	}

	for(i=0; i<m; i++){
		printf("O elemento %d resultante do vetor AxV = %d\n", i+1, resultado[i][0]);
	}

	return 0;
}
