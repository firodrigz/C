/*Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número
indicado. En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int numFilas, fila, espacios, asteriscos, i;
	
	setlocale(LC_ALL,"spanish");

    printf("Ingrese el número de filas para la pirámide: ");
    scanf("%d", &numFilas);

    for (fila = 1; fila <= numFilas; fila++) {
        // Imprimir espacios en blanco antes de los asteriscos
        for (espacios = 1; espacios <= numFilas - fila; espacios++) {
            printf(" ");
        }

        // Imprimir asteriscos
        asteriscos = 2 * fila - 1;
        for (i = 1; i <= asteriscos; i++) {
            printf("*");
        }

        // Cambiar de línea después de cada fila
        printf("\n");
    }
    
	return 0;
}
