/*
Dada uma fila f, retorne uma nova fila, com todos os elemento de f em ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"


TFila* inv_fila(TFila *f){
	TP *aux = criaPilha();
	while(!filaVazia(f)) push(aux, retira(f));

	while(!pilhaVazia(aux)) insere(f, pop(aux));

	free(aux);

	return f;

}

int main(void){
	TFila *f = criaFila();
	insere(f, 1);
	insere(f, 2);
	insere(f, 3);

	f = inv_fila(f);

	imprimeFila(f);

	return 0;
}