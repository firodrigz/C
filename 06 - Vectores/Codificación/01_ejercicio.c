/*Ingresar un vector de 10 unidades reales mediante una función llamada CARGA. Luego mediante una
segunda función llamada INVERTIR, generar un segundo vector del mismo tamaño con los elementos ubicados
en el orden inverso al del vector original. Mostrar el vector invertido con una función llamada MOSTRAR.*/

#include <stdio.h>

#define TAM 4  //constante

//Prototipo de funciones
void carga(float [], int);
void invertir(float [], float[], int);
void mostrar(float [], int);

//main
int main(){
	float vector[TAM];
	float vectorInvert[TAM];
	
	carga(vector,TAM);
	invertir(vector, vectorInvert, TAM);
	mostrar(vectorInvert,TAM);
		
	return 0;
}

//Declaración de funciones

void carga(float v[], int ce){
	int i;
	
	printf("Carga del vector\n");
	for(i=0;i<ce;i++){
		printf("Ingrese valor en la posicion %d : ", i+1);
		scanf("%f",&v[i]);
	}
}
void invertir(float v[], float invert[], int ce){
	int i,j;
	
	for(i=ce-1, j=0; i>=0 && j<ce; i--, j++){    //0 1 2 3  memoria
		invert[j]=v[i];							// 5 3 2 1  ingreso
	}
	
	/* SEGUNDA FORMA
	for(i=0;i<ce;i++){				   
		invert[i]=v[ce - 1 - i];	  	
	}	
	*/
	
}

void mostrar(float invert[], int ce){
	int i;
	
	printf("\nMuestra del vector");
	printf("\n   POSICION     ELEMENTO");
	for(i=0;i<ce;i++){
		printf("\n    %d   \t %.2f  ",i+1, invert[i]);
	}
}
