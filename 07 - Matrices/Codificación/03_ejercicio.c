/*Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 5
#define COLUMNAS 4

void cargarMatriz(int [][COLUMNAS],int,int);
void sumarPorFilas(int [][COLUMNAS],int [],int, int);
void mostrarVector(int [],int);

int main(){
	int matriz[FILAS][COLUMNAS];
	int vectorSuma[FILAS] = {0};
	
	setlocale(LC_ALL, "spanish");
	
	cargarMatriz(matriz,FILAS,COLUMNAS);
	sumarPorFilas(matriz,vectorSuma,FILAS,COLUMNAS);
	mostrarVector(vectorSuma,FILAS);
	
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

void sumarPorFilas(int matriz[][COLUMNAS],int vector[],int cf, int cc){
	int i, j;
	int posVector = 0;
	
	for(i = 0; i < cf;i++){
		for(j = 0; j < cc; j++){
			vector[posVector]+=matriz[i][j];
		}
		posVector++;
	}
}

void mostrarVector(int vector[],int fin){
	int i;
	
	printf("\nVector con la suma por fila de la matriz\n\n");
	
	for(i = 0; i< fin; i++){
		printf("%d\n",vector[i]);
	}
}

