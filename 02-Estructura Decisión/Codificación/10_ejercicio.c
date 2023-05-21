/*Escribir un programa que solicite el año y el número de mes y nos informe cuantos días tiene dicho mes.
Debemos considerar que el año puede ser bisiesto. Un año es bisiesto cuando es divisible por 4 y no por
100 o el año es divisible por 400*/

#include <stdio.h>
#include <locale.h>


int main(){
	int anio,mes,dias;
	int band = 0;
	
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese año: ");
	scanf("%d",&anio);	
	printf("Ingrese número de mes: ");
	scanf("%d",&mes);
	
	if(((anio%4)==0)&&((anio%100)!=0)||((anio%400)==0)){
		band = 1;
		printf("\nEs un año bisiesto\n");
	}
	else{
		printf("\nAño no bisiesto\n");
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
	
	printf("\nEl año %d, junto al mes %d tiene %d días",anio,mes,dias);
	
	return 0;
}
