/*Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.*/

#include <stdio.h>

#define TAM 100
#define TAMSEC 5


//Prototipo de funciones
int validar(int,int,int);
float validarSuel(float);
int cargaEmpleados(int[],int[],float[],int);
void inicializar(int [],int);
void mostrarCuentSec(int[],int);
void cuentaEmplSec(int[],int[],int,int);
void importeTotal(float[],int);

//main
int main(){
	int vecDni[TAM];
	int vecSec[TAM];
	float vecSuel[TAM];
	int vecCuenSec[TAMSEC];
	int cant;
	
	cant=cargaEmpleados(vecDni,vecSec,vecSuel,TAM);
	
	if(cant==0){
		printf("No se ingresó ningún empleado");
	}
	else{
		cuentaEmplSec(vecSec,vecCuenSec,cant,TAMSEC);
		importeTotal(vecSuel,cant);		
	}	
	
	return 0;
}


//Declaración de funciones
int cargaEmpleados(int vDni[],int vSec[], float vSuel[], int ce){
		int auxDni;
		int i=0;		
	
		printf("DNI ingreso");
		auxDni=validar(4000000,99999999,99);
	
		while(auxDni!=99 && i<ce){
			vDni[i]=auxDni;
			printf("\nSECTOR ingreso");
			vSec[i]=validar(1,5,5);
			printf("\nSUELDO ingreso");
			vSuel[i]=validarSuel(0);
			
			i++;
			
			printf("\nDNI ingreso");
			auxDni=validar(4000000,99999999,99);		
		}		
		return i;	
}

void inicializar(int v[],int tamsec){
	int i;
	
	for(i=0;i<tamsec;i++){
		v[i]=0;
	}	
}

void mostrarCuentSec(int v[],int ce){
	int i;
	
	printf("\nCantidad de empleados por sector: \n");
	for(i=0;i<ce;i++){
		printf("%4d",v[i]);
	}	
}

void cuentaEmplSec(int vecSec[],int vecCuenSec[],int cant,int tamsec){
	int i;
	
	inicializar(vecCuenSec,tamsec);
	
	for(i=0;i<cant;i++){
		vecCuenSec[vecSec[i]-1]++; //vector con referencia a otro vector
	}
	
	mostrarCuentSec(vecCuenSec,TAMSEC);	
}


int validar(int LI,int LS,int EXC){
	int nro;
	int band=0;
	
	do{
		if(band==0){
			printf("\nIngrese valor: ");
			band=1;
		}
		else{
			printf("Error! valor fuera de rango, vuelva a intentarlo: ");
		}
		
		scanf("%d",&nro);
		
	}while((nro<LI||nro>LS)&&nro!=EXC);
	
	return nro;
}


float validarSuel(float LI){
	float nro;
	int band=0;
	
	do{
		if(band==0){
			printf("\nIngrese valor: ");
		}
		else{
			printf("Error! valor fuera de rango, vuelva a intentarlo: ");
		}		
		scanf("%f",&nro);
		
	}while(nro<LI);
	
	return nro;
}


void importeTotal(float suel[],int ce){
	float suma=0;
	int i;
	
	for(i=0;i<ce;i++){
		suma+=suel[i];
	}
	
	printf("\n\nCantidad total a pagar a empleados: \n");
	printf("\t%.2f",suma);	
}
