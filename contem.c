/*
Programa que verifica se uma string contém a outra.
*/

#include <stdio.h>
#include <string.h>

int cic (char *str1, char *str2);
void converteString(char *str);

//Constantes
int A = 65;
int Z = 90;

int main (void){
	char str1[100], str2[100];

	scanf("%s", str1);
	scanf("\n \n%s", str2);

	converteString(str1);
	converteString(str2);

	if(cic(str1, str2)){
		printf("A string 1 contém a string 2.\n");
	} else {
		printf("A string 1 NÃO contém a string 2.\n");
	}

	return 0;
}


int cic(char *str1, char *str2){
	int i;
	for(i = 0; i != '\0'; i++){

	}
}

void converteString(char *str){
	int i;
	for(i = 0; i != '\0'; i++){
		//Converte maiúscula em minúsculas
		if(A <= str[i] && str[i] <= Z){
			str[i] += 32;
		}
	}
}