/*Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se
desea obtener e informar cuantos caracteres ingresados son num�ricos y cuantos alfab�ticos. Estos �ltimos
tienen que mostrarse separados por may�sculas y min�sculas. Tambi�n informar la cantidad de otros
s�mbolos que no sean ni letras ni n�meros.*/

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
	
	printf("\nCantidad de caracteres num�ricos: %d \nCantidad de caracteres alfanum�ricos: %d \nCantidad de may�sculas: %d \nCantidad de min�sculas: %d \nCantidad de s�mbolos: %d",contNumero,contLetra,contMayus,contMin,contSimbolos);
	return 0;
}
