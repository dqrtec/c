#include <stdio.h>

int min(int* vet,int a,int* minimo);

int max(int* vet,int a,int* maximo);

int main(int argc, char const *argv[])
{
	int a=10;
	int vet[]={1,2,3,4,5,6,7,8,9,10};
	int minimo=0;
	int maximo=0;
	min(vet,a,&minimo);
	max(vet,a,&maximo);
	printf("minimo %d\n",minimo);
	printf("maximo %d\n",maximo);
	return 0;
}

int min(int* vet,int a,int* minimo)
{
	int menor = vet[0];
	
	for(int i=1;i<a;i++)
	{
		if(vet[i]<menor)
		{
			menor=vet[i];
		}
	}

	*minimo=menor;

}


int max(int* vet,int a,int* maximo)
{
	int maior = vet[0];
	
	for(int i=1;i<a;i++)
	{
		if(vet[i]>maior)
		{
			maior=vet[i];
		}
	}

	*maximo=maior;

}