/*Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con dicho valor calcule
la superficie del círculo, la longitud de la circunferencia (perímetro) y el volumen de la esfera.*/

#include <stdio.h>
#define PI 3.1415

int main(){
	float radio,superficie,longitud,volumen;
	
	printf("Ingrese el valor del radio (r) de un círculo: ");
	scanf("%f",&radio);
	
	superficie = PI*radio*radio;
	longitud = 2*PI*radio;
	volumen = 4/3*PI*radio*radio*radio;
	
	printf("Superficie: %.2f \nLongitud: %.2f \nVolumen: %.2f",superficie,longitud,volumen);	
	
	return 0;
}
