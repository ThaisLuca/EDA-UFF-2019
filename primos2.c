/*
Retorna os n primeiros números primos existentes depois de n.
Ex: Se n=2, a resposta será os primos 3 e 5.
*/

#include<stdio.h>
#include<math.h>

int ehPrimo(int numero);

int main (void){
	int n, i, primos;

	while(1){
		scanf("%d", &n);
		primos = 0;
		if(n <= 0) return 0;
		for(i = n+1; ; i++){
			if(ehPrimo(i)){
				printf("%d\n", i);
				primos++;
			}
			if(primos == n) break;
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