/*
Programa que teste se um n�mero � um pal�ndromo. 
Imprime VERDADEIRO se � pal�ndromo e FALSO caso contr�rio.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
	char numero[100] = {'0', '0', '1', '0', '1', '\0'};
	int i, n;
	
	while(1){
		scanf("%s", numero);
		if(n < 0) break;
		
		n = strlen(numero);
	
		for(i = 0; i < n; i++){
			if(numero[i] != numero[n-i-1]){
				printf("FALSO");
				return 0;
			}
		}
		printf("VERDADEIRO");
	}
	return 0;
}
