/*Confeccionar un programa que permita ingresar diversas ternas de valores enteros mayores que 0 y
menores que 99. Finalizar el ingreso cuando se informen 3 valores iguales a 96, 97 y 98. Determinar e
informar para cada terna, el mayor y el menor de los valores. Confeccionar y utilizar una función con
parámetros llamada MayorMenor, que permita calcular el menor o el mayor valor de la terna según un
parámetro de configuración.*/

#include <stdio.h>

//Prototipo de funciones

int validarIngreso(int,int);
int condFinal(int,int,int);
int mayorMenor(int,int,int,int);

//main

int main(){
	int bandTernas=1;
	int nro1,nro2,nro3,mayorOMenor;
	
	
	printf("Terna: %d \n ",bandTernas);
	nro1= validarIngreso(0,99);
	nro2= validarIngreso(0,99);
	nro3= validarIngreso(0,99);
	
	while(condFinal(nro1,nro2,nro3)!=1){
		
		printf("\n\nSeleccione 1 si quiere encontrar el mayor de la terna o 2 si quiere encontrar el menor de la terna\n");
		mayorOMenor=validarIngreso(0,3);
		
		mayorMenor(nro1,nro2,nro3,mayorOMenor);
		
		bandTernas++;
		
		printf("\n\nTerna: %d \n ",bandTernas);
		nro1= validarIngreso(0,99);
		nro2= validarIngreso(0,99);
		nro3= validarIngreso(0,99);
	}
	
	return 0;
}

//Definición de funciones

int validarIngreso(int LI,int LS){
	int band=0;
	int nro;
	
	do{
		if(band==0){
			band=1;  
			printf("Ingrese valor: ");
		}
		else{
			printf("Valor fuera de rango, vuelva a ingresar: ");
		}
		
		scanf("%d",&nro);
		
	}while((nro<=LI)||(nro>=LS));
	
	return nro;	
}

int condFinal(int a,int b,int c){
	int fin=0;
	
	if((a==96&&b==97&&c==98)||(a==97&&b==96&&c==98)||(a==98&&b==97&&c==96)||(a==97&&b==98&&c==96)||(a==96&&b==98&&c==97)||(a==98&&b==96&&c==97)||(a==96&&b==96&&c==96)||(a==97&&b==97&&c==97)||(a==98&&b==98&&c==98)){
		fin=1;		
	}
	
	return fin;	
}


int mayorMenor(int a,int b,int c,int select){
	int mayor, menor;
	
	if(select==1){
		mayor=a;
		if(b>mayor){
			mayor=b;
		}
		if(c>mayor){
			mayor=c;
		}
		
		
		printf("\n\nEl mayor de la terna es: %d", mayor);
	}
	else{
		menor=a;
		if(b<menor){
			menor=b;
		}
		if(c<menor){
			menor=c;
		}
				
		printf("\n\nEl menor de la terna es: %d", menor);
	}	
}
