#include <stdio.h>
#include <math.h>

double pot(double x, int k){
	if(k == 0)
		return 1.0;
	return pot(x, k-1)*x;
}

int main(void){
	double x, potencia;
	int k;

	printf("Informe a base da potência \n"); scanf("%lf", &x);
	printf("Informe o expoente da potência \n"); scanf("%d", &k);
	potencia = pot(x, k);
	printf("Função POT -> %.1lf^%d = %.1lf\n", x, k, potencia);
	printf("Função POW -> %.1lf^%d = %.1lf\n", x, k, pow(x, k));
	return 0;
}
