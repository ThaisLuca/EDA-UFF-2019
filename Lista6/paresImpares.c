/*
Programa que dada uma fila f, retorna uma nova fila contendo os elementos pares de f e modifica a fila original para que contenha somente os ímpares, respeitando a ordem em f. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

TFila* sep_fila(TFila *f){
	TFila *pares = criaFila();
	TFila *aux = criaFila();

	while(!filaVazia(f)){
		int elemeto = retira(f);
		if(elemeto % 2 == 0) insere(pares, elemeto);
		if(elemeto % 2!= 0) insere(aux, elemeto);
	}

	while(!filaVazia(aux)) insere(f, retira(aux));

	free(aux);

	return pares;
}

int main(void){
	TFila *f = criaFila();
	insere(f, 3);
	insere(f, 2);
	insere(f, 4);
	insere(f, 1);

	TFila *resposta = sep_fila(f);

	printf("Imprimindo pares:\n");
	imprimeFila(resposta);

	printf("Imprimindo ímpares: \n");
	imprimeFila(f);

	return 0;
}