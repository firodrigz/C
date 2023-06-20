/*Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la
constante.*/

#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3

void ingresarMatriz(int [][COLUMNAS]);
void multiplicarMatrizPorConstante(int [][COLUMNAS]);
void imprimirMatriz(int [][COLUMNAS]);

int main() {
    int matriz[FILAS][COLUMNAS];
        
    ingresarMatriz(matriz);
    multiplicarMatrizPorConstante(matriz);
    imprimirMatriz(matriz);
    
    return 0;
}

void ingresarMatriz(int matriz[][COLUMNAS]) {
    int i, j;
    
    printf("Ingrese los elementos de la matriz:\n");
    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void multiplicarMatrizPorConstante(int matriz[][COLUMNAS]) {
    int i, j;
    int constante;
    
    printf("Ingrese un número entero para multiplicar la matriz: ");
    scanf("%d", &constante);    
    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] *= constante;
        }
    }
}

void imprimirMatriz(int matriz[][COLUMNAS]) {
    int i, j;
    
    printf("La matriz resultante es:\n");
    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
