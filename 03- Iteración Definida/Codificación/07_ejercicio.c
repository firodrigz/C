/*Se ingresan 100 letras. Determinar la cantidad de vocales ingresadas.*/

#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
	int cont = 0;
	int i;
	char letra; 
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=10;i++){
		printf("Ingrese una letra del alfabeto: ");
		fflush(stdin);
		scanf("%c",&letra);
		letra=toupper(letra);		
	
		if((letra=='A')||(letra=='E')||(letra=='I')||(letra=='O')||(letra=='U')){
			cont++;
		}		
	}
	
	printf("\nVocales ingresadas: %d",cont);	
	
	return 0;
}
