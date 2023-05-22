/*Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se
desea obtener e informar cuantos caracteres ingresados son numéricos y cuantos alfabéticos. Estos últimos
tienen que mostrarse separados por mayúsculas y minúsculas. También informar la cantidad de otros
símbolos que no sean ni letras ni números.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int contNumero = 0, contLetra = 0, contMayus = 0, contMin = 0, contSimbolos = 0;
	char caracter;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese un caracter: ");
	fflush(stdin);
	scanf("%c",&caracter);
	
	while(caracter!='*'){
		
		if((caracter>=48)&&(caracter<=57)){
			contNumero++;
		}
		else{
			if((caracter>=65)&&(caracter<=90)){
				contLetra++;
				contMayus++;				
			}
			else{
				if((caracter>=97)&&(caracter<=122)){
					contLetra++;
					contMin++;
				}
				else{
					contSimbolos++;
				}
			}
		}
		
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c",&caracter);	
		
	}
	
	printf("\nCantidad de caracteres numéricos: %d \nCantidad de caracteres alfanuméricos: %d \nCantidad de mayúsculas: %d \nCantidad de minúsculas: %d \nCantidad de símbolos: %d",contNumero,contLetra,contMayus,contMin,contSimbolos);
	return 0;
}
