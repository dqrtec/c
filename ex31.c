#include <stdio.h>
int main(int argc, char const *argv[])
{
	float segundos;
	int aux;

	printf("Digite o valor em segundos :");
	scanf("%f",&segundos);
	printf("\n");

	aux=(int)(segundos/3600);
	printf("%02d:",aux);
	segundos = segundos - (aux*3600);

	aux = (int)(segundos/60);
	printf("%02d:",aux);
	segundos = segundos - (aux*60);

	printf("%05.2f\n",segundos);




}