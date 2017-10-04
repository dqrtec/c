#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	int n,soma=0,aux=0;

	scanf("%d",&n);

	int n1[n] , n2[n] , n3[n+1];

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&n1[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&n2[i]);
	}

	for (int i = 0; i < n+1; i++)
	{
		n3[i]=0;
	}


	printf("\n\n>>");

	for (int i = n-1; 0 <= i; i--)
	{
		soma=n2[i]+n1[i];
		printf("soma %d\n",soma);
		//printf("soma= %d\n",soma );
		aux=n3[i+1];
		n3[i+1]=((soma+n3[i+1])%10);
		printf("atribuição n[i+1] %d >> %d\n",i, n3[i+1]);
		n3[i]+=aux+((soma-((soma+aux)%10))/10);
		printf("atribuição n[i] %d >> %d\n",i, n3[i]);

	}

	for (int i = 0; i < n+1; i++)
	{
		printf("%d ", n3[i]);
	}

	return 0;
}