/*
Função que substitui todas as suas letras por predecessoras do alfabeto.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void shift_troca_string(char *str);

//Constantes
int A = 65;
int Z = 90;
int a = 97;
int z = 122;

int main (void){
	char *str;
	str = (char *) malloc(100 * sizeof(char));
	if(!str) return 1;
	gets(str);
	shift_troca_string(str);
	printf("Resposta esperada: %s\n", "zLNQ");
	puts(str);

	return 0;

}

void shift_troca_string(char *str){
	int i = 0, offset;
	while(str[i] != '\0'){
		if(A <= str[i] && str[i] <= Z){
			offset = Z - str[i];
			if(offset > 25) offset--;
			str[i] = a + offset;
		} else if(a < str[i] && str[i] < z){
			offset = z - str[i];
			if(offset > 0) offset--;
			str[i] = A + offset;
		} else {
			str[i] = "!";
		}
		i++;
	}
}