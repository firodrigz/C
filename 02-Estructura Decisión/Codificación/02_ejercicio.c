/*Dados tres n�meros determinar e informar con un mensaje si el primer n�mero ingresado es menor que
los otros dos.*/

#include <stdio.h>
#include <locale.h>

int main(){
	
	int nro1,nro2,nro3;
	
	setlocale(LC_ALL,"spanish");  //Idioma
	
	printf("Ingrese 3 n�meros: ");
	scanf("%d%d%d",&nro1,&nro2,&nro3);
	
	if((nro1<nro2)&&(nro1<nro3)){
		printf("N�mero1 es menor que los otros dos n�meros");
	}
	else{
		printf("El primer n�mero es mayor a alguno de los otros dos n�meros ingresados");
	}
	
	return 0;
}
