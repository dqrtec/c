#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

Fila *nova_f(int tamanho){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	
	if (f == NULL)
		return NULL;

	f->ini = 0;
	f->fim = 0;
	f->tamanho = tamanho;

	return f;
}

void destroi_f(Fila *fila){
	free(fila);
	fila = NULL;
}

int adiciona_f(Fila *fila, Aluno *aluno){
	if(cheia_f(fila))
		return 0;
	
	int indice;
	indice = (fila->ini + fila->fim) % fila->tamanho;
	fila->alunos[indice] = aluno;
	fila->fim++;

	return 1;
}

int retira_f(Fila *fila){
	if(fila->fim == 0)
		return 1;

	Aluno* x;
	x = fila->alunos[fila->ini];
	fila->ini = (fila->ini + 1) % fila->tamanho;
	fila->fim--;

	return 1;
}

Aluno *busca_f(Fila *fila, int matricula){
	int i = 0;
	while(i <= fila->tamanho){
		if(fila->alunos[i]->matricula == matricula)
			return fila->alunos[i];
		
		i++;
		}
	return NULL;
}


int cheia_f(Fila *fila){
	if(fila->fim == fila->tamanho)
		return 1;

	return 0;
}