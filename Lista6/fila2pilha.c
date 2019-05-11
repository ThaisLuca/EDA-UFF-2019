/*
Programa que, a partir de uma fila, retorne todos os elementos da fila em uma pilha.
Na ordem em que foram inseridos. 
*/


#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

TP* f2p(TFila *f) {
	TP *aux = criaPilha();
	TP *resp = criaPilha();

	while(!filaVazia(f)) push(aux, retira(f));
	
	while(!pilhaVazia(aux)) push(resp, pop(aux));

	free(aux);

	return resp;
}

int main(void){
	TFila *f = criaFila();
	insere(f, 1);
	insere(f, 2);
	insere(f, 3);

	TP *resposta = f2p(f);

	imprimePilha(resposta);

	return 0;
}

