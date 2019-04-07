/*
Recebe um número a e um b e respode se a é permutação de b.
*/

#include <stdio.h>
#include <string.h>

int main (void){
	char a[100], b[100];
	int i, nA, nB, index,
	contador[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	scanf("\n \n%s", a);
	scanf("\n \n%s", b);

	nA = strlen(a);
	nB = strlen(b);

	if(nA != nB){
		printf("Não é permutação.\n");
		return 0;
	}


	i = 0;
	while(a[i] != '\0'){
		index = (int) a[i] % 9;
		contador[index] += 1;
		i++;
	}

	i = 0;
	while(b[i] != '\0'){
		index = (int) b[i] % 9;
		contador[index] -= 1;
		i++;
	}


	for(i = 0; i < 10; i++){
		if(contador[i] != 0) break;
	}

	if(i >= 10){
		printf("É permutação.\n");
	} else {
		printf("Não é permutação.\n");
	}

	return 0;
}