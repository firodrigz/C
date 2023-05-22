/*Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
a. Edad promedio.
b. Estatura promedio.
c. Cantidad de alumnos mayores de 10 años.
d. Cantidad de alumnos que miden menos de 1.40 cm.*/

#include <stdio.h>
#include <locale.h>
#define cantAlumnos 4   //constante

int main(){
	int edadSuma = 0, estaturaSuma = 0;  //acumuladores
	int mayores = 0, bajaEstatura = 0;	//contadores 
	int i,edad,edadPromedio;
	float estatura,estaturaPromedio;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=cantAlumnos;i++){
		printf("Ingrese edad del alumno: ");
		scanf("%d",&edad);
		
		printf("Ingrese estatura del alumno en mts: ");
		scanf("%f",&estatura);
		
		edadSuma+=edad;
		estaturaSuma+=estatura;
		
		if(edad>10){
			mayores++;
		}
		
		if(estatura<140){
			bajaEstatura++;
		}		
	}
	
	estaturaPromedio= (float)(estaturaSuma)/cantAlumnos; //casteo
	edadPromedio= edadSuma/cantAlumnos;  //NO se castea porque el contexto edad lo limita
	
	printf("\nLa estatura promedio es: %.2f \nLa edad promedio es: %d",estaturaPromedio,edadPromedio);
	
	return 0;
}
