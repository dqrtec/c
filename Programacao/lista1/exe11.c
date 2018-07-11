#include <stdio.h>
#include <stdlib.h>

int verificaTriangulo(int a, int b, int c){
	if((abs(b-c) < a) && (a < (b+c)) && (abs(a-c) < b) && (b < (a+c)) && (abs(a-b) < c) && (c < (a+b)))
		return 1;
	else
		return 0;
}

int main(void){

	int a, b, c, is_triangle;

	printf("Informe os lados a, b, c do triângulo\n");
	printf("a >> ");
	scanf("%d", &a);

	printf("b >> ");
	scanf("%d", &b);

	printf("c >> ");
	scanf("%d", &c);

	is_triangle = verificaTriangulo(a, b, c);
	if(is_triangle){
		if((a == b) && (b == c))
			printf("O Triângulo é equilátero\n");
		else if((a == b) || (b == c) || (a == c))
			printf("O Triângulo é isóceles\n");
		else
			printf("O Triângulo é escaleno\n");
	}
	else
		printf("Os lados não formam um triầngulo\n");

	return 0;
}