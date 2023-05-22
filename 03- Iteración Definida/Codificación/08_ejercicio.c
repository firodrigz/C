/* Ingresar N y N N�meros naturales. Determinar e informar:
a. La sumatoria de los valores m�ltiplos de 3.
b. La cantidad de valores m�ltiplos de 5.
c. La sumatoria de los valores que se ingresan en orden par*/

#include <stdio.h>
#include <locale.h>

int main(){
	int sumamultiplo = 0,cont5 = 0,sumapar = 0;
	int i,limite,nro;
		
	setlocale(LC_ALL,"spanish");
		
	printf("Ingrese cantidad de n�meros a ingresar: ");
	scanf("%d",&limite);   //ingreso por teclado hasta donde va a llegar el for
	
	for(i=1;i<=limite;i++){
		printf("Ingrese un n�mero: ");
		scanf("%d",&nro);
		
		if((nro%5)==0){
			cont5++;
		}
		if((nro%3)==0){
			sumamultiplo+=nro;
		}
		if((nro%2)==0){
			sumapar+=nro;
		}		
	}
	
	printf("\nSumatoria de los valores m�ltiplos de 3: %d \nLa cantidad de valores m�ltiplos de 5: %d \nLa sumatoria de los valores que se ingresan en orden par: %d",sumamultiplo,cont5,sumapar);	
	
	return 0;
}
