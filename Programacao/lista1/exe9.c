#include <stdio.h>
#include <math.h>

double velocidade(double v0, double a, double t){
	double vel = v0 + (a*t);
}

double espaco(double s0, double v0, double a, double t){
	double esp = s0 + v0 + (a * pow(t, 2))/2;
}

int main(void){

	double s0, v0, a, t, s, v;

	printf("Informe os valores pedidos \n");

	printf("Informe o espaço inicial >> ");
	scanf("%lf", &s0);
	
	printf("Informe a velocidade inicial >> ");
	scanf("%lf", &v0);
	
	printf("Informe a aceleração >> ");
	scanf("%lf", &a);
	
	printf("Informe o tempo >> ");
	scanf("%lf", &t);

	s = espaco(s0, v0, a, t);
	v = velocidade(v0, a, t);

	printf("O valor do espaço final é: %.2lf \n", s);
	printf("O valor da velocidade final é: %.2lf \n", v);

	return 0;
}