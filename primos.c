/*
Implemente um programa que receba como parâmetro de entrada n e
retorne todos os n primeiros números primeos existentes.
*/

#include<stdio.h>
#include<math.h>

int ehPrimo(int numero);

int main (void){
	int n, i;

	while(1){
		scanf("%d", &n);
		if(n <= 0) break;
		for(i = 1; i < n+1; i++){
			if(ehPrimo(i)){
				printf("%d\n", i);
				if(i == n) break;
			}
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