#include <stdio.h>
#include <string.h>

char maiusculo[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char minusculo[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int charMaiusculo(char c){
	int j;
	for(j=0; j<26; j++){
		if(c == maiusculo[j])
			return j;
	}
	return -1;
}

int charMinusculo(char c){
	int j;
	for(j=0; j<26; j++){
		if(c == minusculo[j])
			return j;
	}
	return -1;
}

void troca(char* string){
	int i, indice;
	for(i=0; i<sizeof(string); i++){
		indice = charMaiusculo(string[i]);
		if(indice >= 0)
			string[i] = minusculo[indice];
		else{
			indice = charMinusculo(string[i]);
			if(indice >= 0)
				string[i] = maiusculo[indice];
			
		}
	}
}

int ocorrencia(char* palavra, char carac){
	int i, numVezes = 0;
	for(i=0; i<sizeof(palavra); i++){
		if(palavra[i] == carac)
			numVezes++;
	}
	return numVezes;
}

void remover(char* palavra, char carac){
	int i, j;
	for(i=0; i<sizeof(palavra); i++){
		if(palavra[i] == carac){
			for(j=i; j<sizeof(palavra); j++){
				palavra[j] = palavra[j+1];
			}
		}
			
	}
}

void titulo(char* palavra){
	int i, indice;
	indice = charMinusculo(palavra[0]);
	if(indice >= 0)
		palavra[0] = maiusculo[indice];

	for(i=1; i<sizeof(palavra); i++){
		if(palavra[i] == ' '){
			indice = charMinusculo(palavra[i+1]);
			if(indice >= 0)
				palavra[i+1] = maiusculo[indice];
		}
	}
}

void inverte(char* palavra, int tamanho){
	int i;
	char aux;
	tamanho--;
	for(i=0; i<tamanho/2; i++){
		aux = palavra[i];
		palavra[i] = palavra[tamanho-i-1];
		palavra[tamanho-i-1] = aux;
	}
}


int main(void){
	int n = 100;
	char palavra[n];
	char carac;
	int numVezes;

	printf("Digite uma palavra "); 
	
	//scanf("%[A-Za-z ]s", palavra); getchar();
	fgets(palavra, n, stdin);

	// TROCA
	// troca(palavra); COMENTADO PARA NAO ATRAPALAHAR AS DEMAIS FUNCOES

	// OCORRENCIA
	// numVezes = ocorrencia(palavra, carac);

	// REMOVER
	// remover(palavra, carac);

	// TITULO
	// titulo(palavra);

	// INVERTE
	// inverte(palavra, strlen(palavra));
	
	printf("%s\n", palavra);

	return 0;
}