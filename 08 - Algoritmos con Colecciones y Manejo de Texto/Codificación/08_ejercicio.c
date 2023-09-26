/* Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo. */

#include <stdio.h>
#include <string.h>

void leerFrase(char [], int);
int contarPalabras(char []);

int main(){
	char frase[501];
	int i, cantidadPalabras;
	
	printf("Ingrese frase de 500 caracteres: ");
	leerFrase(frase,501);
	
	cantidadPalabras=contarPalabras(frase);
	printf("La frase contiene %d palabra(s).\n", cantidadPalabras);	
	
	return 0;
}


void leerFrase(char frase[], int ce){
	int i=0;
	
	fgets(frase,ce,stdin);
	
	while(frase[i]!='\0'){
		if(frase[i]=='\n'){
			frase[i]='\0';
		}else{
			i++;
		}
	}
}

int contarPalabras(char frase[]){
	int contador = 0, i = 0;
    int dentroDePalabra = 0; // Bandera que indica si estamos dentro de una palabra

    while(frase[i] != '\0'){
        if (frase[i] == ' ' || frase[i] == '\t') {
            dentroDePalabra = 0; // Si encontramos un espacio, nueva palabra no encontrada
        } else if (dentroDePalabra == 0) {
            contador++; // Si estamos fuera de una palabra, incrementamos el contador
            dentroDePalabra = 1; // Estamos ahora dentro de una palabra
        }
        i++;
    }

    return contador;
}
