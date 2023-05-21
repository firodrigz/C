/*Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado. Calcular su sueldo tomando
en cuenta que recibe un premio de $500 si trabajo m�s de 50 horas y, adem�s, si trabaj� m�s de 150 horas
se le otorgan $1000 adicionales.*/

#include <stdio.h>
#include <locale.h>


int main(){
	int valorHora,cantidad,sueldo;
	
	setlocale(LC_ALL, "spanish");
	
	printf("Ingrese valor de hora del empleado: ");
	scanf("%d",&valorHora);
	
	printf("Ingrese la cantidad de horas trabajadas por el empleado: ");
	scanf("%d",&cantidad);
	
	sueldo = valorHora * cantidad;
	
	if(cantidad > 50){
		if(cantidad > 150){
			sueldo = sueldo + 1500;
		}
		else{
			sueldo = sueldo + 500;
		}
	}
	
	printf("El sueldo es: %d",sueldo);
	
	return 0;
}
