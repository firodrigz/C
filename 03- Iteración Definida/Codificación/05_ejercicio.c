/*Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int suma = 0;  //acumulador
	int i;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=100;i>=50;i-=5){
		suma+=i;
	}
	
	printf("El cálculo de la suma es: %d ",suma);
		
	return 0;
}

