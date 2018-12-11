#include <stdio.h>

void media(int* vet,int a);

void prencher_lista(int* vet,int n);

int min_tempo(int* vet,int a,int* minimo,int* volta_minimo);

int max_tempo(int* vet,int a,int* maximo,int* volta_maximo);

int main(int argc, char const *argv[])
{
	int a=0;
	scanf("%d",&a);
	int vet[a];
	prencher_lista(vet,a);

	int minimo=0;
	int maximo=0;

	int volta_min=0;
	int volta_max=0;

	min_tempo(vet,a,&minimo,&volta_min);
	max_tempo(vet,a,&maximo,&volta_max);

	media(vet,a);
	
	printf("volta %d tempo minimo %d\n",volta_min,minimo);
	printf("volta %d tempo maximo %d\n",volta_max,maximo);

	return 0;
}


int min_tempo(int* vet,int a,int* minimo,int* volta_minimo)
{
	int menor = vet[0];
	int volta = 1;
	
	for(int i=1;i<a;i++)
	{
		if(vet[i]<menor)
		{
			menor = vet[i];
			volta = i+1;
		}
	}

	*volta_minimo = volta;
	*minimo = menor;

}

int max_tempo(int* vet,int a,int* maximo,int* volta_maximo)
{
	int maior = vet[0];
	int volta = 1;
	
	for(int i=1;i<a;i++)
	{
		if(vet[i]>maior)
		{
			maior=vet[i];
			volta = i+1;
		}
	}

	*volta_maximo = volta;
	*maximo=maior;

}

void prencher_lista(int* vet,int n)
{
	int aux=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&aux);
		vet[i]=aux;
	}
}

void media(int* vet,int a)
{
	float m=0;
	float soma=0.0;
	for (int i = 0; i < a; ++i)
	{
		soma+=vet[i];
	}
	m=soma/a;
	printf("media = %g\n",m);

}