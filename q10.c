#include <stdio.h>

int main(int argc, char **argv) {
	int pc , pssoa;
	int teste = 1;
	while(teste == 1)
	{
		printf("digite a opção da pessoa e logo depois a da maquina ");
		scanf("%d %d",&pssoa , &pc);
		if(pssoa == pc)
		{
			printf("Empate. Repita a operação");
		}
		else
		{
			teste = 2;
			if((pc>pssoa) || (pc==(pssoa%3)))
			{
				printf("A Pessoa ganhou!");
			}
			else
			{
				printf("A PC ganhou");
			}
		}
	}
	scanf("%d %d",&pssoa , &pc);
}

