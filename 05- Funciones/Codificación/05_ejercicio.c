/*Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante, que finalice al
ingresar una terna con los valores ORDENADOS en forma creciente. Para cada terna exhibir la siguiente
pantalla:
** OPCIONES POSIBLES **
1 – Mayor valor
2 – Promedio
3 – Suma
4 - Finalizar
** Digite su opción:
Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros
valores de opción. Confeccionar y utilizar una función PARA CADA UNA de las opciones y otra para detectar
la condición final.*/

#include <stdio.h>
#include <locale.h>

//Prototipo de funciones

int validarIngreso(int,int);
int mostrarMenu();
float ingreso();
int valoresOrdenados(float,float,float);
float mayorValor(float,float,float);
float suma(float,float,float);
float promedio(float,float,float);


/*-----------------------------------------------------------------------*/

int main(){
	
	float valor1, valor2, valor3, valorMostrar;
	int ternas = 1; 
	int opcion;
	
	
	setlocale(LC_ALL,"spanish");
	
	printf("\nTerna número: %d \n",ternas);
	valor1= ingreso();
	valor2= ingreso();
	valor3= ingreso();	
	
	
	while(valoresOrdenados(valor1,valor2,valor3)!=1){
		
		opcion=mostrarMenu();			
		
		ternas++;
		
		while(opcion!=4){	
			
			switch(opcion){
				case 1: valorMostrar = mayorValor(valor1,valor2,valor3);
						printf("\nEl mayor valor es: %.2f", valorMostrar);
				break;
				 
				case 2: valorMostrar = promedio(valor1,valor2,valor3);
						printf("\nEl promedio de los números ingresados es: %.2f", valorMostrar);
				break;
				
				case 3: valorMostrar = suma(valor1,valor2,valor3);
						printf("\nLa suma de los números ingresados es: %.2f", valorMostrar);
				break;						
			}
			
			opcion=mostrarMenu();			
		}
			
		printf("\nTerna número: %d \n",ternas);
		valor1= ingreso();
		valor2= ingreso();
		valor3= ingreso();	
						
	}
		
	return 0;
}

//Definición de funciones

int validarIngreso(int LI,int LS){
	int band=0;
	int nro;
	
	do{
		if(band==0){
		printf("Digite su opción: ");
		band=1;
		}
		else{
			printf("Opción fuera de rango, intente nuevamente: ");
		}
		
		scanf("%d",&nro);
	}while(nro<LI||nro>LS);	
	
	return nro;
}

int mostrarMenu(){
	int opcion;
	
	printf("\n\n1-Mayor valor \n2-Promedio \n3-Suma \n4-Finalizar \n\n");
	opcion=validarIngreso(1,4);
	
	return opcion;
}

float ingreso(){
	float nro;
		
	printf("Ingrese valor: ");	
	scanf("%f",&nro);
	
	return nro;
}


int valoresOrdenados(float a, float b, float c){
	if((a<b)&&(b<c)&&(a<c)){
		return 1;
	}
	else{
		return 0;
	}
}

float mayorValor(float a,float b,float c){
	float mayor;
		
	mayor=a;
	
	if(b>mayor){
		mayor=b;
	}
	else{
		if(c>mayor){
			mayor=c;
		}
	}	
	
	return mayor;
}


float suma(float a,float b,float c){
	return (a+b+c);	
}

float promedio(float a,float b,float c){
	float promedio;
	
	promedio= suma(a,b,c)/3;
		
}

