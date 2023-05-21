/*Confeccionar un programa que exhiba por pantalla una lista, a dos columnas, con los primeros 15 números
impares en la primera y los 15 primeros pares en la segunda, incluyendo los títulos.*/

#include <stdio.h
#include <lolcale.h>

int main() {
	
    int i;
    
    printf("Números Impares\tNúmeros Pares\n");
    printf("----------------\t--------------\n");
    
    setlocale

    for (i = 1; i <= 15; i++) {
        printf("%d\t\t\t%d\n", i*2-1, i*2);
    }

    return 0;
}

