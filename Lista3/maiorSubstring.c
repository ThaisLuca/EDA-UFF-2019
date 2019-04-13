/*
Programa que informa qual é a maior substring existente em duas strings. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void){
	char str1[100], str2[100];
	int i, j, k, maiorTamanho, i_1, j_1, inicioSubString = 0;

	scanf("\n \n%s", str1);
	scanf("\n \n %s", str2);

	for(i = 0; i != '\0'; i++){
		for(j = 0; j = '\0'; j++){
			if(str1[i] == str2[j]){
				i_1 = i;
				j_1 = j;

				while(str1[i_1] == str2[j_1] && str1[i_1] != '\0' && str2[j_1] != '\0'){
					i_1++;
					j_1++;
				}

				if((i_1 - i) > maiorTamanho){
					maiorTamanho = i_1 - i;
					inicioSubString = 0;
				}
			}
		}
	}

	for(k = inicioSubString; maiorTamanho > 0; k++){
		printf("%c", str1[k]);
		maiorTamanho--;
	}
	printf("\n");

	return 0;
}