/*
Programa que concatena duas listas, a partir da lista l1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

void imprimeLista(TLSE *l);
TLSE* inicializa(void);
TLSE* insereInicio(TLSE *l, int x);

//Concatena L2 com L1.
TLSE* junta_listas(TLSE *l1, TLSE *l2){
	TLSE *p = l1;

	//Encontra o final de l1.
	while(p->prox) p = p->prox;
	p->prox = l2;
	return l1;
}

int main(void){
	TLSE *l1 = inicializa();
	TLSE *l2 = inicializa();

	l1 = insereInicio(l1, 3);
	l1 = insereInicio(l1, 6);

	l2 = insereInicio(l2, 4);
	l2 = insereInicio(l2, 2);

	l1 = junta_listas(l1, l2);
	imprimeLista(l1);

	return 0;
}

//Inicializa uma lista vazia.
TLSE* inicializa(void){
	return NULL;
}

//Insere um elemento no início da lista.
TLSE* insereInicio(TLSE *l, int x){
	TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
	novo->info = x;
	novo->prox = l;
	return novo;
}

//Imprime a lista.
void imprimeLista(TLSE *l){
	if(!l) return;
	TLSE *p = l;
	while(p){
		printf("%d\n", p->info);
		p = p->prox;
	}
}