#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int soma=1000000000;
	printf("%d\n",soma);
	int **v = (int **) malloc(soma*sizeof (int*));

int i;
int j;
	for (i = 1; i < soma; ++i)
	{
		v[i] = (int *) malloc(soma*sizeof (int));
		
		for(j=0; j<soma; j++){
			v[i][j] = 0;
		}
	}
	return 0;
}