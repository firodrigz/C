/*Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes
aclaratorios la suma, el producto, el cociente y el resto.*/

#include <stdio.h>

int main()
{
	int nro1, nro2, suma, producto, cociente, resto;
	
	printf("Ingrese 2 nros enteros: \n");
	scanf("%d%d",&nro1,&nro2);
		
	suma=nro1+nro2;
	producto=nro1*nro2;
	
	if(nro2==0){
		printf("No se puede dividir por cero \nLa suma es: %d \nEl producto es: %d",suma,producto);
	}
	else{
		cociente=nro1/nro2;
		resto=nro1%nro2;
		printf("La suma es: %d \nEl producto es: %d \nEl cociente es: %d \nEl resto es: %d",suma,producto,cociente,resto);
	}		
	//Se hace el cociente y el resto dentro del if porque sino dá error al ingresar un 0
	return 0;
}
