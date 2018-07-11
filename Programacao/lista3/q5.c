#include <stdio.h>

int main(void){
	int i, n, somaTermo;
	printf("Informe a quantidade de digitos "); scanf("%d", &n);

	int seq1[n], seq2[n], soma[n+1];

	for(i=0; i<n; i++){
		printf("Informe %d digito da primeira sequência ", i+1); scanf("%d", &seq1[i]);
		
	}
	printf("\n");
	for(i=0; i<n; i++){
		printf("Informe %d digito da segunda sequência ", i+1); scanf("%d", &seq2[i]);

	}
	for(i=0; i<=n; i++){
		soma[i] = 0;	
	}
	for(i=n; i>0; i--){
		
		soma[i] += seq1[i-1] + seq2[i-1];

		if(soma[i] >= 10){
			soma[i] -= 10;
			soma[i-1] = 1;
		}
		
	}

	if(soma[0] == 0)
		i = 1;
	else
		i = 0;

	printf("A soma de é ");
	for(i; i<=n; i++){
		printf("%d", soma[i]);	
	}
	printf("\n");

	return 0;
}

