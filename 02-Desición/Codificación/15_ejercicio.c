/*Confeccionar un programa que pueda determinar el importe a pagar por una prestación médica según su
código. Los importes se cobran según la siguiente tabla:*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(){
	int nroHistoria,importe;
	char cod;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese su número de historia clínica: ");
	scanf("%d",&nroHistoria);
	
	printf("Ingrese su código: ");
	fflush(stdin);  //Siempre antes del scanf
	scanf("%c",&cod);
	
	cod = toupper(cod);
	
	switch(cod){
		case 'A': importe=20;
		break;

		case 'D': importe=40;
		break;

		case 'F': importe=60;
		break;

		case 'M':
		case 'T': importe=150;
		break;	
		
	}
	
	printf("El cliente con número de historia clínica: %d , debe abonar: %d ",nroHistoria,importe);	
		
	return 0; 
}
