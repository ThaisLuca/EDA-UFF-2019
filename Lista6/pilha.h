
#ifndef PILHA_H
#define PILHA_H


//Cria a pilha
TP* criaPilhaVetor();
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

#endif