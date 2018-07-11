#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* TAD: Aluno (matricula, nome, curso) */ 
typedef struct aluno Aluno;

/* Aloca e retorna um aluno com os dados passados por parâmetro */ 
Aluno *novo_a(int matricula, char *nome, char *curso);

/* Libera a memória de um aluno previamente criado */ 
void libera_a(Aluno *aluno);

/* Copia os valores de um aluno para as referências informadas */ 
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso);

/* Atribui novos valores aos campos de um aluno */
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso);

/* Retorna o tamanho em bytes do TAD aluno */ 
int tamanho_a();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Aluno.h"

/* TAD: Fila (tamanho)*/ 
typedef struct fila Fila;

/* Aloca e retorna uma fila de tamanho informado */ 
Fila *nova_f(int tamanho);

/* Libera a memória de uma fila previamente criada */ 
void destroi_f(Fila *fila);

/* Adiciona um aluno na fila. Retorna 1 se der certo e 0 caso contrário */ 
int adiciona_f(Fila *fila, Aluno *aluno);

/* Remove um aluno na fila. Retorna 1 se der certo e 0 caso contrário */ 
int retira_f(Fila *fila);

/* Busca aluno pelo número de matricula. Retorna o aluno se der certo e NULL caso contrário */
Aluno *busca_f(Fila *fila, int matricula);

/* Retorna 1 se a fila estiver cheia e 0 caso contrário */ 
int cheia_f(Fila *fila);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct aluno
{
	int matricula;
	char nome[50];
	char curso[30];
};

struct fila
{
	int tamanho;
	Aluno* a;
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int matricula=1;
	char nome[50]={'A','b','r','a','a','o'};
	char curso[30]={'C','o','m','p','u','t','a','c','a','o'};
	float pontuacao = 0;

	Aluno *aluno = NULL;
	libera_a(aluno);
	if (aluno == NULL) {
		printf("[Passou 0.67] - Teste da função libera_a() com dados nulos!\n");	
		pontuacao = 0.67;
	} else {
		printf("[Falhou 0.00] - Teste da função libera_a() com dados nulos!\n");
	}

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Aluno* novo_a(int matricula, char *nome, char *curso)
{
	if (matricula>=0)
	{
		Aluno* x=(Aluno*) malloc(sizeof(Aluno));
		if(x==NULL)
		{
			printf("ESPAÇO INSUFICIENTE!\n");
			return x;

		}
		x->matricula=matricula;
		strcpy(x->nome,nome);
		strcpy(x->curso,curso);
		return x;
	}
	else
	{
		return NULL;
	}
}

void libera_a(Aluno *aluno)
{
	if(aluno==NULL)
	{
		printf("è nulo\n");
	}
	else{
	aluno->matricula=-45;
	free(aluno);
	aluno=NULL;
}

}

void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso)
{
	*matricula=aluno->matricula;
	strcpy(nome,aluno->nome);
	strcpy(curso,aluno->curso);
}

void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso)
{
	if(nome==NULL || curso==NULL)
	{
		printf("nao rodou!!!!!!!!!!!!\n");
	}

	aluno->matricula=matricula;
	strcpy(aluno->nome,nome);
	strcpy(aluno->curso,curso);
}

int tamanho_a()
{
	return (int) sizeof(Aluno);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////