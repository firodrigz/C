/*Se desea realizar un programa para calcular el sueldo final a pagar a cada empleado de una empresa. De
cada uno se tiene, sueldo básico, antigüedad, cantidad de hijos y estudios superiores (‘S’ o ‘N’). Además, se
conocen los porcentajes de aumento del sueldo que dependen de los siguientes factores:
- Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
- Si el empleado tiene más de 2 hijos: aumento del 10%, si solo tiene uno 5%
- Si el empleado posee estudios superiores: aumento del 5%
Luego de ingresar los datos de un empleado se debe preguntar si se desea ingresar otro empleado o no. Se
termina la carga cuando no se deseen ingresar más empleados.
Determinar:
a. Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
b. Sueldo nuevo promedio de la empresa.*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(){
	int antiguedad,cantHijos;
	int cont = 0;
	float sueldoBasico,aumentoAntiguedad,aumentoHijo,aumentoMHijo,aumentoEstudios,nuevoSueldo;
	float sueldoTotal = 0;
	char continuar, estudios;
		
	setlocale(LC_ALL,"spanish");
	
	do{
		cont++;
		
		do{
			printf("Ingrese sueldo básico: ");
			scanf("%f",&sueldoBasico);
		}while(sueldoBasico<=0);
		
		do{		
			printf("Ingrese años de antiguedad: ");
			scanf("%d",&antiguedad);
		}while(antiguedad<0);
		
		do{
			printf("Ingrese cantidad de hijos: ");
			scanf("%d",&cantHijos);
		}while(cantHijos<0);	
			
		do{
			printf("¿Tiene estudios superiores? (‘S’ o ‘N’): ");
			fflush(stdin);
			scanf("%c",&estudios);	
			estudios=toupper(estudios);
		}while(estudios!='S' && estudios!='N');	
	
		if(antiguedad>10){
			aumentoAntiguedad=(sueldoBasico*10/100);
		}
		
		if(cantHijos==1){
			aumentoHijo=(sueldoBasico*5/100);
		}
		else{
			if(cantHijos>2){
				aumentoMHijo=(sueldoBasico*10/100);
			}
		}
		
		if(estudios=='S'){
			aumentoEstudios=(sueldoBasico*5/100);
		}
		
		nuevoSueldo=sueldoBasico+aumentoAntiguedad+aumentoHijo+aumentoMHijo+aumentoEstudios;
		
		sueldoTotal+=nuevoSueldo;
		
		printf("\nNúmero de empleado: %d \nSueldo básico: %.2f \nNuevo sueldo: %.2f",cont,sueldoBasico,nuevoSueldo);
		
		do{
			printf("\n\n¿Desea ingresar otro usuario? (‘S’ o ‘N’): ");
			fflush(stdin);
			scanf("%c",&continuar);
			continuar=toupper(continuar); 
		}while(continuar!='S' && continuar!='N');		
			
	}while(continuar=='S');
	
	printf("\nPromedio de Sueldo en la empresa: %.2f",sueldoTotal/cont);
	
	return 0;
}
