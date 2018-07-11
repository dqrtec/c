#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

struct usuario
{
	int	 id;
	char nome[81];
	int qtd_amigo;
	Usuario	**amigos;
	Viagem	*viagens;
};
//############################################################################################################################
Usuario* novo_u(int	id,	char* nome)
{
	if (id>0 && strlen(nome)>0)
	{
		Usuario* user = (Usuario*)malloc(tamanho_u());
		
		if (user==NULL)
		{
			return NULL;
		}
		else
		{
			user->id = id;
			strcpy(user->nome,nome);
			user->amigos = NULL;
			user->viagens = NULL;
			user->qtd_amigo = 0;
		}
		return user;
	}
}

//############################################################################################################################
void libera_u(Usuario* usuario)
{
	// acessar a lista de amigos e excluir todos os amigos e ele das lista de amigos dos outros
	usuario->id = -1;
	strcpy(usuario->nome,"");
	usuario->amigos = NULL;
	usuario->viagens = NULL;
	usuario->qtd_amigo = -1;
}
//############################################################################################################################
void acessa_u(Usuario* usuario,	int* id, char* nome)
{
	if (usuario !=NULL)
	{
		*id = usuario->id;
		strcpy( nome , usuario->nome);
	}
}
//############################################################################################################################
void atribui_u(Usuario* usuario, int id, char* nome)
{
	if (usuario !=NULL && id > 0 && strlen(nome)>0)
	{
		usuario->id = id;
		strcpy(usuario->nome, nome);
	}
}
//############################################################################################################################
void adiciona_amigo_u(Usuario* usuario,	Usuario* amigo)
{
	if (usuario!=NULL && amigo!=NULL && usuario!=amigo)
	{
		Usuario** amigos;
		if(usuario->amigos == NULL)
		{
			amigos = (Usuario**)malloc(tamanho_u());
		}
		else
		{
			amigos = (Usuario**)realloc(usuario->amigos ,tamanho_u());
		}
		usuario->qtd_amigo = usuario->qtd_amigo + 1;
		usuario->amigos = amigos;
		int aux = usuario->qtd_amigo;
		usuario->amigos[aux] = amigo;



		if(amigo->amigos == NULL)
		{
			amigos = (Usuario**)malloc(tamanho_u());
		}
		else
		{
			amigos = (Usuario**)realloc(amigo->amigos ,tamanho_u());
		}
		amigo->qtd_amigo = amigo->qtd_amigo + 1;
		amigo->amigos = amigos;
		aux = amigo->qtd_amigo;
		amigo->amigos[aux] = usuario;
	}
}
//############################################################################################################################
void remove_amigo_u(Usuario* usuario , int id)
{
	Usuario* amigo = busca_amigo_u(usuario,id);
	if (usuario != NULL && id>0 && amigo!=NULL)
	{
		int count = 0;
		int id_aux;
		char nome[81];
		int encontrado = 0;
		Usuario* aux;
		while(usuario->qtd_amigo > count)
		{
			acessa_u(usuario->amigos[count] , &id_aux , nome);
			if (id_aux == id)
			{
				encontrado = 1;
			}
			if (encontrado == 1)
			{
				if (usuario->qtd_amigo != count-1)
				{
					usuario->amigos[count] = usuario->amigos[count+1];
				}
			}
			count +=1;
		}
		if (encontrado ==1 )
		{
			encontrado = 0;
			usuario->qtd_amigo = usuario->qtd_amigo - 1;
			remove_amigo_u(amigo , usuario->id);
		}
	}
}
//############################################################################################################################
Usuario* busca_amigo_u(Usuario* usuario, int id)
{
	int count = 0;
	int id_aux;
	char nome[81];
	while(usuario->qtd_amigo > count)
	{
		acessa_u(usuario->amigos[count] , &id_aux , nome);
		if (id_aux == id)
		{
			return usuario->amigos[count];
		}
		count +=1;
	}
	return NULL;
}
//############################################################################################################################
void adiciona_viagem_u(Usuario* usuario,Viagem* viagem)
{
	if (usuario == NULL && viagem == NULL)
		{
			int mes, dia , ano,periodo ;
			char cidade[61] , pais[31];
			acessa_v(Viagem	*viagem, int* dia, int* mes, int* ano, char* cidade, char* pais, int* periodo);
			int dias_do_inicio =0 , dias_do_fim
			int validados =0;
			dias_do_inicio = dia + (mes*30) + (ano*365);
			if ()
			{
				/* code */
			}
		}	
}
//############################################################################################################################
//############################################################################################################################
//############################################################################################################################
//############################################################################################################################
//############################################################################################################################
int	tamanho_u()
{
	return sizeof(Usuario);
}