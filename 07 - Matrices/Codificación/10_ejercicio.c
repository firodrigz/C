/*Ingresar por teclado valores enteros y generar una matriz de 5x3 (5 filas y 3 por columnas). Informar:
a. La suma de los elementos de las columnas.
b. Las sumas de los elementos de las filas.
c. La suma total de los elementos.
d. El valor promedio de toda la matriz.
e. El valor promedio por columna.
f. El máximo valor de la matriz y en qué posición se encuentra (el máximo es único).
g. El mínimo valor de cada columna y en qué posición se encuentra (el mínimo es único).
Utilizar funciones para la carga y para resolver cada uno de los puntos.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 3
#define COLUMNAS 2


void cargaMatriz(int [][COLUMNAS],int,int);
void mostrarVector(int [], int);
void sumaPorColumna(int [][COLUMNAS],int [],int,int);
void sumaPorFila(int [][COLUMNAS],int [],int,int);
int sumaMatriz(int [],int);
float promedioMatriz(int,int);
void promedioPorColumna(int [],int [],int);
void valorMaximo(int[][COLUMNAS],int,int);
void valorMinimo(int[][COLUMNAS],int,int);

int main(){
	int matriz[FILAS][COLUMNAS];
	int sumaColumnas[COLUMNAS]={0};
	int sumaFilas[FILAS]={0};
	int promedioColumnas[COLUMNAS];
	int sumaTotal;
	float promedio;
	int minimoPorColumnas[COLUMNAS];
		
	setlocale(LC_ALL,"spanish");	
		
	cargaMatriz(matriz,FILAS,COLUMNAS);
	
	sumaPorColumna(matriz,sumaColumnas,FILAS,COLUMNAS);  //A
	printf("\nLa suma de los elementos de las columnas es: \n");
	mostrarVector(sumaColumnas,COLUMNAS);
	
	sumaPorFila(matriz,sumaFilas,FILAS,COLUMNAS);  //B
	printf("\n\nLa suma de los elementos de las filas es: \n");
	mostrarVector(sumaFilas,FILAS);
	
	sumaTotal=sumaMatriz(sumaFilas,FILAS);
	printf("\n\nLa suma de todos los elementos de la matriz es: %d \n",sumaTotal); //C
	
	promedio=promedioMatriz(sumaTotal,FILAS*COLUMNAS);
	printf("\n\nEl promedio de la matriz es: %.2f \n",promedio); //D
	
	promedioPorColumna(sumaColumnas,promedioColumnas,COLUMNAS);
	printf("\n\nEl promedio de las columnas es: \n");
	mostrarVector(promedioColumnas,COLUMNAS); //E
	
	valorMaximo(matriz,FILAS,COLUMNAS);
	
	valorMinimo(matriz,FILAS,COLUMNAS);
	
	return 0;
}

void cargaMatriz (int matriz[][COLUMNAS], int filas, int columnas){
	int i,j;
	
	printf("-- Carga matriz --\n");
	
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf("Ingrese valor en la posición [%d][%d] : ",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}	
}

void mostrarVector(int vector[],int tam){
	int i;
	
	for(i = 0;i < tam;i++){
		printf("|%d|",vector[i]);	
	}	
}

void sumaPorColumna(int matriz[][COLUMNAS], int vec[], int filas, int columnas){
	int f,c,i=0;
	
	for(c=0;c<columnas;c++){
		for(f=0;f<filas;f++){
			vec[i]+=matriz[f][c];
		}
		i++;
	}
}

void sumaPorFila(int matriz[][COLUMNAS], int vec[], int filas, int columnas){
	int f,c,i=0;
	
	for(f=0;f<filas;f++){
		for(c=0;c<columnas;c++){
			vec[i]+=matriz[f][c];
		}
		i++;
	}
}

int sumaMatriz(int vector[],int tam){
	int i;
	int suma=0;
	
	for(i = 0;i < tam;i++){
		suma+=vector[i];
	}
	
	return suma;
}

float promedioMatriz(int sumaElementos,int cantElementos){
	float promedio;
	
	promedio=(float)sumaElementos/cantElementos;	
	
	return promedio;
}

void promedioPorColumna(int sumaColumnas[],int promedioColumnas[], int columnas){
	int i;
	
	for(i=0;i<columnas;i++){
		promedioColumnas[i] = sumaColumnas[i]/columnas;
	}
}

void valorMaximo(int matriz[][COLUMNAS],int filas,int columnas){
	int i,j,maximo,band=0,ejex,ejey; 
	
	for(i=0;i<filas;i++){		
		for(j=0;j<columnas;j++){			
			if(band==0){
				maximo=matriz[i][j];
				band=1;
			}
			else{
				if(matriz[i][j]>maximo){
					maximo=matriz[i][j];
					ejex=i;
					ejey=j;
				}
			}
		}
	}
	
	printf("\n\nEl máximo es: %d, encotrado en la posición [%d][%d]\n",maximo,ejex,ejey);
	
}

void valorMinimo(int matriz[][COLUMNAS], int filas, int columnas) {
    int f, c, minimo, posf, posc;

    for (c = 0; c < columnas; c++) {
        minimo = matriz[0][c];
        posf = 0;
        posc = c;

        for (f = 1; f < filas; f++) {
            if (matriz[f][c] < minimo) {
                minimo = matriz[f][c];
                posf = f;
            }
        }

        printf("\nEl valor mínimo de la columna es %d, encontrado en la posición [%d][%d]\n", minimo, posf + 1, posc + 1);
    }
}

/*
void valorMinimo(int matriz[][COLUMNAS],int filas,int columnas){
	int f,c,band=0,minimo,posf,posc;
	
	for(c=0;c<columnas;c++){		
		for(f=0;f<filas;f++){
			if(band==0){
				minimo=matriz[f][c];
				band=1;
				posf=f;
				posc=c;
			}
			else{
				if(minimo>matriz[f][c]){
					minimo=matriz[f][c];
					posf=f;
					posc=c;
					}
			}				
		}
		printf("\nEl valor mínimo de la columna es %d, encontrado en la posición [%d][%d]\n", minimo, posf+1, posc+1);			
	}			
}
*/
