//Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.

#include <stdio.h>

int main(){
	int nro,centena,decena,unidad;
	
	printf("Ingrese un nro de 3 cifras: ");
	scanf("%d",&nro);
	
	centena=(nro/100)*100;
	decena=((nro%100)/10)*10;
	unidad=((nro%100)%10)*1;
	
	printf("Centena: %d \nDecena: %d \nUnidad: %d",centena,decena,unidad);
	
	return 0;
}
