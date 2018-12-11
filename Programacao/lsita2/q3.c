#include <stdio.h>


int mdc(int p,int q)
{
	int r=0;
	int aux;
	do
	{
		r=(p%q);
		p = q;
		q=r;
	}while(r!=0);
	return p;
}

int main(int argc, char const *argv[])
{
	//printf("\aa\v", );
	int x=100;
	int y=50;
	int z=1000;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);

	int resultado = mdc(mdc(x,y),z);
	printf("%d",resultado);
	return 0;
}