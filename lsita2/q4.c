#include <stdio.h>
#include <math.h>

#define PI 3.14

double area(double r);

double volume(double r);


int main(int argc, char const *argv[])
{
	double r;
	scanf("%lg",&r);
	printf("area = %lg\n",area(r));
	printf("volume = %lg",volume(r));
	return 0;
}

double area(double r)
{
	return 4*PI*pow(r,4);
}

double volume(double r)
{
	double diva=(double)4/3;
	return diva*PI*pow(r,3);
}