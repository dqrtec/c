#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	double a ,b ,c;
	double x1,x2 , delta;
	printf("\n Digite a: ");
	scanf("%lf",&a);

	printf("\n Digite b: ");
	scanf("%lf",&b);

	printf("\n Digite c: ");
	scanf("%lf",&c);
	

	delta = (b*b)-(4*a*c);

	if(delta<0)
	{
		printf("Não existe raiz no conjunto dos números reais!\n");
		x1=0;
		x2=0;
	}
	else if(delta==0)
	{
		x1 = -b/(2*a);
		x2 = x1;
	}
	else
	{
		x1=((-b+ sqrt(delta))/2*a);
		x2=((-b- sqrt(delta))/2*a);
	}

	printf("as raizes são : x1: %g , x2: %g\n",x1,x2);


	return 0;
}