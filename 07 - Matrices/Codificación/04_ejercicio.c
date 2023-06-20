/*Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por
columna de dicha matriz*/

#include <stdio.h>
#include <locale.h>
#define FILAS 2
#define COLUMNAS 3

void cargarMatriz(int [][COLUMNAS],int,int);
void sumarPorColumnas(int [][COLUMNAS],int [],int, int);
void mostrarVector(int [],int);

int main(){
	int matriz[FILAS][COLUMNAS];
	int vectorSuma[COLUMNAS] = {0};
	
	setlocale(LC_ALL, "spanish");
	
	cargarMatriz(matriz,FILAS,COLUMNAS);
	sumarPorColumnas(matriz,vectorSuma,FILAS,COLUMNAS);
	mostrarVector(vectorSuma,COLUMNAS);
	
	return 0;
}

void cargarMatriz(int matriz[][COLUMNAS],int cf,int cc){
	int i,j;
	
	printf("Carga de la matriz\n\n");
	
	for(i = 0; i < cf;i++){
		for(j = 0; j < cc; j++){
			printf("Ingrese valor en la posición [%d][%d]: ", i, j);
			scanf("%d",&matriz[i][j]);
		}
	}
}

void sumarPorColumnas(int matriz[][COLUMNAS],int vector[],int cf, int cc){
	int columnas, filas;
	int posVector = 0;
	
	for(columnas = 0; columnas < cc;columnas++){
		for(filas = 0; filas < cf; filas++){
			vector[posVector]+=matriz[filas][columnas];
		}
		posVector++;
	}
}

void mostrarVector(int vector[],int fin){
	int i;
	
	printf("\nVector con la suma por fila de la matriz\n\n");
	
	for(i = 0; i< fin; i++){
		printf("%d\t",vector[i]);
	}
}
