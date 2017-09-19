#include <stdio.h>


int mdc(int *p,int *q)
{
	int r=0;
	int aux;
	do
	{
		r=(*p%*q);
		*p = *q;
		*q=r;
	}while(r!=0);
	//printf("%d",p);
}

int main(int argc, char const *argv[])
{
	//printf("\aa\v", );
	int x=10;
	int y=5;

	mdc(&x,&y);
	printf("%d",x);
	return 0;
}