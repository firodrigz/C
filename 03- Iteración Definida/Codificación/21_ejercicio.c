/*Tomando como base el ejercicio anterior ingresar un número entero mayor a 0 y dibujar un rombo con
*. Por ejemplo, si se ingresa el número 5 dibuja la pirámide de 5 filas y luego completa el rombo al ir
decrementando la cantidad de asteriscos.*/


#include <stdio.h>
#include <locale.h>

int main(){
	int i,j,filas,asteriscos;
	
	setlocale(LC_ALL,"spanish");
		
	printf("Ingrese la cantidad de filas que quiera su triángulo rectángulo: ");
	scanf("%d",&filas);
	
	for(i=1;i<=filas;i++){
		
		asteriscos = 2 * i - 1;  //Generador de asteriscos x2
		
		for(j=1;j<=asteriscos;j++){
			printf("*");
		}
		printf("\n");
	}	
	
	for(i=filas-1;i>=1;i--){
		
		asteriscos = 2 * i - 1; 
		
		for(j=asteriscos;j>=1;j--){
			printf("*");
		}
		printf("\n");
	}	
	
	return 0;
}
