#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viagem.h"
int count_id = 0;

struct viagem
{
	int id;
	int	dia;
	int	mes;
	int	ano;
	char cidade[61];
	char pais[31];
	int	periodo;
	Viagem* pai;
	Viagem* direita;
	Viagem* esquerda;
};
//############################################# suplementares #####################################################################################
int dias_do_inicio(Viagem* viagem)
{
	int dias =(int) viagem->dia + (viagem->mes*30) + (viagem->ano*365);
	printf("dias do inicio%d\n",dias);
	return dias;
}

int dias_do_fim(int inicio , Viagem* viagem)
{
	int dias =(int) inicio + viagem->periodo;
	return dias;
}

Viagem* minimo(Viagem* viagem)
{
	if(viagem != NULL)
	{
		while(viagem->direita != NULL)
		{
			viagem = viagem->direita;
		}
		return viagem;
	}
	return NULL;
}

Viagem* sucessor(Viagem* viagem)
{
	if (viagem != NULL)
	{
		if (viagem->direita != NULL)
		{
			return(minimo(viagem->direita));
		}
		Viagem* pai = viagem->pai;
		while((pai!=NULL) && (viagem == pai->direita))
		{
			viagem = pai;
			pai = pai->pai;
		}
		return pai;
	}
	return NULL;
}
//############################################# IMPLEMENTAÇÂO #####################################################################################
Viagem* nova_v(int dia, int mes, int ano, char* cidade,	char* pais,	int	periodo)
{
	if ( dia<1 || dia>31 || mes<1 || mes>12 || strlen(cidade)>61 || strlen(cidade)==0 || strlen(pais)>31 || strlen(pais)==0 || periodo<1)
		return NULL;

	Viagem* nova = (Viagem*)malloc(tamanho_v());
	
	if (nova == NULL)
		return NULL;

	count_id++;
	nova->id = count_id;
	nova->dia = dia;
	nova->mes = mes;
	nova->ano = ano;
	strcpy(nova->cidade,cidade);
	strcpy(nova->pais,pais);
	nova->periodo = periodo;
	nova->direita = NULL;
	nova->esquerda = NULL;

	return nova;
}
//############################################################################################################################
void libera_v(Viagem* viagem)
{
	viagem->id = -1;
	viagem->dia = -1;
	viagem->mes = -1;
	viagem->ano = -1;
	strcpy(viagem->cidade,NULL);
	strcpy(viagem->pais,NULL);
	viagem->periodo = -1;
	viagem->direita = NULL;
	viagem->esquerda = NULL;
	free(viagem);
}
//############################################################################################################################
void acessa_v(Viagem* viagem, int* dia,	int* mes, int* ano,	char* cidade, char* pais, int* periodo)
{
	*dia = viagem->dia;
	*mes = viagem->mes;
	*ano = viagem->ano;
	strcpy(cidade,viagem->cidade);
	strcpy(pais,viagem->pais);
	*periodo = viagem->periodo;

}
//############################################################################################################################
void atribui_v(Viagem* viagem, int dia,	int	mes, int ano, char* cidade,	char* pais, int periodo)
{
	if(viagem!=NULL || dia<1 || dia>31 || mes<1 || mes>12 || strlen(cidade)>61 || strlen(cidade)==0 || strlen(pais)>31 || strlen(pais)==0 || periodo<1)
	{
		viagem->dia = dia;
		viagem->mes = mes;
		viagem->ano = ano;
		viagem->periodo = periodo;
	}
}
//############################################################################################################################
void atribui_direita_v(Viagem* viagem, Viagem* direita)
{
	if (viagem != NULL)
	{
		viagem->direita = direita;
	}
}
//############################################################################################################################
Viagem* acessa_direita_v(Viagem* viagem)
{
	if(viagem != NULL)
	{
		return viagem->direita;
	}
}
//############################################################################################################################
void atribui_esquerda_v(Viagem* viagem,	Viagem* esquerda)
{
	if (viagem != NULL)
	{
		viagem->esquerda = esquerda;
	}
}
//############################################################################################################################
Viagem *acessa_esquerda_v(Viagem* viagem)
{
	if(viagem != NULL)
	{
		return viagem->esquerda;
	}
}
//############################################################################################################################
int	tamanho_v()
{
	return sizeof(Viagem);
}
//############################################################################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
	printf("funfou\n");
	return 0;
}