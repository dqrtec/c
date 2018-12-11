#include <stdio.h>
#include <math.h>
int main(int argc, char **argv) {
	float so , vo , a , t ;
	float s,v;

	printf("so ");
	scanf("%f",&so);

	printf("vo ");
	scanf("%f",&vo);

	printf("a ");
	scanf("%f",&a);

	printf("t ");
	scanf("%f",&t);

	s = so + vo +((a*t*t)/2);

	v = vo + (a*t);

	printf("valor de s = %f   , valor de v = %f",s,v);

	scanf("%f",&t);

}