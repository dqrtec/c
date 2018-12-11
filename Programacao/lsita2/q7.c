#include <stdio.h>
#include <math.h>

double pot(double x, int k);

int main(int argc, char const *argv[])
{
	int k=5;
	double x=2;
	printf("pow %lg\n", pow(x,k));
	printf("pot %lg\n", pot(x,k));
	return 0;
}

double pot(double x, int k)
{
	if(k==1)
	{
		return x;
	}
	return x*pot(x,k-1);
}