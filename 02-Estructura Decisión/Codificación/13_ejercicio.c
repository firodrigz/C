/*La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente
escala: 
a. menor de $55 el descuento es del 4.5%
b. entre $55 y $100 el descuento es del 8%
c. más de $100 el descuento es del 10.5%
Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con
mensajes aclaratorios.*/

#include <stdio.h>
#include <locale.h>

int main(){
	float precio,descto5,descto8,descto10;   
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese el importe de la compra: ");
	scanf("%f",&precio);
	
	descto5= precio*4.5/100;
	descto8= precio*8/100;
	descto10= precio*10.5/100;
	
	if(precio<55){
		precio=precio-descto5;
		printf("\nSe aplicó un descuento del 4.5%, el precio final es %.2f",precio);
	}
	else{
		if(precio>100){
			precio=precio-descto10;
			printf("\nSe aplicó un descuento del 10.5%, el precio final es %.2f",precio);
		}
		else{
			if((precio>=55)&&(precio<=100)){
				precio=precio-descto8;
				printf("\nSe aplicó un descuento del 8%, el precio final es %.2f",precio);
			}			
		}
	}
	
	return 0;
}
