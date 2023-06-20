/*Ingresar una matriz de 2x3 por teclado. Calcular la matriz transpuesta.*/

#include <stdio.h>
#define FILAS 2
#define COLUMNAS 3

void cargaMatriz(int [][COLUMNAS],int,int);
void transpuesta(int [][COLUMNAS],int [][FILAS],int,int);
void mostrarMatriz(int [][FILAS],int,int);


int main(){
	int matriz[FILAS][COLUMNAS];
	int matrizTranspuesta[COLUMNAS][FILAS];
	
	cargaMatriz(matriz,FILAS,COLUMNAS);
	transpuesta(matriz, matrizTranspuesta,FILAS,COLUMNAS);
	mostrarMatriz(matrizTranspuesta,FILAS,COLUMNAS);
	
	return 0;
}


void cargaMatriz(int matriz[][COLUMNAS],int cf, int cc){
	int i,j;
	
	printf("Ingrese los elementos de la matriz:\n");
	
	for(i = 0; i < cf; i++){
		for(j = 0; j < cc; j++){
			printf("Ingrese el elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void transpuesta(int matriz[][COLUMNAS],int transpuesta[][FILAS],int cf, int cc){
	int i,j;
	
	for(i = 0; i < cf; i++){
		for(j = 0; j < cc; j++){
			transpuesta[j][i] = matriz[i][j];
		}
	}
}

void mostrarMatriz(int matriz[][FILAS], int cf, int cc){
	int i,j;
	
	printf("\nMuestra de la matriz transpuesta:\n");
	
	for(i = 0; i < cc; i++){
		for(j = 0; j < cf; j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}

/*
void mostrarMatriz(int matriz[][FILAS]){
	int i,j;
	
	printf("\nMuestra de la matriz transpuesta:\n");
	
	for(i = 0; i < COLUMNAS; i++){
		for(j = 0; j < FILAS; j++){
			printf("%d ",matriz[j][i]);
		}
		printf("\n");
	}
}*/


