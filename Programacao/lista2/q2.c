#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int n) {
	if (n == 2) {
		return 1;
	} 
	else if (n<2 || (n%2)==0) {
		return 0;
	} 
	int lim = (int)sqrt(n);
	for (int i=3; i<= lim; i+=2) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int *nPrimos(int n){
	int i, num;
	i = 0;

	//Aloca um bloco de memória para uma matriz de elementos num , cada um de tamanho de bytes longos e inicializa todos os seus bits para zero. 
	int *n_primos = (int*)calloc(n, sizeof(int));

	i = 0;
	num = 0;
	while(i < n){
		if(primo(num)){
			n_primos[i] = num;
			i++;
		}
		num++;
	}
	return n_primos;
}

int *xPrimos(int x){
	int i, num;
	int *x_primos = (int*)calloc(x, sizeof(int));
	i = 0;
	for(num = 0; num < x; num++){
		if(primo(num)){
			x_primos[i] = num;
			i++;
		}
	}
	return x_primos;
}

int main(void){
	int n, x, i, *nprimos, *xprimos;
	printf("Informe o valor de n "); scanf("%d", n);
	printf("Informe o valor de x "); scanf("%d", x);
	i = 0;
	nprimos = nPrimos(n);
	xprimos = xPrimos(x);

	// Retorna o primos menores que X
	printf("Números primos menores que %d >> ", x);
	while(xprimos[i] > 0){
		printf("%d ", xprimos[i]);
		i++;
	}
	printf("\n\n");

	// Retorna o N primeiros primos
	printf("Os %d primeiros números primos >> ", n);
	for(i = 0; i<n; i++){
		printf("%d ", nprimos[i]);
	}
	printf("\n");
	return 0;	
}