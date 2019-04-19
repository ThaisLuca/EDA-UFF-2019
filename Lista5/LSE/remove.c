/*
Programa que remove todas as ocorrências de uma elemento em uma lista.
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

TLSE* rto(TLSE *l, int elem){
	if(!l) return NULL;
	TLSE *p = l, *q, *ant = NULL;
	while(p){
		if(p->info != elem){
			ant = p;
			p = p->prox;
		} else {
			if(!ant){
				q = p;
				l = p->prox;
				p = p->prox;
				free(q);
			} else {
				q = p;
				ant->prox = p->prox;
				p = p->prox;
				free(q);
			}
		}
	}
	return l;
}

int main(void){
	TLSE *l = inicializa();

	l = insereInicio(l, 3);
	l = insereInicio(l, 6);
	l = insereInicio(l, 4);
	l = insereInicio(l, 2);

	l = rto(l, 2);
	imprimeLista(l);

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