#include <stdio.h>

int vencedor(int jog1, int jog2){
	if(jog1 == 0 && jog2 == 2)
		return 1;
	else if(jog1 == 2 && jog2 == 0)
		return 2;
	else if(jog1 > jog2)
		return 1;
	else if(jog2 > jog1)
		return 2;
	else
		return 0;
}

int main(void){

	int jog1, jog2, venceu;
	
	printf("## Pedra, papel, tesoura ## \n");
	printf("\t Digite \n\t 0 --- Pedra \n\t 1 --- Papel \n\t 2 --- Tesoura \n\n\n");

	while(1){
		printf("Jogador 1 >> ");
		scanf("%d", &jog1);
		
		printf("Jogador 2 >> ");
		scanf("%d", &jog2);

		while(jog1 != 0 && jog1 != 1 && jog1 != 2){
			printf("\nOpção inválida!! \nJogador 1 >> ");
			scanf("%d", &jog1);
		}

		while(jog2 != 0 && jog2 != 1 && jog2 != 2){
			printf("\nOpção inválida!! \nJogador 2 >> ");
			scanf("%d", &jog2);
		}

		venceu = vencedor(jog1, jog2);
		if(!venceu)
			printf("-> Empate <-\n\n\n");
		else	
			printf("-> Jogador %d venceu <-\n\n\n", venceu);
	}

	return 0;
}