/*
Programa que integra e deriva polinômios.
Exemplo: Entrada v = {12, 2, 3}. Saída D = {2,6} e I = {0, 12, 1, 1}
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int *v, *I, *D, g, i;

	while(1){
		scanf("%d", &g);
		if(g <= 0) break;

		v = (int *) malloc(sizeof(int) * (g+1));
		if(v == NULL) exit(1);
		I = (int *) malloc(sizeof(int) * (g+2));
		if(I == NULL) exit(1);
		D = (int *) malloc(sizeof(int) * (g+1));
		if(D == NULL) exit(1);

		for(i = 0; i < g+1; i++){
			scanf("%d", &v[i]);
		}

		for(i = g; i >= 0; i--){
			printf("%d %d\n", v[i], i);	
			D[i] = v[i] * i;
			I[i] = v[i] / (i+1);
		}

		printf("D = { ");
		for(i = 0; i <= g; i++){
			if(D[i] != 0) printf("%d ", D[i]);
		}
		printf("}\n");

		printf("I = { ");
		for(i = 0; i < g+1; i++){
			printf("%d ", I[i]);
		}
		printf("}\n");
	}

	return 0;
}