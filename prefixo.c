/*
Programa que, dada uma cadeia de caracteres e um inteiro n, retira o
"prefixo" da cadeia de tamanho n."
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void retira_inicio_n(char *str, int n);

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
	retira_inicio_n(str, n);
	puts(str);
}

void retira_inicio_n(char *str, int n){
	char *novaString;
	int i;
	for(i = n; i < strlen(str); i++){
		novaString[i] = str[i];
	}
	str = strcpy(str, novaString);
}