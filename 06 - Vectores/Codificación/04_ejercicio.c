/*Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un
0 sino lo son.*/

#include <stdio.h>

#define TAM 5

//Prototipo de funciones
void carga(int[],int);
int igualdad(int[],int[],int);

//main
int main(){
	int vector1[TAM];
	int vector2[TAM];
	int esIgual;
	
	printf("Carga del primer vector de un tamaño de 5 elementos\n ");
	carga(vector1, TAM);
	printf("\nCarga del segundo vector de un tamaño de 5 elementos\n ");
	carga(vector2, TAM);
	
	esIgual = igualdad(vector1, vector2, TAM);
	
	if(esIgual == 1){
		printf("Los vectores son iguales");
	}
	else{
		printf("Los vectores no son iguales");
	}
	
	return 0;
}

//Declaración de funciones


void carga(int v[],int ce){
	int i;
	
	for(i=0;i<ce;i++){
		printf("Ingrese valor: ");
		scanf("%d",&v[i]);		
	}	
}

int igualdad(int v1[],int v2[],int ce){
	int es=0;
	int i;
	
	for(i=0;i<ce;i++){
		if(v1[i]==v2[i]){
			es=1;
		}
		else{
			es=0;
		}
	}
	
	return es;
}

