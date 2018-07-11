#include <stdio.h>
#include <math.h>

double calcDelta(double a, double b, double c){
	double result = pow(b, 2) - (4*a*c);
	return result;
}

int calcularRaiz(double a, double b, double c, double *px1, double *px2){
	double delta = calcDelta(a, b, c);
	*px1 = (-b + sqrt(delta))/(2*a);
	*px2 = (-b - sqrt(delta))/(2*a);

	if(delta < 0)
		return 0;
	
	else if(delta == 0)
		return 1;

	return 2;
}

int main(void){

	double a, b, c, delta, x1, x2, raizes; 
	printf("Informe os coeficientes a, b, c\n");
	
	printf("a >> ");
	scanf("%lf", &a);
	
	printf("b >> ");
	scanf("%lf", &b);
	
	printf("c >> ");
	scanf("%lf", &c);

	while(a == 0){
		printf("Valor de 'a' deve ser diferente de 0. Informe novamente o valor de a\n");
		printf("a >> ");
		scanf("%lf", &a);
	}
	delta = calcDelta(a, b, c);
	raizes = calcularRaiz(a, b, c, &x1, &x2);

	if (raizes > 1){
		printf("Há duas raízes reais diferentes\n");
		printf("x1 = %.2lf\n", x1);
		printf("x2 = %.2lf\n", x2);
	}
	else if(raizes == 1){
		printf("Há duas raízes reais iguais\n");
		printf("x1 = x2 = %.2lf\n", x1);
	}
	else{
		printf("Não há raízes reais\n");
	}
	
	return 0;
}