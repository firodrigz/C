/*Escribir las sentencias que permitan el ingreso correcto del valor num�rico de un d�a y un mes
determinado. Por alg�n error volver a solicitar.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int dia,mes;
	
	setlocale(LC_ALL,"spanish");
	
	do{
		printf("Ingrese valor num�rico de un d�a: ");
		scanf("%d",&dia);
	}while(dia<1||dia>31);	
	do{
		printf("Ingrese valor num�rico de un mes: ");
		scanf("%d",&mes);
	}while(mes<1||mes>12);	
	
	printf("\nD�a ingresado: %d \nMes ingresado: %d",dia,mes);
	
	return 0;
}
