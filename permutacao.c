/*
Recebe um número a e um b e respode se a é permutação de b.
*/

#include <stdio.h>
#include <string.h>

int main (void){
	char a[100], b[100];
	int i, seq = 0,
	contadorA[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	contadorB[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	scanf("%s", a);
	scanf("%s", b);

	i = 0;
	while(a[i] != '\0'){
		contadorA[(int) a[i]] += 1;
		printf("%d %d\n", a[i], contadorA[a[i]]);
		i++;
	}

	while(b[i] != '\0'){
		contadorB[(int) a[i]] += 1;
		i++;
	}

	for(i = 0; i < 10; i++){
		if((contadorA[i] == 0) && (contadorB[i] == 0)) continue;
		if(contadorA[i] == contadorB[i]) seq += 1;
	}

	printf("Oi\n");
	printf("%d\n", seq);
	if(seq == strlen(a)){
		printf("É permutação.\n");
	} else {
		printf("Não é permutação.\n");
	}

	return 0;
}