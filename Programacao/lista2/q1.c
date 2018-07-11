#include <stdio.h>

int mdc(int x, int y){
	int r, q;
	r = 1;
	while(r > 0){
		q = x/y;
		r = x - (y*q);
		x = y;
		y = r;
	}
	return x;
}

int main(){
	int n1, n2, n3, result;
	printf("Informe os valores de n1 e n2\n");
	scanf("%d %d", &n1, &n2);
	result = mdc(n1, n2);
	printf("O MDC de %d, %d é %d\n", n1, n2, result);

	return 0;
}