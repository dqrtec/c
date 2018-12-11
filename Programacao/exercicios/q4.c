#include <stdio.h>

void main()
{
	int valor;
	int n100,n20,n50,n10,n5,n2,n1;
	n100 = 0;
	n50 = 0;
	n20 = 0;
	n10 = 0;
	n5 = 0;
	n2 = 0;
	n1 = 0;
	scanf("%d",&valor);

	n100=valor/100;
	valor-=n100*100;
	n50=valor/50;
	valor-=n50*50;
	n20=valor/20;
	valor-=n20*20;
	n10=valor/10;
	valor-=n10*10;
	n5=valor/5;
	valor-=n5*5;
	n2=valor/2;
	valor-=n2*2;
	n1=valor/1;
	valor-=n1;

	printf("quantidade de notas de 100 : %d\n",n100);
	printf("quantidade de notas de 50 : %d\n",n50);
	printf("quantidade de notas de 20 : %d\n",n20);
	printf("quantidade de notas de 10 : %d\n",n10);
	printf("quantidade de notas de 5 : %d\n",n5);
	printf("quantidade de notas de 2 : %d\n",n2);
	printf("quantidade de notas de 1 : %d\n",n1);
	


}