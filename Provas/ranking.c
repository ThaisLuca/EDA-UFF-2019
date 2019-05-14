

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expressao {
	char descricao[81];
	struct expressao *prox, *ant; 
} Expressao;
 
void imprime(Expressao *lst);
Expressao* insereFim(Expressao *lst, char *nome);

Expressao* ranking(Expressao *p, char *exp){
	if(!p) insereFim(p, exp);
	Expressao *resp = p, *ant = NULL;
	char temp[81];

	while(resp){
		if(!strcmp(resp->descricao, exp)) break;
		resp = resp->prox;
	} 

	if(!resp){
		insereFim(p, exp);	
	} 
	else {
		strcpy(temp, resp->descricao);
		strcpy(resp->descricao, ant->descricao);
		strcpy(ant->descricao, temp);
	}

	return resp;
} 


int main(void){
	Expressao *l = NULL;

	l = insereFim(l, "Britney Spears");
	l = insereFim(l, "Harry Potter");
	l = insereFim(l, "Ed Sheeran");

	Expressao *resposta = ranking(l, "Harry Potter");

	imprime(resposta);

	return 0;
}

void imprime(Expressao *lst){
	while(lst){
		printf("%s\n", lst->descricao);
		lst = lst->prox;
	}
}

Expressao* insereFim(Expressao *lst, char *nome){
	Expressao *novo = (Expressao *) malloc(sizeof(Expressao));
	strcpy(novo->descricao, nome);
	novo->prox = NULL; 
	if(!lst){
		novo->ant = NULL;
		return novo;
	} else {
		Expressao *q = lst;
		while(q->prox) q=q->prox;
		q->prox = novo;
		novo->ant = q;
		
	}
	return lst;
}