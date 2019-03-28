/*
Retorna a representação binária de um número n dado na entrada.
*/

#include<stdio.h>
#include<math.h>

int binario(int numero);

int main (void){
	int numeroBinario = 0;
    int resto, i = 1, n;

    while(1){
    	scanf("%d", &n);
    	if(n < 0) break;
    	while (n!=0){
        	resto = n%2;
        	n /= 2;
        	numeroBinario += resto*i;
        	i *= 10;
    	}
    	printf("%d\n", numeroBinario);
    }

}