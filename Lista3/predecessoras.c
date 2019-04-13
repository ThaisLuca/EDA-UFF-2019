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
	puts(str);

	return 0;

}

void shift_troca_string(char *str){
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == A){
			str[i] = z;
			continue;
		}
		if(str[i] == a){
			str[i] = Z;
			continue;
		}

		if(A+1 >= str[i] && str[i] <= Z){
			str[i] += 31;
		} else if(a+1 < str[i] && str[i] < z){
			str[i] -= 33;
		} else {
			str[i] = "!";
		}
		i++;
	}
}