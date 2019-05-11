
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Cria a fila
TFila* criaFila(void){
	TFila *f = (TFila *) malloc(sizeof(TFila));
	f->ini = f->fim = NULL;
	return f;
}

int filaVazia(TFila *f){
	return f->ini == NULL;
}

//Insere um elemento na fila
void insere(TFila *f, int x){
	TNO *novo = (TNO *) malloc(sizeof(TNO));
	novo->info = x;
	novo->prox = NULL;
	if(vazia(f)){
		f->ini = f->fim = novo;
	} else {
		f->fim->prox = novo;
		f->fim = novo;
	}
}

//Retira um elemento da fila
int retira(TFila *f){
	if(filaVazia(f)) exit(1);
	int resp = f->ini->info;
	TNO *q = f->ini;
	f->ini = f->ini->prox;
	if(!f->ini) f->fim = NULL;
	free(q);
	return resp;
}

//Libera a fila
void liberaFila(TFila *f){
	TNO *q = f->ini, *t;
	while(q){
		t = q;
		q = q->prox;
		free(t);
	}
	free(f);
}