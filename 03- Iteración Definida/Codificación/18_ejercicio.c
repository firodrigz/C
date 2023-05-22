/*Realizar un programa que muestre por pantalla las tablas de multiplicar del 1 al 9*/

#include <stdio.h>

int main(){
	int i,j,nro,multiplo;
	
	printf("Ingrese el nro de la tabla de multiplicar que desea: ");
	scanf("%d",&nro);
	
	for(i=1;i<=nro;i++){
		for(j=1;j<=nro;j++){
			multiplo=i*j;
			printf("%3d\t",multiplo);
		}
		printf("\n");
	}	
		
	return 0;
}
