/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
igual a 0. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.

Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota*/


#include <stdio.h>
#define TAM 60

int busqueda(int[], int, int);
int valida(int ,int, int);
int cargaIncompleta(int[], int[], int);
void ordenarMayorMenor(int [], int[], int);
void mostrarListado(int [], int[], int);

int main(){
	int vectorDNI[TAM];
	int vectorNOTA[TAM];
	int ingreso;
			
	ingreso = cargaIncompleta(vectorDNI,vectorNOTA,TAM);
	
	if(ingreso!=0){
		ordenarMayorMenor(vectorDNI,vectorNOTA,ingreso);
		mostrarListado(vectorDNI,vectorNOTA,ingreso);
	} else {
		printf("\nNo se ingresaron datos!");
	}
	
	return 0;
}

int busqueda(int Vdni[], int nro, int hasta){
	int i=0, encuentra=-1;
	
	while(i<hasta && encuentra==-1){
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
			printf("Ingrese valor entre %d y %d: ", LI,LS);
			band++;
		}
		else{
			printf("Valor fuera de rango, porfavor ingrese un valor entre %d y %d: ", LI,LS);
		}
		scanf("%d",&nro);
	}while((nro<LI || nro>LS) && nro!=exc);
	
	return nro;
}


int cargaIncompleta(int dni[], int nota[], int tamanio){
	int cant=0, dniIngreso, notaIngreso, encuentra;
	
	printf("Ingrese su DNI (termina carga con DNI = 0) \n ");
	dniIngreso= valida(11111111,99999999,0);
	
	while(dniIngreso != 0 && cant<tamanio){
		encuentra= busqueda(dni, dniIngreso,cant);
		
		if(encuentra!=-1){
			printf("\nDNI duplicado!, porfavor ingrese un DNI distinto");
		}
		else{
			dni[cant]=dniIngreso;
			printf("\nIngrese nota \n");
			notaIngreso= valida(0,10,10);
			nota[cant] = notaIngreso;
			cant++;
		}
		
		printf("\nIngrese su DNI (termina carga con DNI = 0) \n ");
		dniIngreso= valida(11111111,99999999,0);
		
	}
	
	return cant;

}

void ordenarMayorMenor(int dni[], int nota[], int tam){
	int i, j, aux;
	for(i=0;i<tam-1;i++){
		for(j=0;j<tam-1-i;j++){
			if(nota[j] < nota[j+1]){
				aux=dni[j];
				dni[j]=dni[j+1];
				dni[j+1]=aux;
				
				aux=nota[j];
				nota[j]=nota[j+1];
				nota[j+1]=aux;
			}
		}
	}
}

void mostrarListado(int dni[], int nota[], int tam){
	int i;
	printf("\nListado de dni y notas ordenados de mayor a menor\n");
	for(i=0;i<tam;i++){
		printf("%d \t %d \n", dni[i], nota[i]);
	}
}

