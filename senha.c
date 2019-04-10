/*
Programa que verifica se uma string é uma "boa" senha.
Critérios para uma boa senha:
(a) deve possuir, no mínimo, 8 caracteres;
(b) deve possuir, no mínimo, um caracter entre '0' e '9';
(c) deve possuir, no mínimo, uma letra maiúscula;
(d) deve possuir, no mínimo, uma letra minúscula;
(e) deve possuir, no mínimo, um caracter do conjunto formato pelos demais caracteres do teclado
*/

#include <stdio.h>
#include <string.h>

//Constantes
int MINIMO = 8;
int A = 65;
int Z = 90;
int a = 97;
int z = 122;
int UM = 48;
int NOVE = 57;

int boaSenha(char *str);

int main (void){
	char str[100];

	scanf("\n \n%s", str);
	if(boaSenha(str)){
		printf("Senha Forte\n");
	} else {
		printf("Senha Fraca\n");
	}

	return 0;
}

int boaSenha(char *str){
	int i = 0, maiuscula = 0, minuscula = 0, caracter = 0, teclado = 0;
	if(strlen(str) < MINIMO){
		return 0;
	}
	for(i = 0; str[i] != '\0'; i++){
		if(A <= str[i] && str[i] <= Z){
			maiuscula = 1;
			continue;
		}
		if(a <= str[i] && str[i] <= z){
			minuscula = 1;
			continue;
		}
		if(UM <= str[i] && str[i] <= NOVE){
			caracter = 1;
			continue;
		}
		teclado = 1;
		
	}

	if(!maiuscula || !minuscula || !caracter || !teclado) return 0;
	
	return 1;
}