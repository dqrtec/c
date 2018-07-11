#include <stdio.h>
#include <math.h>
#define pi 3.14

int main(void){
	
	double r, volume;

	printf("Informe o valor do raio (m): ");
	scanf("%lf", &r);

	volume = (4 * pow(r, 3) * pi)/3;
	printf("O volume da esfera de raio %.2lfm é %.2lfm \n", r, volume);
	
	return 0;
}