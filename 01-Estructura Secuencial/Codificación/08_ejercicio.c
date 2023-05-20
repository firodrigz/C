/*Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a un 
número con formato (aammdd).*/

#include <stdio.h>

int main(){
	int fecha,dd,aux,mm,aa,nuevoFormato;
	
	printf("Ingrese fecha con formato (ddmmaa): ");
	scanf("%d",&fecha);
	
	dd=fecha/10000;
	aux=fecha % 10000;
	mm=aux/100;
	aa=aux%100;
	
	nuevoFormato= aa*10000 + mm*100 + dd;
	
	printf("\nNúmero con formato (aammdd): %d",nuevoFormato);
		
	return 0;
}
