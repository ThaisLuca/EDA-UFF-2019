/*
Programa que converte uma pilha para um fila, obedecendo a ordem de entrada dos inteiros na pilha, ou seja,
o primeiro que sair da pilha deve ser o primeiro inteiro a sair da fila.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

TFila* p2f(TP *p){
	TFila *resp = criaFila();
	while(!pilhaVazia(p)) insere(resp, pop(p));

	return resp;
}

int main(void){
	TP *p = criaPilha();
	push(p, 1);
	push(p, 2);
	push(p, 3);

	TFila *resposta = p2f(p);

	imprimeFila(resposta);

	return 0;
}