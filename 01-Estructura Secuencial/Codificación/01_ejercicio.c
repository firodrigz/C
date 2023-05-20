//Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo

#include <stdio.h>

int main()
{
	int cantHoras, valorHora, sueldo;
	
	printf("Ingrese cantidad de horas trabajadas: ");
	scanf("%d",&cantHoras);
	printf("Ingrese el valor de cada hora trabajada: ");
	scanf("%d",&valorHora);
	
	sueldo =  cantHoras * valorHora;
	printf("El sueldo es: %d ", sueldo);
	
	return 0;
}
