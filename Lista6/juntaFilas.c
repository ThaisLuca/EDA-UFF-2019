/*
Programa que junta duas filas e retorna uma fila contendo todos os elementos de f1 seguidos pelos elementos de f2 obedecento a ordem de entrada dos inteiros nas filas de entrada.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

TFila* junta_filas(TFila *f1, TFila *f2){
	TFila *aux1 = criaFila();
	TFila *aux2 = criaFila();

	TFila *resp = criaFila();

	while(!filaVazia(f1)) insere(aux1, retira(f1));
	while(!filaVazia(f2)) insere(aux2, retira(f2));

	while(!filaVazia(aux1)){
		int elemento = retira(aux1);
		insere(resp, elemento);
		insere(f1, elemento);
	}

	while(!filaVazia(aux2)){
		int elemento = retira(aux2);
		insere(resp, elemento);
		insere(f2, elemento);
	}

	free(aux1);
	free(aux2);

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