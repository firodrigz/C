/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota*/


/*
	2 vectores, 1 de dni y otro de nota (de 60 posiciones ambos)
	Ingreso de DNI único (uso de función búsqueda) (finaliza con 0)
	Mostrar listado ordenado de mayor a menor por nota


*/
#include <stdio.h>
#define TAM 60

int busqueda(int[], int, int);
int valida(int,int, int);
int cargaIncompleta(int[], int[], int);
void ordenarMayorMenor(int [], int[], int);
void mostrarListado(int [], int[], int);

int main(){
	int vectorDNI[TAM];
	int vectorNOTA[TAM];
	int ingreso;
			
	ingreso = cargaIncompleta(vectorDNI,vectorNOTA,TAM);
	
	if(ingreso!=0){
		ordenarMayorMenor(vectorDNI,vectorNOTA,TAM);
		mostrarListado(vectorDNI,vectorNOTA,TAM);
	}
	return 0;
}

int busqueda(int Vdni[], int nro, int hasta){
	int i, encuentra=-1;
	
	while(i<hasta && pos==-1){
		if(Vdni[i]==nro){
			encuentra=i;
		}
		else{
			i++;
		}
	}
	
	return encuentra;
}

int valida(int LI,int LS, int exc){
	int nro, band=0;
	do{
		if(band==0){
			printf("Ingrese una nota entre %d y %d", LI,LS);
			band++;
		}
		else{
			printf("Nota fuera de rango, porfavor ingrese una nota entre %d y %d", LI,LS);
		}
		scanf("%d",&nro);
	}while(nro<li || nro>ls && nro!=exc);
	
	return nro;
}


int cargaIncompleta(int dni[], int nota[], int tamanio){
	int cant=0, dniIngreso, notaIngreso, encuentra;
	
	printf("Ingrese su dni: ");
	scanf("%d",&dniIngreso);
	
	while( dniIngreso > 0 && cant<tamanio){
		encuentra= busqueda(dni, dniIngreso,cant);
		
		if(encuentra!=-1){
			printf("\nDNI duplicado!, porfavor ingrese un DNI distinto");
		}
		else{
			dni[cant]=dniIngreso;
			notaIngreso= valida(0,10);
			nota[cant] = notaIngreso;
			cant++;
		}
		
		printf("\nIngrese su dni: ");
		scanf("%d",&dniIngreso);
		
	}
	
	return cant;

}


// falta:
// ordenado por mayor a menor
// mostrar el listado

