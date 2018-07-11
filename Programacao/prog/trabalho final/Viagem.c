#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Viagem.h"
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
	Viagem* direita;
	Viagem* esquerda;
};

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
	strcpy(viagem->cidade,"");
	strcpy(viagem->pais,"");
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
int main()
{
	int	dia=10;
	int	mes=05;
	int	ano=2017;
	char cidade[31];
	strcpy(cidade,"daniel de ");
	char pais[60];
	strcpy(pais,"samuel de");
	int	periodo=15;

Viagem* daniel =  nova_v(dia,mes,ano,cidade, pais, periodo);
printf("%d",daniel->periodo);

	return 0;
}