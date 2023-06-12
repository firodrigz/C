/*Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la informaci�n ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la ra�z cuadrada del respectivo elemento de VA.
(para el c�lculo de la ra�z cuadrada utilizar la funci�n sqrt disponible en la biblioteca math.h). Si el
n�mero es negativo poner un 0 ya que no se puede calcular la ra�z
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor m�ximo del vector VA y en qu� posici�n se hall� (el mayor es �nico).
f. Hallar el valor m�nimo del vector VB y en qu� posiciones se hallaron (el m�nimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qu� posici�n se encontr� del vector VC.
h. Mostrar el contenido de todos los vectores.

FUNCIONES:
I. Para el ingreso del vector VA, del punto a).
II. Para generar el vector VC, del punto c).
III. Para realizar la b�squeda del punto g).
IV. Para generar el vector VE del punto i).
V. Para mostrar los valores de todos los vectores del punto j).*/

#include <stdio.h>
#include <math.h>

#define TAM 10

//Prototipo de funciones
void carga(float[],int);
void mostrar(float[],int);
void raiz(float[],float[],int);
void sumaVectores(float[],float[],float[],int);
void ordenInverso(float[],float[],int);
int busqueda(float[],int,float);
void valorMaximo(float[],int);
void valorMinimo(float[],int);


//main
int main(){
	float VA[TAM];
	float VB[TAM];
	float VC[TAM];
	float VD[TAM];
	float BUS;
	int pos;
	
	
	carga(VA,TAM);
	raiz(VA,VB,TAM);
	sumaVectores(VA,VB,VC,TAM);
	ordenInverso(VC,VD,TAM);
	valorMaximo(VA,TAM);
	valorMinimo(VB,TAM);
	
	printf("\nIngrese un valor a buscar en el vector VC: ");
	scanf("%f",&BUS);	
	pos=busqueda(VC,TAM,BUS);
	if(pos==-1){
		printf("\nNo se encontr� el vector que busca\n");
	}
	else{
		printf("Se encontr� en la posici�n: %d",pos);
	}
	
	return 0;
}


//Definici�n de funciones

void carga(float v[],int ce){
	int i;
	
	printf("Carga del vector \n ");
	for(i=0;i<ce;i++){
		printf("Ingrese valor: ");
		scanf("%f",&v[i]);
	}		
}

void mostrar(float v[], int ce){
	int i;
	
	for(i=0;i<ce;i++){
		printf("\n\t%.2f",v[i]);
	}
	
}

void raiz(float VA[],float VB[],int ce){
	int i;
	
	for(i=0;i<ce;i++){
		if(VA[i]>=0){
			VB[i]=sqrt(VA[i]);
		}
		else{
			VB[i]=0;
		}
	}
	
	printf("\nMuestra de vector aplicada raices\n");
	mostrar(VB,ce);
}

void sumaVectores(float VA[],float VB[],float VC[],int ce){
	int i;
	
	for(i=0;i<ce;i++){
		VC[i]=VA[i]+VB[i];
	}	
	
	printf("\nMuestra de vector que contiene la suma de los elementos de VA y VB\n");
	mostrar(VC,ce);
}

void ordenInverso(float VC[],float VD[],int ce){
	int i,j;
	
	for(i=ce-1, j=0; i>=0 && j<ce; i--, j++){    //0 1 2 3  memoria
		VD[j]=VC[i];							// 5 3 2 1  ingreso
	}	
	
	printf("\nMuestra vector invertido\n");
	mostrar(VD,ce);	
}

int busqueda(float v[],int ce,float x){
	int i=0;
	int pos=-1;
	
	while(i<ce && pos==-1){
		if(v[i]==x){
			pos=i;
		}
		else{
			i++;
		}		
	}
	
	return pos;
	
}

void valorMaximo(float VA[],int ce){
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
	
	printf("\nEl mayor es: %.2f\n",mayor);
	pos=busqueda(VA,ce,mayor); //no se repite entonces uso la funci�n b�squeda
	printf("\nEncontrado en la posici�n: %d", pos);
}

void valorMinimo(float VB[],int ce){
	int band=0;
	int i,pos;
	float menor;
	
	
	for(i=0;i<ce;i++){
		if(band==0){
			menor=VB[i];
			band=1;
		}
		else{
			if(VB[i]<menor){
				menor=VB[i];
			}
		}		
	}
	
	printf("\nEl menor es: %.2f\n",menor);
	for(i=0;i<ce;i++){
		if(VB[i]==menor)
		printf("\nEncontrado en la posici�n: %d\n",i);
	}
	
}
