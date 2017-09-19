#include <stdio.h>
#include <math.h>

double delta(double a,double b,double c);

int raizes(double a, double b, double c, double *px1, double *px2);


int main(int argc, char const *argv[])
{
	double a;
	double b;
	double c;
	scanf("%lg %lg %lg",&a,&b,&c);
	/*scanf("%lg",&a);
	scanf("%lg",&a);*/
	double px1=0;
	double px2=0;
	printf("%d\n",raizes(a,b,c,&px1,&px2));
	printf("x1 -> %lg\n",px1);
	printf("x2 ->%lg\n",px2);

	return 0;
}

double delta(double a,double b,double c)
{
	return (b*b)-(4*a*c);
}

int raizes(double a, double b, double c, double *px1, double *px2){
	double del=delta(a,b,c);
	if(del==0)
	{
		*px1=*px2;
		*px2=-b/(2*a);
		return 1;
	}
	else if(del<0)
	{
		return 0;
	}
	else
	{
		double raiz=sqrt(del);
		*px1=(-b+raiz)/(2*a);
		*px1=(-b-raiz)/(2*a);
	}
}