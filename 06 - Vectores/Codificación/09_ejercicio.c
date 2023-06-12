/*Confeccionar un programa para:
a. Generar los vectores necesarios para guardar la información ingresada por teclado. Se ingresa los
datos de 300 artículos diferentes. De cada artículo se ingresa los siguientes datos:
	- Código de artículo (int, entre 1 y 500).
	- Clase de artículo (char, ‘A’ o ‘B’ o ‘C’ o ‘D’).
	- Número de depósito donde se encuentra el artículo (int, entre 1 y 100).
	- Stock (int, entre o y 2000).
	- Punto de reposición (int, entre 500 y 1000).
b. Generar e informar el vector VB, que contenga los códigos de artículos de aquellos que hayan
quedado con el saldo igual a cero.
c. Generar e informar el vector VC, que contengo a los códigos de artículos de aquellos que hayan
quedado con saldo por debajo del punto de reposición.
d. Generar e informar el vector VD, que contengo los códigos de artículos de aquellos que están en los
depósitos entre el 15 y 50.
Informar el/los códigos de el/los artículos que tienen el stock más alto. (puede haber varios artículos que
tienen la misma cantidad de stock).
FUNCIONES:
I. Para generar los vectores del punto a).
II. Para generar el vector VB.
III. Para generar el vector VC.
IV. Para generar el vector VD.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void GenerarArticulos(int [],int [],int [],int [],int, int, int, int, int);
void VectorVB(int [], int [], int);
void VectorVC(int [], int [], int[], int);
void VectorVD(int [], int [], int);
void MayorStock(int [], int [], int);
int EncontrarCodigo(int [], int, int);

int main(){
	int codigos[300], depos[300], stocks[300], repos[300], cont = 1, cod, verif = -1, dep, stock, pRep;
	char clase;
	
	while(cont < 3){
		do{
			printf("Ingrese codigo de articulo (1-500): ");
			scanf("%d", &cod);
			
			verif = EncontrarCodigo(codigos, cont, cod);
			
			if(verif == -1){
				printf("Codigo ya ingresado\n");
			}
		}while(verif == -1);
		fflush(stdin);
		do{
			printf("Ingresar clase de articulo: ");
			scanf("%c",&clase);
			clase = toupper(clase);
		}while(clase != 'A' && clase!= 'B' && clase!= 'C' && clase != 'D');
		
		do{
			printf("Ingresar numero de deposito (1-100): ");
			scanf("%d",&dep);
		}while(dep<1 || dep > 100);
		
		do{
			printf("Ingresar stock (0-200): ");
			scanf("%d",&stock);
		}while(stock<0 || stock > 200);
		
		do{
			printf("Ingresar punto de reposicion (500-1000): ");
			scanf("%d",&pRep);
		}while(pRep < 500 || pRep > 1000);
		
		
		GenerarArticulos(codigos, depos, repos, stocks, cont, cod,dep,stock, pRep);
		cont++;
	}
	
	VectorVB(codigos, stocks, cont);
	VectorVC(codigos, stocks, repos, cont);
	VectorVD(codigos, depos, cont);
	MayorStock(codigos, stocks, cont);
}

void GenerarArticulos(int codigos[], int depos[], int repos[], int stocks[], int i, int cod, int dep, int stock, int pRep){
	codigos[i] = cod;
	depos[i] = dep;
	repos[i] = pRep;
	stocks[i] = stock;
}

void VectorVB(int codigos[], int stocks[], int max){
	int i, vb[max], cont = 0;
	
	for(i = 0; i<max;i++){
		vb[i] = 0;
	}
	
	for(i= 0; i<max;i++){
		if(stocks[i] == 0){
			vb[cont] = codigos[i];
			cont++;
		}
	}
	
	for(i = 0; i < cont; i++){
		printf("El codigo %d tiene saldo 0\n", vb[i]);
	}
}

void VectorVC(int codigos[], int stocks[], int repos[], int max){
	int i, cont = 0, vc[max];
	
	for(i = 0; i<max;i++){
		vc[i] = 0;
	}
	
	for(i = 0; i<max;i++){
		if(stocks[i] < repos[i]){
			vc[cont] = codigos[i];
			cont++;
		}
	}
	printf("CODIGOS CON SALDO MENOR AL PUNTO DE REPOSICION\n");
	for(i = 0; i<cont; i++){
		printf("%d\n", vc[i]);
	}
}

void VectorVD(int codigos[], int depos[], int max){
	int i, cont = 0, vd[max];
	
	for(i = 0; i<max;i++){
		vd[i] = 0;
	}
	
	for(i = 0; i<max;i++){
		if(depos[i] >= 15 && depos[i] <= 50){
			vd[cont] = codigos[i];
			cont++;
		}
	}
	
	printf("CODIGOS entre 15 y 50\n");
	
	for(i = 0; i<cont;i++){
		printf("%d\n", vd[i]);
	}
}

void MayorStock(int codigos[], int stocks[], int max){
	int i, mayor = 0, band = 1;
	
	for(i = 0; i < max; i++){
		if(band == 1 || stocks[i] > mayor){
			mayor = stocks[i];
			band = 0;
		}
	}
	
	for(i = 0; i < max; i++){
		if(stocks[i] == mayor){
			printf("El codigo %d tiene el mayor stock\n", codigos[i]);
		}
	}
}

int EncontrarCodigo(int codigos[], int cont, int cod){
	int i, verif = -1;
	for(i = 0; i < cont; i++){
		if(codigos[i] == cod){
			verif = 0;
		}
		else{
			verif = -1;
		}
	}
}
