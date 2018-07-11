#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

float calcArea(float raio){
	return 4*PI*pow(raio, 2);
}

float calcVolume(float raio){
	return (4.0/3)*PI*pow(raio, 3);
}


int main(void){
	float raio, volume, area;

	printf("Informe o valor do raio \n"); scanf("%f", raio);
	area = calcArea(raio);
	volume = calcVolume(raio);

	printf("O valor da área é %.2f u.a.\n", area);
	printf("O valor do volume é %.2f u.v.\n", volume);
	return 0;
}