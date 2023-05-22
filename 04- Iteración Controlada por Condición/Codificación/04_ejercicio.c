/*Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe total
y un código que indica la forma de pago. El código puede ser:
? C: cheque, 20% de recargo.
? E: efectivo, 10% de descuento.
? T: con tarjeta, 12% de recargo.
Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
Efectivo en Caja: $ xxxx.xx
Ventas con Tarjeta de Crédito: $ xxxx.xx
Ventas con cheque: $ xxxx.xx
Total de Venta: $ xxxx.xx
Importe del IVA: $ xxxx.xx
Nota: El IVA corresponde al 21% del total de ventas.*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#define porcentC 20
#define porcentE 10
#define porcentT 12
#define IVA 21

int main(){
	float acumC = 0, acumE = 0, acumT = 0;   //acumuladores
	float importe,recargoA,descuentoA,recargoB,total,ivaV;
	char cod;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese código que indique su la forma de pago: ");
	fflush(stdin);
	scanf("%c",&cod);
	cod=toupper(cod);
	
	while(cod!='F'){
		
		printf("Ingrese importe: ");
		scanf("%f",&importe);
		
		switch(cod){
			case 'C':
				recargoA=importe+(importe*porcentC/100);
				acumC+=recargoA;
				break;
			
			case 'E':
				descuentoA=importe-(importe*porcentE/100);
				acumE+=descuentoA;
				break;
				
		 	case 'T':
				recargoB=importe+(importe*porcentT/100);
				acumT+=recargoB;
				break;
			
		}
		
		printf("\nIngrese código que indique su la forma de pago: ");
		fflush(stdin);
		scanf("%c",&cod);
		cod=toupper(cod);
		
	}
	
	total=acumC+acumE+acumT;
	ivaV=(total*IVA/100);	
	
	printf("\nEfectivo en Caja: $ %.2f \nVentas con Tarjeta de Crédito: $ %.2f \nVentas con cheque: $ %.2f \nTotal de Venta: $ %.2f \nImporte del IVA: $ %.2f",acumE,acumT,acumC,total,ivaV);
	
	return 0;
}
