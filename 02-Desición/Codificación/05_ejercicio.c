/*Confeccionar un programa que permita ingresar 4 n�meros enteros, de a uno por vez y determine el menor
valor y su n�mero de orden. Informe los valores ingresados e identifique al menor con mensaje aclaratorio*/

#include <stdio.h>
#include <locale.h>

int main(){
	int  n1,n2,n3,n4,menor;
	int posi = 1;
	
	setlocale(LC_ALL,"spanish");

	printf("Ingrese primer n�mero: ");
	scanf("%d",&n1);
	
	menor=n1;
	
	printf("Ingrese segundo n�mero: ");
	scanf("%d",&n2);
	
	if(n2<menor){
		menor=n2;
		posi=posi+1;
	}	
	
	printf("Ingrese tercer n�mero: ");
	scanf("%d",&n3);
	
	if(n3<menor){
		menor=n3;
		posi=posi+2;
	}
	
	printf("Ingrese cuarto n�mero: ");
	scanf("%d",&n4);
	
	if(n4<menor){
		menor=n4;
		posi=posi+3;
	}
	
	printf("\nDe los n�meros ingresados %d %d %d %d, el menor de ellos es %d, ingresado en la posici�n %d",n1,n2,n3,n4,menor,posi);	
	
	return 0;
	
}
