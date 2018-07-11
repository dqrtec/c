#include <stdio.h>
#include <math.h>

double *calcularRaiz(int a, int b, int delta){
	static double root[2];
	double x1 = (-b + sqrt(delta))/(2*a);
	double x2 = (-b - sqrt(delta))/(2*a);

	root[0] = x1;
	root[1] = x2;
	return root;
}

int main(void){

	double a, b, c, x1, x2, *raiz; 
	int delta;

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

	delta = pow(b, 2) - (4*a*c);
	raiz = calcularRaiz(a, b, delta);
	x1 = raiz[0];
	x2 = raiz[1];

	if (delta > 0){
		printf("Há duas raízes reais diferentes\n");
		printf("x1 = %.2lf\n", x1);
		printf("x2 = %.2lf\n", x2);
	}
	else if(delta == 0){
		printf("Há duas raízes reais iguais\n");
		printf("x1 = x2 = %.2lf\n", x1);
	}
	else{
		printf("Não há raízes reais\n");
	}
	

	return 0;
}