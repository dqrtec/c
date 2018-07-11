#include <stdio.h>

void misterio(int *p, int *q){
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

int main(void){
	
	int i=6, j=10;
	misterio(&i, &j);
	printf("%d %d\n", i, j);	
	return 0;
}
