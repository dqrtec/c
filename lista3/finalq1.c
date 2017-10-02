#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5};
	int b[]={5,6,7,8,9,1,3,2};
	int i,j;

	for(i=0;i<5;i++)
	{
		for (j = 0; j < 8; j++)
		{
			if(a[i]==b[j])
			{
				printf(" %d", a[i]);
				break;
			}
		}
	}

	return 0;
}