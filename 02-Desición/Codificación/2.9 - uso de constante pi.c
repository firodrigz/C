/*Confeccionar un programa que permita convertir grados sexagesimales a radianes y viceversa, seg�n el
valor de un c�digo que se ingresa junto al valor. Si c�digo = 1 se ingresan grados, si es 2 se ingresan radianes.*/

#include <stdio.h>
#include <locale.h>
#define PI 3.14

int main(){
	float nro,rad,grad;
	int cod;
		
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese un n�mero junto a su c�digo de referencia (1 se ingresan grados, si es 2 se ingresan radianes): ");
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
			printf("El c�digo ingresado no corresponde a una opci�n v�lida");
		}
	}
	
	return 0;
}
