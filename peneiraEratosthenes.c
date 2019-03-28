/*
Implementa a Peneira de Eratosthenes até um valor n definido pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehPrimo(int numero);

int main(void) {
	int *numeros, n, i, j, proximoPrimo;
	scanf("%d", &n);
	if(n < 0) return 0;
	
	n = n - 1;
	numeros = (int*) calloc(n, sizeof(int));
	for(i = 0; i < n; i++){
		numeros[i] = i+2;
	}
	
	for(i = 0; i < n; i++){
		proximoPrimo = numeros[i];
		if(ehPrimo(proximoPrimo)){
			for(j = 0; j < n; j++){
				if(numeros[j] != proximoPrimo && (numeros[j] % proximoPrimo == 0)){
					numeros[j] = 0;
				}
			}
		}
	}
	
	for(i = 0; i < n; i++){
		if(numeros[i] != 0){
			printf("%d\n", numeros[i]);	
		}
	}
	return 0;
}

int ehPrimo(int numero){
	if(((numero % 2) == 0) && (numero != 2)) return 0;
	int div, raiz = (int) sqrt(numero);
	for(div=3; div <= raiz; div = div + 2){
		if((numero % div) == 0) return 0;
	}
	return 1;
}
