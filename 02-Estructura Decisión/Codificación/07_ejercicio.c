/*Realizar un programa que ingrese dos n�meros e indique si el primer n�mero es divisible por el segundo.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int nro1,nro2;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese dos n�meros: \n");
	scanf("%d%d",&nro1,&nro2);
	
	if((nro2!=0)&&(nro1>nro2)&&(nro1%nro2==0)){
		printf("\nEl primer n�mero es divisible por el segundo");
	}
	else{
		printf("\nEl primer n�mero no es divisible por el segundo");
	}
		
	return 0;
}
