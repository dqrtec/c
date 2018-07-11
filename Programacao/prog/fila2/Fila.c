#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila{
	Aluno* inicio;
	Aluno* fim;
	int tamanho;
	int count;
};

int verificaTamanho(int tamanho){
	if(tamanho < 0)
		return 1;
	return 0;
}

Fila *nova_f(int tamanho){
	Fila* f = (Fila*) malloc(sizeof(Fila));

	if (f == NULL)
		return NULL;
	if(verificaTamanho(tamanho))
		return NULL;

	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = tamanho;
	f->count = 0;

	return f;
}

void destroi_f(Fila *fila){
	if(fila != NULL){
		free(fila);
		fila = NULL;
	}
}

int adiciona_f(Fila *fila, Aluno *aluno){
	
	if(fila == NULL)
		return 0;
	
	if(aluno == NULL)
		return 0;
	
	if(cheia_f(fila))
		return 0;

	if(fila->fim == fila->tamanho)
		fila->fim = 0;

	fila->alunos[fila->fim] = aluno;
	fila->fim++;

	return 1;

}

int retira_f(Fila *fila){

	if(fila == NULL)
		return 0;

	if(fila->ini == fila->fim)
		return 0;

	
	if(fila->ini > fila->tamanho)
		fila->ini = 0;
	
	fila->ini++;
	
	return 1;

}

Aluno *busca_f(Fila *fila, int matricula){
		
	if(fila == NULL)
		return NULL;

	if(fila->ini == fila->fim)
		return NULL;
	 
	int i, tamanho;
	int matricula_aluno;
	char nome[50];
	char curso[30];

	if(fila->ini < fila->fim)
		tamanho = fila->fim;
	else
		tamanho = fila->tamanho + fila->fim;


	for(i=fila->ini; i<tamanho; i++){
		if(i == fila->tamanho)
			i = 0;
		acessa_a(fila->alunos[i], &matricula_aluno, nome, curso);
		if(matricula_aluno == matricula)
			return fila->alunos[i];
		
		}
	return NULL;
}

int cheia_f(Fila *fila){
	if(fila->fim == fila->tamanho && fila->ini == 0)
		return 1;
	
	if(fila->ini == fila->fim + 1)
		return 1;

	return 0;
}