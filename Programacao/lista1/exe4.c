#include <stdio.h>

int main(void){
	int valor, num_notas, i;
	int notas[7] = {100, 50, 20, 10, 5, 2, 1};
	
	printf("Informe a quantia em R$: ");
	scanf("%d", &valor);

	i = 0;
	num_notas = 0;
	while(valor > 0){
		while(valor < notas[i])
			i++;
		valor -= notas[i];
		num_notas++;

	}

	printf("O número mínimo de notas é %d \n", num_notas);

	return 0;
}