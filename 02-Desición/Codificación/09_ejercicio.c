/*Confeccionar un programa que permita convertir grados sexagesimales a radianes y viceversa, según el
valor de un código que se ingresa junto al valor. Si código = 1 se ingresan grados, si es 2 se ingresan radianes.*/

#include <stdio.h>
#include <locale.h>
#define PI 3.14

int main(){
	float nro,rad,grad;
	int cod;
		
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese un número junto a su código de referencia (1 se ingresan grados, si es 2 se ingresan radianes): ");
	scanf("%f%d",&nro,&cod);
	
	if(cod==1){
		rad=(nro*PI/180);
		printf("%.2f grados son %.2f radianes",grad,rad);
	}
	else{
		if(cod==2){
			grad=(nro*180/PI);
			printf("%.2f radianes son %.2f grados",rad,grad);
		}
		else{
			printf("El código ingresado no corresponde a una opción válida");
		}
	}
	
	return 0;
}
