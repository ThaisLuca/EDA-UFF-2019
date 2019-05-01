/*
Programa que verifica se uma lista é o inverso da outra.
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
void imprimeLista(TLista *l);

int contrario(TLista *l1, TLista *l2){
	TLista *p = l1, *q = l2;
	int total = 0, i, j;
	while(p){
		total++;
		p=p->prox;
	}
	p = l1;
	for(i = 0; i < total; i++){
		j = 0, q = l2;
		while(j != i){
			q=q->prox;
			j++;
		}
		if(compara(p,q)) return 0;
		p=p->prox;
	}
	return 1;
}

int main(void){
	TLista *l1 = inicializa();
	TLista *l2 = inicializa();

	l1 = insereInicio(l1, 1, "Thais", 7.0);
	l1 = insereInicio(l1, 2, "Thati", 8.5);

	l2 = insereInicio(l2, 1, "Thati", 7.0);
	l2 = insereInicio(l2, 2, "Thais", 8.5);

	printf("Lista 1\n");
	imprimeLista(l1);
	printf("\n");

	printf("Lista 2\n");
	imprimeLista(l2);
	printf("\n");

	if(contrario(l1, l2)){
		printf("Lista 1 é o inverso da 2.\n");
	} else {
		printf("Lista 1 não é o inverso da 2.\n");
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

//Imprime a lista.
void imprimeLista(TLista *l){
	if(!l) return;
	TLista *p = l;
	while(p){
		printf("Matrícula: %d Nome: %s CR: %f\n", p->mat, p->nome, p->cr);
		p = p->prox;
	}
}