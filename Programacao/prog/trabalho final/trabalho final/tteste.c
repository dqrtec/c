#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

float nota;

// --------------------------------- TESTE USUARIO --------------------------------- //

float testeNovoComDadosValidos() {
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = novo_u(1, "Abraão");

	if (usuario != NULL){
		printf("[Passou 1.50] - Teste da função novo_u() com dados válidos!\n");
		pontuacao = 1.5;
	} else {
		printf("[Falhou 0.00] - Teste da função novo_u() com dados válidos!\n");
	}
	return pontuacao;
}

float testeNovoComDadosInvalidos() {
	char nome[82] = "N";
	float pontuacao = 0;

	for (int i = 0; i < 82; i++) {
		strcat(nome, "N");
	}


	Usuario *usuario = novo_u(-1, nome);
	if (usuario == NULL){
		printf("[Passou 1.00] - Teste da função novo_u() com dados inválidos!\n");
		pontuacao = 1;
	} else{
		printf("[Falhou 0.00] - Teste da função novo_u() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeNovoComDadosNulos() {
	float pontuacao = 0;

	Usuario *usuario = novo_u(-1, NULL);
	if (usuario == NULL){
		printf("[Passou 0.67] - Teste da função novo_u() com dados nulos!\n");
		pontuacao = 0.67;
	} else{
		printf("[Falhou 0.00] - Teste da função novo_u() com dados nulos!\n");
	}
	return pontuacao;
}

float testeAcessa() {
	int id_u;
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = novo_u(1, "Abraão");
	if (usuario != NULL){
		acessa_u(usuario, &id_u, nome);
		if(id_u == 1 && strcmp(nome,"Abraão") == 0) {
			printf("[Passou 1.50] - Teste da função acessa_u() com dados válidos!\n");
			pontuacao = 1.5;
		} else {
			printf("[Falhou 0.00] - Teste da função acessa_u()com dados válidos!\n");
		} 
	} else {
		printf("[Falhou 0.00] - Teste da função acessa_u() com dados válidos!\n");
	}
	return pontuacao;	
}

float testeAtribuiComDadosValidos() {
	int id_u;
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = novo_u(1, "Abraão");
	if (usuario != NULL){
		atribui_u(usuario, 2, "Jacó");
		acessa_u(usuario, &id_u, nome); 
		if(id_u == 2 && strcmp(nome,"Jacó") == 0) {
			printf("[Passou 1.50] - Teste da função atribui_u() com dados válidos!\n");
			pontuacao = 1.5;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados válidos!\n");	
		}
	} else {
		printf("[Falhou 0.00] - Teste da função atribui_u() com dados válidos!\n");
	}
	return pontuacao;
}

float testeAtribuiComDadosInvalidos() {
	int id_u;
	char nome[82] = "N";
	float pontuacao = 0;

	for (int i = 0; i < 82; i++) {
		strcat(nome, "N");
	}

	Usuario *usuario = novo_u(1, "Abraão");
	if (usuario != NULL){
		atribui_u(usuario, 2, nome);
		acessa_u(usuario, &id_u, nome); 
		if(id_u == 1 && strcmp(nome,"Abraão") == 0) {
			printf("[Passou 1.00] - Teste da função atribui_u() com dados inválidos!\n");
			pontuacao = 1;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados inválidos!\n");
		}	
	} else{
		printf("[Falhou 0.00] - Teste da função atribui_u() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeAtribuiComDadosNulos() {
	int id_u;
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = novo_u(1, "Abraão");
	if (usuario != NULL){
		atribui_u(usuario, 2, NULL);
		acessa_u(usuario, &id_u, nome); 
		if(id_u == 1 && strcmp(nome,"Abraão") == 0) {
			printf("[Passou 0.67] - Teste da função atribui_u() com dados nulos!\n");
			pontuacao = 0.67;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_u() com dados nulos!\n");	
		}
	} else {
		printf("[Falhou 0.00] - Teste da função atribui_u() com dados nulos!\n");
	}
	return pontuacao;
}

float testeLiberaComDadosValidos() {
	int id_u;
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = novo_u(1, "Abraão");
	libera_u(usuario);
	if (usuario != NULL) {
		acessa_u(usuario, &id_u, nome); 
		if(id_u == 1 || strcmp(nome,"Abraão") == 0) {
			printf("[Falhou 0.00] - Teste da função libera_u() com dados válidos!\n");
		} else {
			printf("[Passou 1.50] - Teste da função libera_u() com dados válidos!\n");	
			pontuacao = 1.5;
		}
	} else {
		printf("[Passou 1.50] - Teste da função libera_u() com dados válidos!\n");
		pontuacao = 1.5;
	}
	return pontuacao;
}

float testeLiberaComDadosNulos() {
	int id_u;
	char nome[81];
	float pontuacao = 0;

	Usuario *usuario = NULL;
	libera_u(usuario);
	if (usuario == NULL) {
		printf("[Passou 0.67] - Teste da função libera_u() com dados nulos!\n");	
		pontuacao = 0.67;
	} else {
		printf("[Falhou 0.00] - Teste da função libera_u() com dados nulos!\n");
	}
	return pontuacao;
}

/* CRIAR TESTE DAS PROXIMAS FUNÇOES DE USUARIO APOS A IMPLEMENTACAO DAS FUNCOES
float testeAdicionaAmigoComDadosValidos(){
	int id_u;
	char nome[81];
	float pontuacao = 0;
	Usuario *usuario = novo_u(1, "Abraão");
	Usuario *amigo = novo_u(2, "Amanda");
	if(usuario != NULL || amigo != NULL){
		adiciona_amigo_u(usuario, amigo);
		if(usuario)
	}
}
*/


// --------------------------------- TESTE VIAGEM --------------------------------- //

/*
float testeNovaComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(1);
	if(fila != NULL) {
		printf("[Passou 1.00] - Teste da função nova_f() com dados válidos!\n");
		pontuacao = 1;
	} else {
		printf("[Falhou 0.00] - Teste da função nova_f() com dados válidos!\n");
	}
	return pontuacao;
}
float testeNovaComDadosInvalidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(-1);
	if(fila == NULL) {
		printf("[Passou 0.67] - Teste da função nova_f() com dados inválidos!\n");
		pontuacao = 0.67;
	} else {
		printf("[Falhou 0.00] - Teste da função nova_f() com dados inválidos!\n");
	}
	return pontuacao;
}
float testeDestroiComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	destroi_f(fila);
	if(fila != NULL) {
		printf("[Falhou 0.00] - Teste da função destroi_f() com dados válidos!\n");
	} else {
		printf("[Passou 1.00] - Teste da função destroi_f() com dados válidos!\n");
		pontuacao = 1;
	}
	return pontuacao;
}
float testeDestroiComDadosNulos() {
	float pontuacao = 0;
	Fila *fila = NULL;
	destroi_f(fila);
	if(fila == NULL) {
		printf("[Passou 0.50] - Teste da função destroi_f() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função destroi_f() com dados nulos!\n");
	}
	return pontuacao;
}
float testeCheia() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL && !cheia_f(fila)) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		usuario *jaco = novo_u(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		if (!cheia_f(fila)) {
			usuario *jose = novo_u(3, "Jose", "Computação");
			adiciona_f(fila, jose);
			if(cheia_f(fila)) {
				printf("[Passou 1.00] - Teste da função cheia_f() com dados válidos!\n");
				pontuacao = 1;
			}
		} else {
			printf("[Falhou 0.00] - Teste da função cheia_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função cheia_f() com dados válidos!\n");
	}
	return pontuacao;
}
float testeAdicionaComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		if(adiciona_f(fila, abraao)) {
			usuario *jaco = novo_u(2, "Jaco", "Computação");
			if(adiciona_f(fila, jaco)) {
				usuario *jose = novo_u(3, "Jose", "Computação");
				if(adiciona_f(fila, jose)) {
					printf("[Passou 1.00] - Teste da função adiciona_f() com dados válidos!\n");
					pontuacao = 1;
				} else {
					printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
				}	
			} else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
			}		
		} else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
	}
	return pontuacao;
}
float testeAdicionaComDadosInvalidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	if(fila != NULL) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		if(adiciona_f(fila, abraao)) {
			usuario *jaco = novo_u(2, "Jaco", "Computação");
			if(adiciona_f(fila, jaco)) {
				usuario *jose = novo_u(3, "Jose", "Computação");
				if(!adiciona_f(fila, jose)) {
					printf("[Passou 0.67] - Teste da função adiciona_f() com dados inválidos!\n");
					pontuacao = 0.67;
				} else {
					printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
				}	
			} else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
			}		
		} else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
	}
	return pontuacao;
}
float testeAdicionaComDadosNulos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	if(!adiciona_f(fila, NULL)) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		if(!adiciona_f(NULL, abraao)) {
			if(!adiciona_f(NULL, NULL)) {
				printf("[Passou 0.50] - Teste da função adiciona_f() com dados nulos!\n");
				pontuacao = 0.50;
			}else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
			}
		}else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
	}
	return pontuacao;
}
float testeRetiraComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		usuario *jaco = novo_u(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		usuario *jose = novo_u(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		if(retira_f(fila)){
			if(retira_f(fila)){
				if (retira_f(fila)) {
					if(!retira_f(fila)) {
						printf("[Passou 1.00] - Teste da função retira_f() com dados válidos!\n");
						pontuacao = 1;
					} else {
						printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
					}
				} else {
					printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
				}
			} else {
				printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
			}
		} else {
			printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
	}
	return pontuacao;
}
float testeRetiraComDadosNulos() {
	float pontuacao = 0;
	if(!retira_f(NULL)){
		printf("[Passou 0.50] - Teste da função retira_f() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função retira_f() com dados nulos!\n");
	}
	return pontuacao;
}
float testeBuscaComDadosValidos() {
	float pontuacao = 0;
	int id_u;
	char nome[50];
	char curso[30];
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		usuario *jaco = novo_u(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		usuario *jose = novo_u(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		usuario *aux = busca_f(fila, 2);
		if(aux != NULL){
			acessa_u(aux, &id_u, nome, curso);
			if(id_u == 2 && strcmp(nome,"Jaco") == 0 && strcmp(curso,"Computação") == 0) {
				printf("[Passou 1.00] - Teste da função busca_f() com dados válidos!\n");
				pontuacao = 1;				
			} else {
				printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
			}
		} else {
			printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
	}
	return pontuacao;
}
float testeBuscaComDadosInvalidos() {
	float pontuacao = 0;
	int id_u;
	char nome[50];
	char curso[30];
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		usuario *abraao = novo_u(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		usuario *jaco = novo_u(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		usuario *jose = novo_u(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		usuario *aux = busca_f(fila, 5);
		if(aux == NULL){
			printf("[Passou 0.67] - Teste da função busca_f() com dados inválidos!\n");
			pontuacao = 0.67;				
		} else {
			printf("[Falhou 0.00] - Teste da função busca_f() com dados inválidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função busca_f() com dados inválidos!\n");
	}
	return pontuacao;
}
float testeBuscaComDadosNulos() {
	float pontuacao = 0;
	int id_u;
	char nome[50];
	char curso[30];
	usuario *aux = busca_f(NULL, 1);
	if(aux == NULL){
		printf("[Passou 0.50] - Teste da função busca() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função busca() com dados nulos!\n");
	}
	return pontuacao;
}*/

float bateriaTestes01() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD usuario: Bateria de Testes 01 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = testeNovoComDadosValidos() + testeAtribuiComDadosValidos() + testeAcessa() + testeLiberaComDadosValidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes02() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD usuario: Bateria de Testes 02 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = testeNovoComDadosInvalidos() + testeAtribuiComDadosInvalidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes03() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD usuario: Bateria de Testes 03 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = testeNovoComDadosNulos() + testeAtribuiComDadosNulos() + testeLiberaComDadosNulos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}
/*
float bateriaTestes04() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 04 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeNovaComDadosValidos() + testeAdicionaComDadosValidos();
	pontuacao += testeDestroiComDadosValidos() + testeRetiraComDadosValidos();
	pontuacao += testeBuscaComDadosValidos() + testeCheia();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}
float bateriaTestes05() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 05 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeNovaComDadosInvalidos() + testeAdicionaComDadosInvalidos();
	pontuacao += testeBuscaComDadosInvalidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}
float bateriaTestes06() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 06 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeAdicionaComDadosNulos() + testeDestroiComDadosNulos();
	pontuacao += testeRetiraComDadosNulos() + testeBuscaComDadosNulos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}
*/
int main(void) {
	float pontuacaoTADusuario = bateriaTestes01();
	pontuacaoTADusuario += bateriaTestes02();
	pontuacaoTADusuario += bateriaTestes03();
	
	/*float pontuacaoTADFila = bateriaTestes04();
	pontuacaoTADFila += bateriaTestes05();
	pontuacaoTADFila += bateriaTestes06();
	printf("Nota Lista: %f\n", 0.3*pontuacaoTADusuario + 0.7*pontuacaoTADFila);
	*/
	printf("Nota Lista: %f\n", pontuacaoTADusuario);
	return 0;
}