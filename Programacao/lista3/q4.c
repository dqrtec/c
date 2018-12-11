#include <stdio.h>

void somatorio(int* vet_a,int* vet_b,int* s,int n)
{
	for(int i =0;i<n;i++)
	{
		*s += vet_a[i]*vet_b[i];
	}
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int b[]={10,9,8,7,6,5,4,3,2,1};
	int soma=0;
	int n=10;
	somatorio(a,b,&soma,n);
	printf("%d\n",soma);

	return 0;
}
