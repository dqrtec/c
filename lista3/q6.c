#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n,i,j,op,soma;
	scanf("%d",&n);
	soma=n-1;

	
	int* v = (int*)malloc((sizeof(int)*n));

	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}

	do
	{
		printf("digite 0 para sair e 1 para alocar mais memoria\n");
		scanf("%d",&op);

		if(op==1)
		{

			scanf("%d",&n);
			v = (int*) realloc(v,(n*sizeof(int)));
				for(i=soma+1;i<=n+soma;i++)
				{
					scanf("%d",&v[i]);
				}
			soma+=n;
		}
	}while(op!=0);

	printf("LISTA DE NUMEROS ADICIONADOS\n");
	for (i = 0; i <= soma; i++)
	{
		printf("%d , ",v[i]);
	}

	return 0;
}