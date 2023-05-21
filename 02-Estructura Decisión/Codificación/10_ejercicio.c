/*Escribir un programa que solicite el a�o y el n�mero de mes y nos informe cuantos d�as tiene dicho mes.
Debemos considerar que el a�o puede ser bisiesto. Un a�o es bisiesto cuando es divisible por 4 y no por
100 o el a�o es divisible por 400*/

#include <stdio.h>
#include <locale.h>


int main(){
	int anio,mes,dias;
	int band = 0;
	
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese a�o: ");
	scanf("%d",&anio);	
	printf("Ingrese n�mero de mes: ");
	scanf("%d",&mes);
	
	if(((anio%4)==0)&&((anio%100)!=0)||((anio%400)==0)){
		band = 1;
		printf("\nEs un a�o bisiesto\n");
	}
	else{
		printf("\nA�o no bisiesto\n");
	}
	
	switch(mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: dias = 31;		
		break;	
		
		case 4:
		case 6:
		case 9:
		case 11: dias = 30;
		break;
		
		case 2: dias = 28;		
	}
	
	if(band==1){
		if(mes==2){
			dias=29;
		}		
	}
	
	printf("\nEl a�o %d, junto al mes %d tiene %d d�as",anio,mes,dias);
	
	return 0;
}
