#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

struct usuario
{
	int	 id;
	char nome[81];
	int qtd_amigo;
	int qtd_viagem;
	Usuario	**amigos;
	Viagem	*viagens;
};

int dias_do_inicio(Viagem* viagem);
int dias_do_fim(int inicio , Viagem* viagem);
Viagem* sucessor(Viagem* viagem);
Viagem* minimo(Viagem* viagem);
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
			user->qtd_viagem = 0;
		}
		return user;
	}
}

//############################################################################################################################
void libera_u(Usuario* usuario)
{
	// acessar a lista de amigos e excluir todos os amigos e ele das lista de amigos dos outros
	usuario->id = -1;
	strcpy(usuario->nome,NULL);
	usuario->amigos = NULL;
	usuario->viagens = NULL;
	usuario->qtd_amigo = -1;
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
	if (usuario != NULL && viagem != NULL)
	{
		
		if (usuario->viagens == NULL)
		{
			usuario->viagens = viagem;
			usuario->qtd_viagem = usuario->qtd_viagem + 1;
		}
		else
		{
			int dia_do_inicio , dia_do_fim;
			dia_do_inicio = dias_do_inicio(viagem);
			dia_do_fim = dias_do_fim(dia_do_inicio,viagem);
			Viagem* pai = usuario->viagens;
			Viagem* avo = NULL;
			int decisao;
			do
			{
				decisao = 0;
				int inicio_pai = dias_do_inicio(pai);
				int fim_pai = dias_do_fim(inicio_pai, pai);
				if ( ( ( inicio_pai > dia_do_inicio ) && ( inicio_pai > dia_do_fim ) ) || ( fim_pai < dia_do_inicio ) )
				{
					avo = pai;
					if ( ( inicio_pai > dia_do_inicio ) && ( inicio_pai > dia_do_fim ) )
					{
						decisao = -1;
						pai = acessa_esquerda_v(pai);
					}
					else if ( fim_pai < dia_do_inicio ) 
					{
						decisao = 1;
						pai = acessa_direita_v(pai);
					}
				}
				else
				{
					pai = NULL;
				}

			}while(pai != NULL);

			if (decisao == -1)
			{
				atribui_esquerda_v(avo,viagem);
				usuario->qtd_viagem = usuario->qtd_viagem + 1;
			}
			else if (decisao == 1)
			{
				atribui_direita_v(avo,viagem);
				usuario->qtd_viagem = usuario->qtd_viagem + 1;
			}
		}
	}
}
//############################################################################################################################
Viagem* listar_viagens_u(Usuario* usuario)
{
	if (usuario!= NULL)
	{
		Viagem** lista = (Viagem**) malloc(tamanho_v() * usuario->qtd_viagem);
		lista[0]=minimo(usuario->viagens);
		for (int i = 1; i < usuario->qtd_viagem ; i++)
		{
			lista[i] = sucessor(lista[i-1]);
		}
		return *lista;
	}
	return NULL;
}
//############################################################################################################################
Viagem* buscar_viagem_por_data_u(Usuario* usuario, int dia, int mes, int ano)
{
	if (usuario != NULL && dia>0 && mes >0 && ano>0 && dia<31 && mes<13)
	{
		int dias = dia + (mes*30) + (ano*365);
		int dias_aux;
		Viagem* aux = usuario->viagens;
		while(aux!=NULL && dias != dias_do_inicio(aux))
		{
			if (dia > dias_do_inicio(aux))
			{
				aux = acessa_esquerda_v(aux);
			}
			else
			{
				aux = acessa_direita_v(aux);
			}
		}
		return aux;
	}
	else
	{
		return NULL;
	}
}
//############################################################################################################################
Viagem* buscar_viagem_por_destino_u(Usuario* usuario, char* cidade, char* pais)
{
	if (usuario!=NULL && cidade!=NULL && pais!=NULL)
	{
		if(usuario->viagens !=NULL)
		{
			Viagem* aux = minimo(usuario->viagens);
			int dia , mes , ano ,periodo;
			char cidade[61],pais[31];
			acessa_v(aux , &dia , &mes , &ano , cidade , pais , &periodo);
			while (!(strcmp(cidade,cidade)) && !(strcmp(pais,pais)) )
			{
				if (sucessor(aux)!= NULL)
				{
					aux = sucessor(aux);
				}
				else
				{
					return NULL;
				}
				acessa_v(aux , &dia , &mes , &ano , cidade , pais , &periodo);
			}
			return aux;
		}
	}
}
//############################################################################################################################
//############################################################################################################################
int	tamanho_u()
{
	return sizeof(Usuario);
}

