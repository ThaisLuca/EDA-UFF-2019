
#ifndef PILHA_H
#define PILHA_H

typedef struct pilhaVetor {
	int posicaoLivre;
	int *vet;
} TPV;

typedef struct no {
	int info;
	struct no *prox;
} TNO;

typedef struct pilhaLista {
	TNO *prim;
} TP;

//Cria a pilha
TPV* criaPilhaVetor();
TP* criaPilha();

//Verifica se está vazia
int pilhaVaziaVetor(TPV *p);
int pilhaVazia(TP *p);

//Insere um elemento na pilha
void pushPilhaVetor(TPV *p, int x);
void push(TP *p, int x);

//Retira um elemento da pilha
int popPilhaVetor(TPV *p);
int pop(TP *p);

//Libera a pilha
void liberaPilhaVetor(TPV *p);
void liberaPilha(TP *p);

//Imprime a pilha
void imprimePilha(TP *p);

#endif