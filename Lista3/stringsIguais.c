/*
Programa que verifica se duas strings são iguais ignorando maiúsculas e minúsculas.
*/
#include <stdio.h>
#include <string.h>

int igual (char *str1, char *str2);
void converteString(char *str);

//Constantes
int A = 65;
int Z = 90;

int main (void) {
	char str1[100], str2[100];

	scanf("%s", str1);
	scanf("\n \n%s", str2);

	converteString(str1);
	converteString(str2);

	if(igual(str1, str2)){
		printf("Strings iguais.\n");
	} else {
		printf("Strings diferentes.\n");
	}

	return 0;
}

int igual (char *str1, char *str2){
	int i;
	if(strlen(str1) != strlen(str2)){
		return 0;
	}

	for(i = 0; i != '\0'; i++){
		if(str1[i] != str2[i]){
			return 0;
		}
	}
	return 1;
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