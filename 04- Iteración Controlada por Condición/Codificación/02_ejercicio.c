/*Escribir las sentencias que permitan el ingreso correcto del valor numérico de un día y un mes
determinado. Por algún error volver a solicitar.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int dia,mes;
	
	setlocale(LC_ALL,"spanish");
	
	do{
		printf("Ingrese valor numérico de un día: ");
		scanf("%d",&dia);
	}while(dia<1||dia>31);	
	do{
		printf("Ingrese valor numérico de un mes: ");
		scanf("%d",&mes);
	}while(mes<1||mes>12);	
	
	printf("\nDía ingresado: %d \nMes ingresado: %d",dia,mes);
	
	return 0;
}
