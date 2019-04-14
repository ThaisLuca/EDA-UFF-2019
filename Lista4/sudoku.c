/*
A partir de uma matriz quadrada de dimensão 9, verifica se a matriz é uma solução
válida para o Sudoku. Cada linha, cada coluna e cada contém os números de 1 a 9
somente uma vez.
*/

#include <stdio.h>

#define DIM 9

void lerMatriz(int matriz[DIM][DIM], FILE *arquivo);
void zerarContador(int contador[10]);

int main (void){

	int matriz[DIM][DIM], i, j, elemento;
	int contador[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	FILE *arquivo;

	arquivo = fopen("entradaSudoku.txt", "r");
	if(arquivo == NULL){
		printf("Erro ao ler arquivo de entrada.\n");
		return 1;
	}

	lerMatriz(matriz, arquivo);
	fclose(arquivo);

	//Verifica as linhas
	for(i = 0; i < DIM; i++){
		zerarContador(contador);
		for(j = 0; j < DIM; j++){
			elemento = matriz[i][j];
			if(contador[elemento] > 0){
				printf("Não é uma solução válida: elemento repetido em uma das linhas.\n");
				return 0;
			} else {
				contador[elemento] += 1;
			}
		}
	}

	//Verifica as colunas
	for(j = 0; j < DIM; j++){
		zerarContador(contador);
		for(i = 0; i < DIM; i++){
			elemento = matriz[i][j];
			if(contador[elemento] > 0){
				printf("Não é uma solução válida: elemento repetido em uma das colunas.\n");
				return 0;
			} else {
				contador[elemento] += 1;
			}
		}
	}

	//Verifica os blocos
	int bloco = 0;
	int limiteBloco = DIM/3;
	for(bloco = 0; bloco < DIM; bloco++){
		zerarContador(contador);
		for(i = bloco; i < i + limiteBloco; i++){
			for(j = bloco; j < j + limiteBloco; j++){
				elemento = matriz[i][j];
				if(contador[elemento] > 0){
					printf("Não é uma solução válida: elemento repetido em um dos blocos da matriz.\n");
					return 0;
				} else {
					contador[elemento] += 1;
				}
			}
		}
	}


	return 0;
}

void lerMatriz(int matriz[DIM][DIM], FILE *arquivo){
	int i, j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			fscanf(arquivo, "%d", &matriz[i][j]);
		}
	}
}

void zerarContador(int contador[10]){
	int i;
	for(i = 0; i < 10; i++){
		contador[i] = 0;
	}
}