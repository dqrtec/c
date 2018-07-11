#include <stdio.h>


int main(void){

	double n1, n2;
	char op;

	printf("Informe os valores no seguinte formato: <operando> <operador> <operando>.\n>> ");
	scanf("%lf %c %lf", &n1, &op, &n2);

	switch(op){
		case '+':
			printf("Soma: %.2lf\n", (n1+n2));
			break;

		case '-':
			printf("Subtração: %.2lf\n", (n1-n2));
			break;

		case '*':
			printf("Multiplicação: %.2lf\n", (n1*n2));
			break;

		case '/':
			while(n2 == 0){
				printf("O segundo número deve ser diferente de zero\nTente novamente!\n\n>>");
				scanf("%lf", &n2);
			}
			printf("Divisão: %.2lf\n", (n1/n2));
			break;

		default:
			printf("Opção inválida\n");	

	}

	return 0;
}