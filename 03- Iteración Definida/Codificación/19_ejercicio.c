/*Ingresar un número entero mayor a 0. Debe dibujar un triángulo rectángulo con * con tantas filas como
el número indicado. En cada fila se va incrementando la cantidad de asteriscos. Por ejemplo, si se ingresa el
número 6 debe mostrar en pantalla: */

#include <stdio.h>
#include <locale.h>

int main(){
	int i,j,filas;
	
	setlocale(LC_ALL,"spanish");
		
	printf("Ingrese la cantidad de filas que quiera su triángulo rectángulo: ");
	scanf("%d",&filas);
	
	for(i=1;i<=filas;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}	
		
	return 0;
}
