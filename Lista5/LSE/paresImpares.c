/*

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

TLSE* i_p(TLSE *l){
	if(!l) return NULL;
	TLSE *resp, *p = l;
	resp = inicializa();

	//Primeiro os ímpares
	while(p){
		if(p->info % 2 == 0){
			p = p->prox;
			continue;
		}
		resp = insereFim(resp, p->info);
		p = p->prox;
	}

	p = l;
	//Depois os pares
	while(p){
		if(p->info % 2 != 0) {
			p = p->prox;
			continue;
		}
		resp = insereFim(resp, p->info);
		p = p->prox;
	}

	free(p);
	return resp;
}

int main(void){
	TLSE *lista = inicializa();
	lista = insereFim(lista, 4);
	lista = insereFim(lista, 3);
	lista = insereFim(lista, 2);
	lista = insereFim(lista, 1);

	TLSE *resposta = i_p(lista);

	printf("Lista separada por ímpares e pares: \n");
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