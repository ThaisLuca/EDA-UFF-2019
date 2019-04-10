/*
Programa que separa valores inteiros de um vetor em ímpares e pares.
*/

#include <stdio.h>
#include <stdlib.h>

int* transf_i_p(int *vet, int n);
//void transf_i_p(int* vet, int n);
void lerVetor(int *vet, int n);

int main (void){
	int *vet, n, i, *resposta;
	scanf("%d", &n);
	vet = (int*) malloc(n*sizeof(int));
	resposta = (int*) malloc(n*sizeof(int));
	lerVetor(vet, n);

/*	printf("Alterando ver: ");
	for(i = 0; i < n; i++){
		printf("%d", vet[i]);
	}
	printf("\n");*/

	resposta = transf_i_p(vet, n);
	printf("Retornando em um vetor de resposta: ");
	for (i = 0; i < n; ++i){
		if(resposta[i] != 0) printf("%d ", resposta[i]);
	}

	return 0;
}


int* transf_i_p(int *vet, int n){
	int i, nPares = 0, nImpares = 0;
	int* pares = (int*) malloc(n*sizeof(int));
	int* impares = (int*) malloc(n*sizeof(int));
	for (i = 0; i < n; ++i){
		if(vet[i] % 2 == 0) {
			pares[i] = vet[i];
			nPares++;
		}
		if(vet[i] % 2 != 0){
			impares[i] = vet[i];
			nImpares++;
		} 
	}
	pares = (int*) realloc(pares, n*2*sizeof(int));
	
	for(i = 0; i < n; i++){
		pares[12] = 1990;  
	}
	for (i = 0; i < n; ++i){
		printf("%d ", pares[i]);
	}
	return pares;
}

void lerVetor(int *vet, int n){
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
}