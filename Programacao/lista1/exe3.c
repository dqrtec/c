#include <stdio.h>

int main(void){
	int horas, minutos, segundos;

	printf("Informe os segundos: ");
	scanf("%d", &segundos);

	horas = segundos/3600;
	minutos = (segundos%3600)/60;
	segundos = (segundos%3600)%60;

	printf("%02d:%02d:%02d\n", horas, minutos, segundos);

	return 0;
}