/*Realizar un programa que ingrese dos números e indique si el primer número es divisible por el segundo.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int nro1,nro2;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese dos números: \n");
	scanf("%d%d",&nro1,&nro2);
	
	if((nro2!=0)&&(nro1>nro2)&&(nro1%nro2==0)){
		printf("\nEl primer número es divisible por el segundo");
	}
	else{
		printf("\nEl primer número no es divisible por el segundo");
	}
		
	return 0;
}
