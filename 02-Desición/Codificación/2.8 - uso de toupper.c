/*Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e informe si lo
ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su correspondiente valor numérico en ASCII. */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(){
	char L,LM;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingresar un carácter alfanumérico: ");
	fflush(stdin);
	scanf("%c",&L);
	
	LM=toupper(L);
	if(LM=='A'||LM=='E'||LM=='I'||LM=='O'||LM=='U'){
		printf("Es vocal");
	}
	else{
		printf("No es vocal");
	}
		
	return 0;
}
