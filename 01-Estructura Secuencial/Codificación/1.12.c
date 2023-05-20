/*Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%. Confeccionar un 
programa que recibiendo el precio original y un código que indica si es o no con descuento, informe el precio 
final (0 no aplica el descuento y 1 aplica el descuento)*/

#include <stdio.h>

int main(){
	int precioOriginal,codigo,descuento,precioFinal;
	
	printf("Ingrese el precio original del producto: ");
	scanf("%d",&precioOriginal);
	
	printf("Ingrese código de descuento: ");
	scanf("%d",&codigo);
	
	descuento=(precioOriginal*20/100)*codigo;
	precioFinal=precioOriginal- descuento;
	
	printf("Valor total: %d",precioFinal);		
	
	return 0;
}
