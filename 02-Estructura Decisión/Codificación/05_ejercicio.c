/*Confeccionar un programa que permita ingresar 4 números enteros, de a uno por vez y determine el menor
valor y su número de orden. Informe los valores ingresados e identifique al menor con mensaje aclaratorio*/

#include <stdio.h>
#include <locale.h>

int main(){
	int  n1,n2,n3,n4,menor;
	int posi = 1;
	
	setlocale(LC_ALL,"spanish");

	printf("Ingrese primer número: ");
	scanf("%d",&n1);
	
	menor=n1;
	
	printf("Ingrese segundo número: ");
	scanf("%d",&n2);
	
	if(n2<menor){
		menor=n2;
		posi=posi+1;
	}	
	
	printf("Ingrese tercer número: ");
	scanf("%d",&n3);
	
	if(n3<menor){
		menor=n3;
		posi=posi+2;
	}
	
	printf("Ingrese cuarto número: ");
	scanf("%d",&n4);
	
	if(n4<menor){
		menor=n4;
		posi=posi+3;
	}
	
	printf("\nDe los números ingresados %d %d %d %d, el menor de ellos es %d, ingresado en la posición %d",n1,n2,n3,n4,menor,posi);	
	
	return 0;
	
}
