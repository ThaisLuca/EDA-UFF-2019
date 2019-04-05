/*
Recebe um número a e um b e respode se a é permutação de b.
*/

#include <stdio.h>
#include <string.h>

int main (void){
	char a[100], b[100];
	int i, seq = 0, n,
	contadorA[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	contadorB[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	scanf("%s", a);
	scanf("%s", b);

	n = strlen(a);
	for(i = 0; i < n; i++){
		contadorA[a[i]] += 1;
		printf("%s %d\n", a[i], contadorA[a[i]]);
	}

	n = strlen(b);
	for(i = 0; i < n; i++){
		contadorB[b[i]] += 1;
	}

	for(i = 0; i < 10; i++){
		if((contadorA[i] == 0) && (contadorB[i] == 0)) continue;
		if(contadorA[i] == contadorB[i]) seq += 1;
	}

	printf("%d\n", seq);
	if(seq == strlen(a)){
		printf("É permutação.\n");
	} else {
		printf("Não é permutação.\n");
	}

	return 0;
}