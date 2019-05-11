/*
Programa que junta duas filas e retorna uma fila contendo todos os elementos de f1 seguidos pelos elementos de f2 obedecento a ordem de entrada dos inteiros nas filas de entrada.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

TFila* junta_filas(TFila *f1, TFila *f2){
	TP *p1 = criaPilha();
	TP *p2 = criaPilha();
	TP *p1aux = criaPilha();
	TP *p2aux = criaPilha();

	while(!filaVazia(f1)) push(p1, retira(f1));
	while(!pilhaVazia(p1)) push(p1aux, pop(p1));

	while(!filaVazia(f2)) push(p2, retira(f2));
	while(!pilhaVazia(p2)) push(p2aux, pop(p2));

	TFila *resp = criaFila();

	while(!pilhaVazia(p1aux)){
		int elemento = pop(p1aux);
		insere(resp, elemento);
		insere(f1, elemento);
	}

	while(!pilhaVazia(p2aux)){
		int elemento = pop(p2aux);
		insere(resp, elemento);
		insere(f2, elemento);
	}

	free(p1);
	free(p1aux);
	free(p2);
	free(p2aux);

	return resp;
}

int main(void){
	TFila *F1 = criaFila();
	TFila *F2 = criaFila();

	insere(F1, 1);
	insere(F1, 2);

	insere(F2, 3);
	insere(F2, 4);

	TFila *resposta = junta_filas(F1, F2);

	printf("Imprimindo resposta \n");
	imprimeFila(resposta);

	printf("Mostrando filas inalteradas: \n");

	printf("F1 \n");
	imprimeFila(F1);

	printf("F2 \n");
	imprimeFila(F2);

	return 0;
}