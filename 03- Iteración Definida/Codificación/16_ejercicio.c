/*Se ingresan DNI y la nota promedio de 10 alumnos. Determinar el DNI del alumno de mayor nota
promedio (considerar único).*/

#include <stdio.h>

int main(){
	int mayorNota = 0;
	int dni,i,nota,dniMayor;
	
	for(i=1;i<=10;i++){
		printf("Ingrese DNI del alumno: ");
		scanf("%d",&dni);
		
		printf("Ingrese nota promedio: ");
		scanf("%d",&nota);
		
		if(nota>mayorNota){
			mayorNota = nota;
			dniMayor = dni;
		}		
	}	
	
	printf("La mayor nota promedio fue %d, obtenida por el alumno con DNI: %d",mayorNota,dniMayor);

	return 0;
}
