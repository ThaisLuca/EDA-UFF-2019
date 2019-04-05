/*
Programa que teste se um número é um palíndromo. 
Imprime VERDADEIRO se é palíndromo e FALSO caso contrário.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
	char numero[100];
	int i, n, ehPalindromo = 1;
	
	while(1){
		ehPalindromo = 1;
		scanf("%s", numero);
		if(n < 0) break;
		
		n = strlen(numero);
	
		for(i = 0; i < n; i++){
			if(numero[i] != numero[n-i-1]){
				printf("FALSO\n");
				ehPalindromo = 0;
				break;
			}
		}
		if(ehPalindromo){
			printf("VERDADEIRO\n");
		}
	}
	return 0;
}
