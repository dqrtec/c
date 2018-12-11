#include <stdio.h> 
int main(int argc, char const *argv[])
{
	int n1,n2;
	char operacao;
	scanf("%d %c %d",&n1,&operacao,&n2);
	
	switch(operacao)
	{
		case '+':
			printf("%d + %d = %d\n",n1,n2,(n1+n2) );
			break;

		case '-':
			printf("%d + %d = %d\n",n1,n2,(n1-n2) );
			break;

		case '*':
			printf("%d + %d = %d\n",n1,n2,(n1*n2) );
			break;

		case '/':
			printf("%d + %d = %d\n",n1,n2,(n1/n2) );
			break;
	}
	return 0;
}