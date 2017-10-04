#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int soma=1000000000;
	printf("%d\n",soma);
	int *v = (int *) malloc(soma*sizeof (int));
	int *a = (int *) malloc(1000000000*sizeof (int));
	int *b = (int *) malloc(1000000000*sizeof (int));
	int *c = (int *) malloc(1000000000*sizeof (int));
	int *d = (int *) malloc(1000000000*sizeof (int));
	int *e = (int *) malloc(1000000000*sizeof (int));
	int *f = (int *) malloc(1000000000*sizeof (int));
	printf("%d\n",soma);

	for (int i = 1; i < 500000000000000000; ++i)
	{
		for (int j = 1; j < 500000000000000000; ++j)
		{
			//printf("%d\n",j);
			soma=soma*1.1;
			printf("%d\n",soma);
			v = (int *) realloc(v, ((soma)*sizeof(int)) );
			a = (int *) realloc(a, ((soma)*sizeof(int)) );
			b = (int *) realloc(b, ((soma)*sizeof(int)) );
			c = (int *) realloc(c, ((soma)*sizeof(int)) );
			d = (int *) realloc(d, ((soma)*sizeof(int)) );
			e = (int *) realloc(e, ((soma)*sizeof(int)) );
			f = (int *) realloc(f, ((soma)*sizeof(int)) );
		}
	}
	//free(v);
	return 0;
}