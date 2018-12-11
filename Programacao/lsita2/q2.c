#include <stdio.h>
#include <math.h>

int primo(int n) 
{
	if (n == 2) {
		return 1;
	} 
	else if (n<2 || (n%2)==0) 
	{
		return 0;
	} 
	else 
	{
		int lim = (int) sqrt(n);
		for (int i=3; i<= lim; i+=2)
		{
			if (n% i == 0) 
			{
				return 0;
			}
		}
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	int x=10;
	do
	{
		if (primo(x)==1)
		{
			printf("%d\n",x);
		}
		--x;
	}while(x>=2);

	printf("\n|\n|\n|\n|\n|\n");
	int n=10;
	int aux=1;
	for(int i=1;aux<=n;i++)
	{
		if(primo(i)==1)
		{
			aux++;
			printf("%d\n",i);
		}
	}


	return 0;
}