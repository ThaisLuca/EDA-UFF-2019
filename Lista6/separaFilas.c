/*
Programa que separa uma fila f em duas filas de pares e ímpares. Ao final da execução, f deve permanecer intacta.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void separa_filas(TFila *f, TFila *par, TFila *impar){
	TFila *aux = criaFila();

	while(!filaVazia(f)){
		int elemento = retira(f);
		insere(aux, elemento);
		if(elemento % 2 == 0) insere(par, elemento);
		if(elemento % 2 != 0) insere(impar, elemento);
	}

	while(!filaVazia(aux)) insere(f, retira(aux));

	free(aux);
}

int main(void){
	TFila *f = criaFila();
	TFila *par = criaFila();
	TFila *impar = criaFila();

	insere(f, 1);
	insere(f, 2);
	insere(f, 3);
	insere(f, 4);

	separa_filas(f, par, impar);

	printf("Imprimindo lista de pares \n");
	imprimeFila(par);

	printf("Imprimindo lista de ímpares \n");
	imprimeFila(impar);

	printf("Mostrando fila f intacta \n");
	imprimeFila(f);

	return 0;
}