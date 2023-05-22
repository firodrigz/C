/*Ingresar un n�mero entero mayor a 0. Debe dibujar un tri�ngulo rect�ngulo con * con tantas filas como
el n�mero indicado. En cada fila se va incrementando la cantidad de asteriscos. Por ejemplo, si se ingresa el
n�mero 6 debe mostrar en pantalla: */

#include <stdio.h>
#include <locale.h>

int main(){
	int i,j,filas;
	
	setlocale(LC_ALL,"spanish");
		
	printf("Ingrese la cantidad de filas que quiera su tri�ngulo rect�ngulo: ");
	scanf("%d",&filas);
	
	for(i=1;i<=filas;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}	
		
	return 0;
}
