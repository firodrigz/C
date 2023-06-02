/*Realizar un programa que al ingresar solicite el ingreso de dos números enteros y luego muestre por
pantalla el siguiente menú (las xx de los números deben ser reemplazadas con los valores
correspondientes):
Menú de Opciones
---- -- --------
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos Números
6) Salir
Ingrese su opción:

Al ingresar el número de la opción del 1 al 4, se realiza la operación y muestra el resultado hasta que se
presione una tecla. Luego vuelve a mostrar el menú para poder realizar otra operación con los mismos
números. La opción 5 pide el ingreso de dos nuevos números de trabajo mientras que la opción 6 sale y
cierra el programa.
El ingreso de la opción debe estar validado y en caso de ingresarse un número no válido debe solicitarlo
nuevamente.
Usar una función para mostrar el menú y retornar el valor elegido.
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
	
	printf("\nIngrese primer número entero: ");
	scanf("%d",&nro1);
		
	printf("Ingrese segundo número entero: ");
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
			
			case 5:		printf("\nIngrese primer número entero: ");
						scanf("%d",&nro1);
		
						printf("Ingrese segundo número entero: ");
						scanf("%d",&nro2);	
			break;
		}
		
		printf("\nEl resultado es: %d \n\n ",result);
		
		opcion=menu(nro1,nro2);
	}
	
	return 0;
}

//Definición de funciones

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
	
	printf("\nMenú de Opciones\n---- -- --------\n\nNúmero 1: %d Número 2: %d\n\n1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Ingresar Nuevos Números\n6) Salir\n\nIngrese su opción: ",N1,N2);
	
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
