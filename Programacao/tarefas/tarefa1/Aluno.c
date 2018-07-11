#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aluno.h"

int verificaMatricula(int matricula){
	if(matricula < 0)
		return 1;
	return 0;
}

int verificaNome(char* nome){
	if(nome == NULL)
		return 1;
	if(strlen(nome) > 50)
		return 1;
	return 0;
}

int verificaCurso(char* curso){
	if(curso == NULL)
		return 1;
	if(strlen(curso) > 30)
		return 1;
	return 0;
}



Aluno *novo_a(int matricula, char *nome, char *curso){
	
	Aluno* a = (Aluno*) malloc(sizeof(Aluno));
	if (a == NULL) {
		exit(1);
	}

	if(verificaMatricula(matricula))
		return NULL;
	if(verificaNome(nome))
		return NULL;
	if(verificaCurso(curso))
		return NULL;


	a->matricula = matricula;
	strcpy(a->nome, nome);
	strcpy(a->curso, curso);
	return a;
}


void libera_a(Aluno *aluno){
	if(aluno != NULL){

		aluno->matricula = 0;
		strcpy(aluno->nome, "");
		strcpy(aluno->curso, "");

		free(aluno);
		aluno = NULL;
	}
}


void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	*matricula = aluno->matricula;
	strcpy(nome, aluno->nome);
	strcpy(curso, aluno->curso);
}


void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){
	int i;
	if(aluno == NULL)
		i = 0;	
	else if(verificaMatricula(matricula))
		i = 0;	
		
	else if(verificaNome(nome))
		i = 0;	
		
	else if(verificaCurso(curso))
		i = 0;	
		
	else{

	aluno->matricula = matricula;
	strcpy(aluno->nome, nome);
	strcpy(aluno->curso, curso);
	}
}


int tamanho_a(){
	return (int) sizeof(Aluno);
}