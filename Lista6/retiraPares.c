/*
Programa que retira todos os elementos pares de uma pilha.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

void retira_pares(TP *p){
	TP *aux = criaPilha();

	while(!pilhaVazia(p)){
		int elemento = pop(p);
		if(elemento % 2 != 0) push(aux, elemento);
	}

	while(!pilhaVazia(aux)) push(p, pop(aux));

	free(aux);
}

int main(void){
	TP *p = criaPilha();

	push(p, 1);
	push(p, 2);
	push(p, 4);
	push(p, 5);

	retira_pares(p);
	imprimePilha(p);

	return 0;
}