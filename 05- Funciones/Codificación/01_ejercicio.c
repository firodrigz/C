/*Realizar un programa que al ingresar solicite el ingreso de dos n�meros enteros y luego muestre por
pantalla el siguiente men� (las xx de los n�meros deben ser reemplazadas con los valores
correspondientes):
Men� de Opciones
---- -- --------
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos N�meros
6) Salir
Ingrese su opci�n:

Al ingresar el n�mero de la opci�n del 1 al 4, se realiza la operaci�n y muestra el resultado hasta que se
presione una tecla. Luego vuelve a mostrar el men� para poder realizar otra operaci�n con los mismos
n�meros. La opci�n 5 pide el ingreso de dos nuevos n�meros de trabajo mientras que la opci�n 6 sale y
cierra el programa.
El ingreso de la opci�n debe estar validado y en caso de ingresarse un n�mero no v�lido debe solicitarlo
nuevamente.
Usar una funci�n para mostrar el men� y retornar el valor elegido.
*/

#include <stdio.h>
#include <locale.h>

#define LI 1
#define LS 6

//Prototipo de funciones
int validarIngreso(int,int);
int menu(int,int);
int sumar(int,int);
int restar(int,int);
int multiplicar(int,int);
int dividir(int,int);


//Main
int main(){
	
	int opcion, nro1, nro2,result;
	
	setlocale(LC_ALL,"spanish");
	
	printf("\nIngrese primer n�mero entero: ");
	scanf("%d",&nro1);
		
	printf("Ingrese segundo n�mero entero: ");
	scanf("%d",&nro2);
	
	opcion=menu(nro1,nro2);
	
	while(opcion!=6){
		
		switch(opcion){
			case 1:	result=sumar(nro1,nro2);				
			break;
			
			case 2:	result=restar(nro1,nro2);
			break;
			
			case 3:	result=multiplicar(nro1,nro2);
			break;
			
			case 4:	result=dividir(nro1,nro2);
			break;
			
			case 5:		printf("\nIngrese primer n�mero entero: ");
						scanf("%d",&nro1);
		
						printf("Ingrese segundo n�mero entero: ");
						scanf("%d",&nro2);	
			break;
		}
		
		printf("\nEl resultado es: %d \n\n ",result);
		
		opcion=menu(nro1,nro2);
	}
	
	return 0;
}

//Definici�n de funciones

int validarIngreso(int li, int ls){
	int N;
	int band=0;
	
	do{
		if(band==0){
			scanf("%d",&N);
		}
		else{
			printf("No corresponde a las opciones, porfavor ingrese otro valor: ");
			scanf("%d",&N);
		}		
		band++;
	}while(N<li||N>ls);	
	
	return N;
}

int menu(int N1, int N2){
	int ingreso;
	
	printf("\nMen� de Opciones\n---- -- --------\n\nN�mero 1: %d N�mero 2: %d\n\n1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Ingresar Nuevos N�meros\n6) Salir\n\nIngrese su opci�n: ",N1,N2);
	
	ingreso=validarIngreso(LI,LS);
	
	return ingreso;
}

int sumar(int N1,int N2){
	int suma;
	suma=N1+N2;
	return suma;
}

int restar(int N1,int N2){
	int resta;
	resta=N1-N2;
	return resta;	
}

int multiplicar(int N1,int N2){
	int multiplica;
	multiplica=N1*N2;
	return multiplica;
}

int dividir(int N1,int N2){
	int dividir;
	if(N2==0){
		printf("No se puede dividir por 0");
	}
	else{
		dividir=N1/N2;
	}
	return dividir;	
}
