/*Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados). Se pide
determinar el/los empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a
cero.
a. Los números de legajo son números correlativos de 1 a 100.*/

#include <stdio.h>
#define TAM 100

//Prototipo de funciones
float validar(float);
int cargaIncompleta(int [],float [],int);
void valorMaximo(float[],int[],int);

//main
int main(){
	int legajos[TAM];
	float sueldos[TAM];
	int cant;
	
	cant=cargaIncompleta(legajos,sueldos,TAM);
	valorMaximo(sueldos,legajos,cant);
	
	return 0;
}

//Definión de funciones

void valorMaximo(float VA[],int LJ[],int ce){
	int band=0;
	int i,pos;
	float mayor;
	
	
	for(i=0;i<ce;i++){
		if(band==0){
			mayor=VA[i];
			band=1;
		}
		else{
			if(VA[i]>mayor){
				mayor=VA[i];
			}
		}		
	}
	
	printf("\nEl sueldo más alto es: %.2f\n Los legajos con dicho sueldo son: \n",mayor);
	for(i=0;i<ce;i++){
		if(VA[i]==mayor)
		printf("\t%d\n",LJ[i]);
	}
}

float validar(float LI){
	float nro;
	int band=0;
	
	do{
		if(band==0){
			printf("Ingrese sueldo: ");
		}
		else{
			printf("Error, valor fuera de rango, intente nuevamente: ");
		}
		
		scanf("%f",&nro);
		
	}while(nro<LI);
	
	return nro;	
}

int cargaIncompleta(int legajos[],float sueldos[],int ce){
	int auxLegajos;
	int i=0;
	
	printf("\nIngrese 1 para ingresar sueldos, 0 para finalizar carga: ");
	scanf("%d",&auxLegajos);
	
	while(auxLegajos!=0 && i<ce){
		legajos[i]=i+1;
		sueldos[i]=validar(0);
		i++;
		
		printf("\nIngrese 1 para ingresar sueldos, 0 para finalizar carga: ");
		scanf("%d",&auxLegajos);		
	}
	
	return i;
}


