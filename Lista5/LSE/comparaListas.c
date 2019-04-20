/*
Programa que verifica se duas listas são iguais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
	int mat;
	char nome[81];
	float cr;
	struct lista *prox;
} TLista;

TLista* inicializa(void);
TLista* insereInicio(TLista *l, int mat, char* nome, float cr);
int compara(TLista *p, TLista *q);

int igual(TLista *l1, TLista *l2){
	if((!l1) && (!l2)) return 1;
	if((!l1) && l2) return 0;
	if(l1 && (!l2)) return 0;

	TLista *p = l1, *q = l2;
	while(p && q){
		if(!compara(p,q)) return 0;
		p = p->prox;
		q = q->prox;
	}
	if(!p && q) return 0;
	if(p && !q) return 0;

	return 1;
}

int main(void){
	TLista *l1 = inicializa();
	TLista *l2 = inicializa();

	l1 = insereInicio(l1, 1, "Thais", 7.0);
	l1 = insereInicio(l1, 2, "Thati", 8.5);

	l2 = insereInicio(l2, 1, "Thais", 7.0);
	l2 = insereInicio(l2, 2, "Thati", 8.5);

	if(igual(l1, l2)){
		printf("Listas iguais.\n");
	} else {
		printf("Listas diferentes.\n");
	}

	return 0;
}

//Inicializa uma lista vazia.
TLista* inicializa(void){
	return NULL;
}

//Insere um elemento no início da lista.
TLista* insereInicio(TLista *l, int mat, char* nome, float cr){
	TLista *novo = (TLista *) malloc(sizeof(TLista));
	novo->mat = mat;
	strcpy(novo->nome, nome);
	novo->cr = cr;
	novo->prox = l;
	return novo;
}

//Compara se duas estruturas são iguais.
int compara(TLista *p, TLista *q){
	return (p->mat == q->mat) && (p->cr == q->cr) && !(strcmp(p->nome, q->nome));
}