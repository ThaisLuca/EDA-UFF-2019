/*
Determine o comprimeiro máximo de um segmento crescente de n números.
Ex.: 5 10 3 2 4 7 9 8 5, o comprimento do segmento crescente máximo é 4.
*/
#include<stdio.h>

int main (void){

	int n, i, tam = 0, ultimo, proximo, maximo = 1;

	while(1){
		scanf("%d", &n);	//Tamanho da sequência
		if(n <= 0) break;
		scanf("%d", &ultimo);
		tam++;
		for(i = 1; i < n; i++){
			scanf("%d", &proximo);		
			if(proximo > ultimo){
				tam++;
				ultimo = proximo;
			} else {
				if(tam > maximo){
					maximo = tam;
				}
				tam = 1; 
				ultimo = proximo;
			}
		}
		printf("Tamanho: %d\n", maximo);
		tam = 0;
		maximo = 1;
	}
	return 0;
}