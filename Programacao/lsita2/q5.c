#include <stdio.h>

void misterio(int *p, int *q);

int main(int argc, char const *argv[])
{
	int i=6, j=10;
	misterio(&i, &j);	
	printf("i=%d\t j=%d\n",i,j);
	return 0;
}

void misterio(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}