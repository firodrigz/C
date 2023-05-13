//Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.

#include <stdio.h>
#include <ctype.h>  //librería utilizada para casteo

int main()
{
	int nota1, nota2;
	float promedio;
	
	printf("Ingrese las notas de dos evaluaciones de un alumno: \n");
	scanf("%d%d", &nota1, &nota2);
	promedio = (float)(nota1 + nota2)/2;  //casteo generalmente se hace en el numerador
	printf("Promedio del alumno: %.2f", promedio);
	
	return 0;
}
