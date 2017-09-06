#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	float angulo , raio;
	float x , y;
	printf("Digite o valor do angulo: ");
	scanf("%f",&angulo);

	printf("Digite o valor do raio: ");
	scanf("%f",&raio);

	angulo = (3.1415926535897932384626433832795/180) * angulo;

	x= raio*cos(angulo);
	y= raio*sin(angulo);

	printf("(%f , %f )",x,y);

	return 0;
}