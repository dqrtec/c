#include <stdio.h>
#define galao 3.7854

int main(void){
	double preco, real, preco_litro_us, preco_litro_br;

	printf("Informe o preço do galão de gasolina: US$ ");
	scanf("%lf", &preco);
	
	printf("Informe o preço do real em relação ao dólar: R$ ");
	scanf("%lf", &real);

	preco_litro_us = preco/galao;
	preco_litro_br = preco_litro_us*real;

	printf("O preço da gasolina é R$ %.4lf\n", preco_litro_br);

	return 0;
}