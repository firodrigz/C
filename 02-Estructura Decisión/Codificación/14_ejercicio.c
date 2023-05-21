/*Un negocio vende distintos art�culos identificados por un c�digo, seg�n se muestra:
- c�digo 1; 10; 100: 10 pesos la unidad.
- c�digo 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
- c�digo 3; 33: 3 pesos la unidad. Si la compra es por m�s de 10 unidades se hace un descuento del
10% sobre el total de la compra.
- c�digo 4; 44: 1 peso la unidad.
Confeccionar un programa que ingrese como dato el c�digo de un art�culo y la cantidad a comprar y se
informe el importe de la compra*/

#include <stdio.h>
#include <locale.h>

int main(){
	int cod,cant,caja10,valor,unidad,desc,precio;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese el c�digo del art�culo: ");
	scanf("%d",&cod);
	
	printf("Ingrese cantidad a comprar: ");
	scanf("%d",&cant);
	
	switch(cod){
		case 1:
		case 10:
		case 100: valor=10*cant;
		break;
		
		case 2:
		case 22:
		case 222: caja10=(cant/10);
				  unidad=(cant%10);
				  valor=((caja10*65)+(unidad*7));
		break;
		
		case 3:
		case 33:
		case 333: precio= cant*3;
				  if(cant>10){
				  	desc=precio*10%100;
				  	valor=precio-desc;
				  }
		break;
				  
		case 4:
		case 44: valor= 1*cant;
		break;
	}
	
	printf("El valor es: %d",valor);
	
	return 0;
}
