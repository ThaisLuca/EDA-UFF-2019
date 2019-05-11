/*
Programa que, a partir de uma fila, retorne todos os elementos da fila em uma pilha.
Na ordem em que foram inseridos. 
*/


#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main(void){
	TFila *f = criaFila();
	insere(f, 1);
	insere(f, 2);
	insere(f, 3);

	TPilha *aux = criaPilha();
	TPilha *resp = criaPilha();

	while(filaVazia(f)){
		push(aux, retira(f));
	}

	while(pilhaVazia(aux)){
		push(resp, pop(aux));
	}

	imprimePilha(resp);
}