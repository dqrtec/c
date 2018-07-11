// se nao usar o getchar, a leitura do que está abaixo fica incorreta, como se armazenasse somente o ENTER
#include <stdio.h>

int main(void){

	char gabarito[10];
	char gabaritoAluno1[10];
	char gabaritoAluno2[10];
	char gabaritoAluno3[10];

	int matricula1;
	int matricula2;
	int matricula3;

	int nota1 = 0;
	int nota2 = 0;
	int nota3 = 0;

	int aprovados = 0;
	
	int i;

	for(i=0; i<10; i++){	
		printf("(GABARITO) questão %d ", i+1); scanf("%c", &gabarito[i]);
		getchar();
	}	

	// ALUNO 1
	printf("\nInforme a matrícula do primeiro aluno "); scanf("%d", &matricula1);
	getchar();
	
	for(i=0; i<10; i++){
		printf("Informe o item da questao %d ", i+1); scanf("%c", &gabaritoAluno1[i]);
		getchar();
	}

	// ALUNO 2
	printf("\nInforme a matrícula do segundo aluno "); scanf("%d", &matricula2);
	getchar();
	
	for(i=0; i<10; i++){
		printf("Informe o item da questao %d ", i+1); scanf("%c", &gabaritoAluno2[i]);
		getchar();
	}

	// ALUNO 3
	printf("\nInforme a matrícula do terceiro aluno "); scanf("%d", &matricula3);
	getchar();
	
	for(i=0; i<10; i++){
		printf("Informe o item da questao %d ", i+1); scanf("%c", &gabaritoAluno3[i]);
		getchar();
	}

	// SOMA DOS ACERTOS INDIVIDUAIS
	for(i=0; i<10; i++){
		if(gabaritoAluno1[i] == gabarito[i])
			nota1 += 1;
		if(gabaritoAluno2[i] == gabarito[i])
			nota2 += 1;
		if(gabaritoAluno3[i] == gabarito[i])
			nota3 += 1;
	}

	// Ficha aluno 1
	printf("Matrícula do aluno: %d\n", matricula1);
	printf("Gabarito \n");
	for(i=0; i<10; i++){
		printf("%d - %c\n", i+1, gabaritoAluno1[i]);
	}
	printf("Nota final: %d\n\n", nota1);

	// Ficha aluno 2
	printf("Matrícula do aluno: %d\n", matricula2);
	printf("Gabarito \n");
	for(i=0; i<10; i++){
		printf("%d - %c\n", i+1, gabaritoAluno2[i]);
	}
	printf("Nota final: %d\n\n", nota2);
	
	// Ficha aluno 3
	printf("Matrícula do aluno: %d\n", matricula3);
	printf("Gabarito \n");
	for(i=0; i<10; i++){
		printf("%d - %c\n", i+1, gabaritoAluno3[i]);
	}
	printf("Nota final: %d\n\n", nota3);

	if(nota1 >= 7)
		aprovados += 1;
	if(nota2 >= 7)
		aprovados += 1;
	if(nota3 >= 7)
		aprovados += 1;

	printf("Percentual de aprovação: %.2lf %% \n", aprovados*100.0/3);

	return 0;
}