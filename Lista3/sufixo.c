/*
Programa que, dada uma cadeia de caracteres e um inteiro n, retira o
"sufixo" da cadeia de tamanho n."
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void retira_fim_n(char *str, int n);

int main(void){
	char *str;
	int n;

	scanf("%d", &n);
	str = (char*) malloc(sizeof(char)*n);
	if(!str) return 1;
	scanf("\n \n%s", str);
	if(n > strlen(str)){
		printf("Erro\n");
		return 0;
	}
	retira_fim_n(str, n);
	printf("%s\n", str);
	return 0;
}

void retira_fim_n(char *str, int n){
	char *novaString;
	int i;
	novaString = (char *) malloc(sizeof(char)*(strlen(str)-n));

	for(i = 0; i < (strlen(str) - n); i++){
		novaString[i] = str[i];
	}
	str = strcpy(str, novaString);
}
