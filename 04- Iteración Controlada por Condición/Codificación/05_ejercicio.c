/*De cada uno de los alumnos de un curso se ingresa su número de DNI y las notas de los dos exámenes
parciales confeccionar, un programa que muestre por cada alumno su condición final con el siguiente
mensaje:
“El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”
La condición final se establece según las siguientes reglas:
? PROMOCIONA: ambas notas > = 7
? RINDE EXAMEN FINAL: ambas notas > = 4
? REPROBO LA MATERIA: alguna nota no cumple lo anterior
El programa finaliza cuando se ingresa un valor negativo como número de DNI. Al finalizar mostrar la nota
promedio de alumnos promocionados.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int contProm = 0, contAlum = 0, band = 0;
	int suma,nota1,nota2,dni;
	float promedio;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese DNI del alumno: ");
	scanf("%d",&dni);
	
	while(dni>0){
	contAlum++;
				
		do{
			printf("\nIngrese primer nota: ");
			scanf("%d",&nota1);
			
		}while(nota1<1||nota1>10);
	
		do{
			printf("Ingrese segunda nota: ");
			scanf("%d",&nota2);
			
		}while(nota2<1||nota2>10);
		
		
		if((nota1>=7)&&(nota2>=7)){
			printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [Promocionó]",dni,nota1,nota2);
			contProm++;	
			band=1;		
		}
		else{
			if((nota1>=4)&&(nota2>=4)){				
				printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [Rinde final]",dni,nota1,nota2);
			}
			else{
				printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [Recursa]",dni,nota1,nota2);
			}
		}
				
		printf("\n\nIngrese DNI del alumno: ");
		scanf("%d",&dni);	
	}
	
	if(band==1){
		promedio=(float)contAlum/contProm;
		printf("\nPromedio de alumnos promocionados: %.2f",promedio);
	}
	else{
		printf("\nNo promocionó ningun alumno");
	}
	
	return 0;
}
