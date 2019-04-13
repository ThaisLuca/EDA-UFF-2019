/*
Programa que realiza a multiplicação de duas matrizes.
*/

#include <stdio.h>
#include <stdlib.h>

int** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2);
void lerMatriz(int m, int n, int **mat, FILE *arquivo);
void imprimeMatriz(int m, int n, int **mat);

int main (void){
	int m1, n1, m2, n2, i;
	int **mat1, **mat2;
	FILE *arquivoMatriz1, *arquivoMatriz2;

	arquivoMatriz1 = fopen("matriz1.txt", "r");
	if(arquivoMatriz1 == NULL){
		printf("Arquivo não pode ser aberto.\n");
		return 1;
	}

	arquivoMatriz2 = fopen("matriz2.txt", "r");
	if(arquivoMatriz2 == NULL){
		printf("Arquivo não pode ser aberto.\n");
		return 1;
	}

	fscanf(arquivoMatriz1, "%d %d", &m1, &n1);
	fscanf(arquivoMatriz2, "%d %d", &m2, &n2);

	mat1 = (int **) malloc(sizeof(int *) * m1);
	mat2 = (int **) malloc(sizeof(int *) * m2);

	for(i = 0; i < m1; i++){
		mat1[i] = (int *) malloc(n1 * sizeof(int));
		mat2[i] = (int *) malloc(n2 * sizeof(int));
	}

	lerMatriz(m1, n1, mat1, arquivoMatriz1);
	lerMatriz(m2, n2, mat2, arquivoMatriz2);

	int **resposta = mult(m1, n1, mat1, m2, n2, mat2);
	imprimeMatriz(m1, n2, resposta);
}

int** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2){
	int **resp, i, j, k;
	if(n1 != m2){
		printf("Não é possível multiplicar as matrizes.\n");
		return 0;
	}
	resp = (int **) malloc(m1 * sizeof(int *));
	for(i = 0; i < m1; i++){
		resp[i] = (int *) malloc(n2 * sizeof(int));
	}

	for(i = 0; i < m1; i++){
		for(j = 0; j < n2; j++){
			resp[i][j] = 0;
			for(k = 0; k < n1; k++){
				resp[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	return resp;
}

void lerMatriz(int m, int n, int **mat, FILE *arquivo){
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			fscanf(arquivo, "%d", &mat[i][j]);	
		}
	}
}

void imprimeMatriz(int m, int n, int **mat){
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}