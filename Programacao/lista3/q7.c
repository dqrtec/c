#include <stdio.h>

int buscar(int *L, int x){
	int i;
	for(i=0; i<sizeof(L); i++){
		if(L[i] == x)
			return i+1;
	}
	return -1;
}

int main(void){
	int n, i, x, k;
	printf("Informe a quantidade de elementos da sequencia "); scanf("%d", &n);

	int seq[n];

	for(i=0; i<n; i++){
		printf("Informe o elemento %d da sequencia ", i+1); scanf("%d", &seq[i]);
	}

	printf("Informe o elemento que deseja buscar "); scanf("%d", &x);

	k = buscar(seq, x);

	if(k > 0)
		printf("O elemento %d está na posição %d da sequencia\n", x, k);
	else
		printf("O elemento %d não pertence a sequencia\n", x);


	return 0;
}