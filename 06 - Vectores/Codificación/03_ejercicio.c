/*Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere
un vector de 10 posiciones con el contenido de ambos vectores intercalados*/

#include <stdio.h>
#define TAM 5
#define TAMTOTAL 10


//Prototipo de funciones
void cargar(int [], int);
void mostrar(int [],int);
void unirIntercalado(int[], int[], int[], int);

//main
int main(){
	int vector1[TAM];
	int vector2[TAM];
	int vectorTotal[TAMTOTAL];
	
	printf("Carga de primer vector \n");
	cargar(vector1,TAM);
	printf("\nCarga de segundo vector \n");
	cargar(vector2,TAM);
	
	unirIntercalado(vector1,vector2,vectorTotal,TAM);
	
	mostrar(vectorTotal,TAMTOTAL);
	
	return 0;
}

//Definición de funciones
void cargar(int v[], int ce){
	int i;
	
	for(i=0;i<ce;i++){
		printf("Ingrese valor: ");
		scanf("%d",&v[i]);
	}	
}

void unirIntercalado(int v1[], int v2[], int vu[], int tam){
	int i, j;
	
	printf("\nVector que muestra el contenido de ambos vectores intercalados\n");
	
	for(i=0, j=0 ;i<tam;i++,j+=2){
		vu[j]=v1[i];
		vu[j+1]=v2[i];
	}
}

void mostrar(int v[], int ce){
	int i;
	
	for(i=0;i<ce;i++){
		printf("%4d",v[i]);		
	}	
}

