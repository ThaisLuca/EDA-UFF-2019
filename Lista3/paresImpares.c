/*
Programa que separa valores inteiros de um vetor em ímpares e pares.
*/

#include <stdio.h>
#include <stdlib.h>

int* transf_i_p(int *vet, int n);
void lerVetor(int *vet, int n);

int main (void){
	int *vet, n, i, *resposta;
	scanf("%d", &n);
	vet = (int*) malloc(n*sizeof(int));
	resposta = (int*) malloc(n*sizeof(int));
	lerVetor(vet, n);

	resposta = transf_i_p(vet, n);
	printf("Retornando em um vetor de resposta: ");
	for (i = 0; i < n; ++i){
		if(resposta[i] != 0) printf("%d ", resposta[i]);
	}
	printf("\n");

	free(vet);
	free(resposta);

	return 0;
}


int* transf_i_p(int *vet, int n){
	int i;
	int* pares = (int*) calloc(n, sizeof(int));
	int* impares = (int*) calloc(n, sizeof(int));
	int* resp = (int *) calloc(n, sizeof(int));
	for (i = 0; i < n; ++i){
		if(vet[i] % 2 == 0) {
			pares[i] = vet[i];
		}
		if(vet[i] % 2 != 0){
			impares[i] = vet[i];
		} 
	}
	int ultima = 0;
	for(i = 0; i < n; i++){
		if(pares[i] != 0){
			resp[ultima] = pares[i];
			ultima++;
		}
	}

	for(i = 0; i < n; i++){
		if(impares[i] != 0){
			resp[ultima] = impares[i];
			ultima++;
		}
	}

	free(pares);
	free(impares);

	return resp;
}

void lerVetor(int *vet, int n){
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
}