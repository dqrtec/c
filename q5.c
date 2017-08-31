#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n1,n2,n3;
	scanf("%d",&n1);
	printf("\n");
	scanf("%d",&n2);
	printf("\n");
	scanf("%d",&n3);
	printf("\n");

	printf("%d  %d  %d\n",n1,n2,n3);

	int aux;

	if(n1>n2)
	{
		aux = n1;
		n1=n2;
		n2=aux;

		if(n2>n3)
		{
			aux=n3;
			n3=n2;
			n2=aux;

			if(n2<n1)
			{
				aux=n1;
				n1=n2;
				n2=aux;
			}
		}
	}
	else
	{
		if(n2>n3)
		{
			aux=n3;
			n3=n2;
			n2=aux;

			if(n1>n2)
			{
				aux=n1;
				n1=n2;
				n2=aux;
			}
		}
	}


	printf("sequencia crescente:%d  %d  %d\n",n1,n2,n3);
	printf("maior numero:%d \n",n3);
/*
	if(n1>n2)
	{
		if(n1>n3)
		{
			maior = n1;

			if(n2>n3)

		}
		else
		{
			maior = n3;
		}
	}
	else
	{
		if(n2>n3)
		{
			maior = n2;
		}
		else
		{
			maior = n3;
		}
	}
*/

	return 0;
}