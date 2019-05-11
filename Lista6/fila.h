#ifndef FILA_H
#define FILA_H

#include "pilha.h"

typedef struct fila {
	TNO *ini, *fim;
} TFila;


//Cria uma fila
TFila* cria(void);

//Verifica se a fila está vazia
int vazia(TFila *f);

//Libera a pilha
void libera(TFila *f);

//Insere um elemento na fila
void insere(TFila *f, int x);

//Retira um elemento da fila
int retira(TFila *f);

//Imprime os elementos da fila
void imprimeFila(TFila *f);

#endif