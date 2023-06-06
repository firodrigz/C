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

int validarIngreso(int,int);
void mostrarMenu();
float ingreso();
int valoresOrdenados(float,float,float);


int main(){
	
	float valor1, valor2, valor3;
	int ternas = 1;  //preguntar
	
	
	setlocale(LC_ALL,"spanish");
	
	printf("\nTerna número: %d \n"),ternas;
	valor1= ingreso();
	valor2= ingreso();
	valor3= ingreso();
	
	mostrarMenu();
	
	while(valoresOrdenados(valor1,valor2,valor3)!=1){
				
		
		printf("\nTerna número: %d \n"),ternas;
		valor1= ingreso(ternas);
		valor2= ingreso(ternas);
		valor3= ingreso(ternas);
		
		ternas++;
		
		mostrarMenu();
	}
	
	
	return 0;
}



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

void mostrarMenu(){
	printf("\n\n1-Mayor valor \n2-Promedio \n3-Suma \n4-Finalizar \n\n");
	validarIngreso(1,4);
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
