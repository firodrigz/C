/*Dados tres números determinar e informar con un mensaje si el primer número ingresado es menor que
los otros dos.*/

#include <stdio.h>
#include <locale.h>

int main(){
	
	int nro1,nro2,nro3;
	
	setlocale(LC_ALL,"spanish");  //Idioma
	
	printf("Ingrese 3 números: ");
	scanf("%d%d%d",&nro1,&nro2,&nro3);
	
	if((nro1<nro2)&&(nro1<nro3)){
		printf("Número1 es menor que los otros dos números");
	}
	else{
		printf("El primer número es mayor a alguno de los otros dos números ingresados");
	}
	
	return 0;
}
