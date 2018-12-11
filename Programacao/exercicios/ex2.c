#include <stdio.h>
int main(int argc, char const *argv[])
{
	float preco_galao;
	float valor_dolar;
	float valor_reais;
	float litros= 1; //3.7854;
	float valor;

	printf("Digite o valor do galao em dolares :");
	scanf("%g",&preco_galao);
	printf("\n");

	printf("Digite o valor do dolar :");
	scanf("%g",&valor_dolar);
	printf("\n");

	valor_reais= preco_galao * valor_dolar;
	valor = valor_reais/litros;

	printf("valor da gasolina em litros: %g\n", valor);







	return 0;
}
