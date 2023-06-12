/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Mostrar:
a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.*/


#include <stdio.h>

#define TAM 60


//Prototipo de funciones
int validarDNI(int,int,int);
int validar(int,int);
int cargaAlumnos(int [],int [],int);
void mostrarListadoIngreso(int [],int [],int);
void mostrarmayor(int[],int [],int);

//main
int main(){
	int vectorDNI[TAM];
	int vectorNOTA[TAM];
	int cant, mayorNota;
	
	
	cant=cargaAlumnos(vectorDNI,vectorNOTA,TAM);
	
	if(cant==0){
		printf("No se ingresaron alumnos");
	}
	else{		
		mostrarListadoIngreso(vectorDNI,vectorNOTA,cant);
		mostrarmayor(vectorDNI,vectorNOTA,cant);					
	}
	
	return 0;
}


//Definición de funciones

int validarDNI(int LI,int LS,int EXC){
	int nro;
	int band=0;
	
	do{
		if(band==0){
			printf("\nIngrese DNI: ");
			band=1;
		}
		else{
			printf("Error! valor de DNI fuera de rango, vuelva a intentarlo: ");
		}
		
		scanf("%d",&nro);
		
	}while((nro>=EXC && nro<LI)|| nro>LS);
	
	return nro;
}


int validar(int LI,int LS){
	int nro;
	int band=0;
	
	do{
		if(band==0){
			printf("Ingrese NOTA: ");
			band=1;
		}
		else{
			printf("Error! valor de NOTA fuera de rango, vuelva a intentarlo: ");
		}
		
		scanf("%d",&nro);
		
	}while(nro<LI||nro>LS);
	
	return nro;
}


int cargaAlumnos(int vDNI[],int vNOTA[],int ce){
	int auxDNI;
	int i=0;
	
	auxDNI=validarDNI(4000000,99999999,0);
	
	while(auxDNI>0 && i<ce){
		vDNI[i]=auxDNI;
		vNOTA[i]=validar(0,10);
		
		i++;
		
		auxDNI=validarDNI(4000000,99999999,0);
		
	}	
	return i;	
}


void mostrarListadoIngreso(int vDNI[],int vNOTA[],int ce){
	int i;
	printf("\nListado de alumnos con DNI y NOTA:\n");
	
	for(i=0;i<ce;i++){
		printf("\t%9d\t%3d\n",vDNI[i],vNOTA[i]);
	}
	
}


void mostrarmayor(int DNI[],int NOTA[],int ce){
	int band=0;
	int i,j, mayor;
	
	for(i=0;i<ce;i++){
		if(band==0){
			mayor=NOTA[i];
			band++;
		}
		else{
			if(NOTA[i]>mayor){
				mayor=NOTA[i];
			}
		}		
	}
	
	printf("\nLa mayor nota fue: %d \n", mayor);
	
	for(j=0;j<i;j++){
		if(NOTA[j]==mayor)
		printf("DNI con nota %d : %9d\n",mayor,DNI[j]);
	}	
}
