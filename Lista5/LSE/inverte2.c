/*
Programa que inverte uma lista e retorna um ponteiro para uma nova lista encadeada.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

void imprimeLista(TLSE *l);
TLSE* inicializa(void);
TLSE* insereFim(TLSE *l, int x);
TLSE* insereInicio(TLSE *l, int x);

TLSE* inverte(TLSE *l){
	TLSE *p = l, *resp = inicializa();

	while(p){
		resp = insereInicio(resp, p->info);
		p = p->prox;
	}

	return resp;
}

int main(void){
	TLSE *lista = inicializa();
	lista = insereFim(lista, 4);
	lista = insereFim(lista, 3);
	lista = insereFim(lista, 2);
	lista = insereFim(lista, 1);

	TLSE *resposta = inverte(lista);
	
	printf("Lista separada invertida: \n");
	imprimeLista(resposta);
	printf("\n");

	printf("Mostrando lista original: \n");
	imprimeLista(lista);
	printf("\n");

	return 0;
}

//Insere um elemento no final de uma lista.
TLSE* insereFim(TLSE *l, int x){
	TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
	novo->info = x;
	if(!l) return novo;
	TLSE *p = l;
	while(p->prox) p = p->prox;
	p->prox = novo;
	return l;
}

//Inicializa uma lista vazia.
TLSE* inicializa(void){
	return NULL;
}

//Imprime a lista.
void imprimeLista(TLSE *l){
	if(!l) return;
	TLSE *p = l;
	while(p){
		printf("%d", p->info);
		p = p->prox;
	}
}

//Insere um elemento no início da lista.
TLSE* insereInicio(TLSE *l, int x){
	TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
	novo->info = x;
	novo->prox = l;
	return novo;
}