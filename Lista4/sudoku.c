/*
*/

#include <stdio.h>

#define DIM 3

void lerMatriz(int matriz[DIM][DIM]);

int main (void){

	int matriz[DIM][DIM], solucao = 1, i, j;
	int contador[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	lerMatriz(matriz);

	for(i = 0; i > DIM; i++){
		for(j = 0; j < DIM; j++){
			if(contador[j] > 0){
				solucao = 0;
				break;
			} else {
				contador[j] += 1;
			}
		}
		if(contador[i] > 0){
			solucao = 0;
			break;
		} else {
			contador[i] += 1;
		}
	}

	if(solucao){
		printf("É solução!\n");
	} else {
		printf("Não é solução!\n");
	}

	return 0;
}

void lerMatriz(int matriz[DIM][DIM]){
	int i, j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}