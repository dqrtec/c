#include <stdio.h>

double media(double *notas, int num_notas){
	double media = 0;
	for(int i = 0; i < num_notas; i++){
		media += notas[i];
	}
	media /= num_notas;
	return media;
}

int main(void){
	double p1, p2, p3, notas[3];

	printf("Informe a nota das duas AP's \n");
	
	printf("AP 1 >> ");
	scanf("%lf", &p1);
	
	printf("AP 2 >> ");
	scanf("%lf", &p2);

	notas[0] = p1;
	notas[1] = p2;

	if(media(notas, 2) >= 5 && p1 >= 3 && p2 >= 3){
		printf("Parabéns você está aprovado \n");
	}
	else{
		printf("Você não passou. Informe a nota da terceira prova\n");
		printf("AP 3 >> ");
		scanf("%lf", &p3);

		notas[2] = p3;
		if(media(notas, 3) >= 5){
			printf("Parabéns você está aprovado \n");
		}
		else{
			printf("Tente novamente \n");
		}	
	}
		
	return 0;
}