/*Dadas 20 notas y legajos de alumnos de un curso. Determinar:
a. Cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int aplazados=0;
	int i,nota,legajo;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=20;i++){
		printf("Ingrese legajo del alumno: ");
		scanf("%d",&legajo);
		
		printf("Ingrese nota del alumno: ");
		scanf("%d",&nota);
		
		if(nota>7){
			printf("El alumno con legajo %d , ha promocionado\n\n",legajo);
		}
		else{
			aplazados++;
		}		
	}
	
	printf("Cantidad de aplazados: %d ",aplazados);
	
	return 0;
}
