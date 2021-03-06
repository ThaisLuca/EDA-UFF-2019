
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int MAX_TAM = 100;


// Funções de Criação
TPV* criaPilhaVetor(){
	TPV *p = (TPV*) malloc(sizeof(TPV));
	p->vet = (int*) malloc(sizeof(int) * MAX_TAM);
	p->posicaoLivre = 0;
	return p;
}

TP* criaPilha(){
	TP *p = (TP *) malloc(sizeof(TP));
	p->prim = NULL;
	return p;
}


//Verifica se a pilha está vazia
int pilhaVaziaVetor(TPV *p){
	return p->posicaoLivre == 0;
}

int pilhaVazia(TP *p){
	return p->prim == NULL;
}

//Insere um elemento na pilha
void pushPilhaVetor(TPV *p, int x){
	if(p->posicaoLivre == MAX_TAM){
		MAX_TAM *= 2;
		p->vet = (int *) realloc(p->vet, MAX_TAM);
	}
	p->vet[p->posicaoLivre++] = x;
}

void push(TP *p, int x){
	TNO *no = (TNO *) malloc(sizeof(TNO));
	no->info = x;
	no->prox = p->prim;
	p->prim = no;
}

//Retira um elemento da pilha
int popPilhaVetor(TPV *p){
	if(pilhaVaziaVetor(p)) exit(1);
	int elemento = p->vet[--p->posicaoLivre];
	return elemento;
}


int pop(TP *p){
	if(pilhaVazia(p)) exit(1);
	int elemento = p->prim->info;
	TNO *q = p->prim;
	p->prim = q->prox;
	free(q);
	return elemento;
}

//Libera a pilha
void liberaPilhaVetor(TPV *p){
	free(p->vet);
	free(p);
}

void liberaPilha(TP *p){
	TNO *q = p->prim, *t;
	while(!pilhaVazia(p)){
		t = q;
		q = q->prox;
		free(t);
	}
	free(q);
}

//Funções de impressão
void imprimePilha(TP *p){
	while(!pilhaVazia(p)){
		printf("%d\n", pop(p));
	}
}