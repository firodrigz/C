/*Mostrar por pantalla los n�meros pares comprendidos entre 100 y 500.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int i;
	
	setlocale(LC_ALL,"spanish");
	
	printf("N�meros pares comprendidos entre 100 y 500\n");
	
	for(i=100;i<=500;i+=2){
		printf("\n%d",i);
	}	
		
	return 0;
}
