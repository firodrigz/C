/*Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las
funciones de la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre
coma espacio y apellido) y mostrarlo*/

#include <stdio.h>
#include <string.h>

int main(){
	char nombre[15];
	char apellido[15];
	char completo[30];
	
	printf("Ingrese nombre: ");
	gets(nombre);
	printf("Ingrese apellido: ");
	gets(apellido);
	
	strcpy(completo,nombre);
	strcat(completo, ", ");
	strcat(completo,apellido);
	
	printf("Nombre completo: ");
	puts(completo);	
	
	return 0;
}
