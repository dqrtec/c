#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(void){

	double ang, r, x, y;

	printf("Informe o ângulo >> ");
	scanf("%lf", &ang);

	printf("Informe o raio >> ");
	scanf("%lf", &r);

	ang = (ang * PI)/180;

	x = r * cos(ang);
	y = r * sin(ang);

	printf("Suas coordenadas cartesianas são: X = %.2lf, Y = %.2lf \n", x, y);
	return 0;
}