
/*
Programa que recebe uma string como parâmetro 
e retorna uma nova string com as vogais minúsculas substituídas
por "?"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * codifica(char *str);

int main (void) {
	char *str, *resposta;

	str = (char *) malloc(100 * sizeof(char));
	if(!str) return 1;
	gets(str);
	resposta = codifica(str);
	puts(resposta);

	return 0;

}

char * codifica(char *str){
	char *stringCodificada = (char *) malloc(strlen(str) * sizeof(char));
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
			stringCodificada[i] = "?";
		} else {
			stringCodificada[i] = str[i];
		}
		i++;
	}
	return stringCodificada;
}