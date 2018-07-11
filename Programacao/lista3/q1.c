#include <stdio.h>
#define N1 5
#define N2 8

int main(void){

	int vetor1[N1] = {1, 2, 3, 4, 16};
	int vetor2[N2] = {2, 4, 1, 8, 1, 12, 14, 16};

	for(int i = 0; i<N1; i++){
		for(int j = 0; j<N2; j++){
			if(vetor1[i] == vetor2[j])
				printf("%d\n", vetor1[i]);
		}
	}
	return 0;
}