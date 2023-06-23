/*Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
- Número de lista
- Número de sede
- Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0

Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
LISTA 	SEDE1 	SEDE2 	SEDE3… 	SEDE15
873 	 36 	 78 	 99… 	 XX
735 	 XX 	 XX 	XXX… 	 XX
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
TOTAL DE VOTOS 		PORCENTAJE 		LISTA
		800 			80% 		 873
		200 			20% 		 735
c. Candidatos que NO recibieron votos en la sede 5.


10 candidatos (nro de 3 cifras no correlativo) por 15 sedes(del 1 al 15) 
se ingresan cantidad de votos por acceso directo
carga d datos finaliza con nro de lista d candidato = 0

carga de candidatos en vectorCandidatos
carga de
*/

#include <stdio.h>
#define CANDIDATOS 10
#define SEDES 15

int ingresaValida(int,int,int);
int busqueda(int [],int,int);
void cargaVector(int [],int);
int datosIngreso(int [][SEDES],int [],int,int);

int main(){
	int vectorCandidatos[CANDIDATOS]={0};
	int matrizVotos[CANDIDATOS][SEDES]={{0}};
	
	cargaVector(vectorCandidatos,CANDIDATOS);
	datosIngreso(matrizVotos,vectorCandidatos,CANDIDATOS,SEDES);
	
	
	return 0;
}

int ingresaValida(int LI, int LS, int EXC){
	int nro, band = 0;
	
	do{
		if(band==0){
			printf("Ingrese valor entre %d - %d : ",LI,LS);
			band=1;
		}
		else{
			printf("Error!, vuelva a ingresar valor entre %d - %d",LI,LS);
		}
		
		scanf("%d",&nro);
		
	}while( (nro<LI || nro>LS) && nro!=EXC);	
	
	return nro;
}

int busqueda(int vector[], int tam, int x){
	int i, encuentra = -1;
	
	while(encuentra == -1 && i<tam){
		if(vector[i]==x){
			encuentra=i;
		}
		else{
			i++;
		}
	}
		
	return encuentra;
}

void cargaVector(int candidatos[],int tamVector){
	int i,ingreso,encuentra,band=0;	
	
	printf("Carga de nro de lista de candidato\n");
	
	for(i = 0;i < tamVector; i++){
		do{
			if(band==0){
				band=1;			
			}
			else{
				printf("\nValor ya ingresado\n");
			}
			
			ingreso=ingresaValida(100,999,999);
			encuentra=busqueda(candidatos,tamVector,ingreso);
			
		}while(encuentra!=-1);
		
		candidatos[i]=ingreso;		
	}
}


int datosIngreso(int votos[][SEDES],int vectorCandidatos[], int candidatos,int sedes){
	int ingresos, nroLista, sede, votosTotales, encuentra, band=0;
	
	do{
		if(band==0){
			printf("-- Nro de lista --");
			band=1;
		}
		else{
			printf("\nValor ingresado no pertenece a un candidato, porfavor ingrese otro: \n");
		}
		
		nroLista = ingresaValida(100,999,0);
		encuentra=busqueda(vectorCandidatos,candidatos,nroLista);	
	}while(encuentra==-1);
	
	while(nroLista!=0){
		
		
		printf("-- Nro de Sede --");
		sede = ingresaValida(1,15,15);
		
		printf("-- Cantidad de votos --");
		votosTotales = ingresaValida(0,99999999,99999999);
		
		
		
		printf("-- Nro de lista --");
		nroLista = ingresaValida(100,999,0);	
	}
	
	return ingresos;
}

