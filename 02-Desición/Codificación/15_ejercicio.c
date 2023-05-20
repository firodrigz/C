/*Confeccionar un programa que pueda determinar el importe a pagar por una prestaci�n m�dica seg�n su
c�digo. Los importes se cobran seg�n la siguiente tabla:*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(){
	int nroHistoria,importe;
	char cod;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese su n�mero de historia cl�nica: ");
	scanf("%d",&nroHistoria);
	
	printf("Ingrese su c�digo: ");
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
	
	printf("El cliente con n�mero de historia cl�nica: %d , debe abonar: %d ",nroHistoria,importe);	
		
	return 0; 
}
