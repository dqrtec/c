#include <math.h>
#include <stdio.h>

#define PI 3.1415

int main(int argc, char const *argv[])
{
	
	double volume;
	int raio;
	printf("Digit eo valor do raio:");
	scanf("%d",&raio);

	volume = (4/3.0)*PI*pow(raio,3);
	printf("%lf\n", volume );


	return 0;
}