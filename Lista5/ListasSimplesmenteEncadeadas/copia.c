/*
Dada a struct que representa um aluno em uma universidade hipotética, escreva uma função que copie uma lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	int mat;
	float cr;
	struct aluno *prox;
} TAluno;

TAluno* inicializa(void);
TAluno* insereFim(TAluno *l, int mat, float cr);
void imprimeLista(TAluno *l);


//Copia uma lista para outra lista e retorna esta lista.
TAluno* copia(TAluno *l){
	TAluno *p = l, *resp;
	resp = inicializa();
	while(p){
		resp = insereFim(resp, p->mat, p->cr);
		p = p->prox;
	}
	return resp;
}

int main(void){
	TAluno *copiaLista;
	TAluno *lista = inicializa();
	lista = insereFim(lista, 1, 7.0);
	lista = insereFim(lista, 2, 8.0);
	lista = insereFim(lista, 3, 7.5);
	lista = insereFim(lista, 4, 8.9);

	copiaLista = copia(lista);
	imprimeLista(copiaLista);

	return 0;

}

//Inicializa uma lista vazia.
TAluno* inicializa(void){
	return NULL;
}

//Insere um elemento no final de uma lista.
TAluno* insereFim(TAluno *l, int mat, float cr){
	TAluno *novo = (TAluno *) malloc(sizeof(TAluno));
	novo->mat = mat;
	novo->cr = cr;
	if(!l) return novo;
	TAluno *p = l;
	while(p->prox) p = p->prox;
	p->prox = novo;
	return l;
}

//Imprime a lista.
void imprimeLista(TAluno *l){
	if(!l) return;
	TAluno *p = l;
	while(p){
		printf("Matrícula: %d CR: %f\n", p->mat, p->cr);
		p = p->prox;
	}
}