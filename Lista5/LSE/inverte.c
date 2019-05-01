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
TLSE* insereInicio(TLSE *l, int x);

void inverte(TLSE *l){
	if(!l) return;
	int total = 0, i, j, temp;
	TLSE *p = l, *q;
	while(p){
		total++;
		p = p->prox;
	}
	p = l;
	for(i = 0; i < (int) total/2; i++){
		j = i; q = p;
		while(j != total-i-1){
			q = q->prox;
			j++;
		}
		temp = q->info;
		q->info = p->info;
		p->info = temp;
		p = p->prox;
	}
}

int main(void){
	TLSE *lista = inicializa();
	lista = insereInicio(lista, 4);
	lista = insereInicio(lista, 3);
	lista = insereInicio(lista, 2);
	lista = insereInicio(lista, 1);

	printf("Lista Original: ");
	imprimeLista(lista);
	printf("\n");

	inverte(lista);

	printf("Lista Invertida: ");
	imprimeLista(lista);
	printf("\n");

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
		printf("%d", p->info);
		p = p->prox;
	}
}