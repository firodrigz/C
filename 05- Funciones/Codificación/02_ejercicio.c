/*Se ingresan números enteros comprendidos entre 100 y 2000 (usar función LeerYValidar). Determinar
usando la función EstaDentroDelRango:
a. Cantidad de números ingresados entre 100 y 500
b. Cantidad de números pares ingresados entre 500 y 1200
c. Promedio de números ingresados entre 1200 y 2000
El ingreso de datos finaliza cuando se ingresa un número igual a 99.
Para realizar este programa se deben realizar las siguientes funciones:

- EstaDentroDelRango: que reciba 3 enteros correspondientes a un número a validar y los límites
superior e inferior del rango. La función debe retornar un 1 si el número a validar se encuentra
dentro del rango indicado o un 0 si no lo está.

- LeerYValidar: que reciba los límites superior e inferior de un rango y retorne un número que se
encuentre dentro del mismo. (El ingreso de datos se realiza dentro de la función). Para validar el
rango utilizar la función EstaDentroDelRango realizada en el punto anterior.*/

#include <stdio.h>
#include <locale.h>

//Protocolo de funciones
int EstaDentroDelRango(int,int,int);
int LeerYValidar(int,int);

//main
int main(){
	
	int cont = 0, contPares = 0, acum = 0, contAcum = 0;
	int nroIng;
	float prom;
	
	setlocale(LC_ALL,"spanish");
	
	nroIng=LeerYValidar(99,200);
	
	while(nroIng!=99){
		
		if(EstaDentroDelRango(nroIng,100,500)==1){
			cont++;
		}
		
		if(EstaDentroDelRango(nroIng,500,1200)==1){
			if((nroIng%2)==0){
				contPares++;
			}
		}
		
		if(EstaDentroDelRango(nroIng,1200,2000)==1){
			acum+=nroIng;
			contAcum++;
		}
		
		nroIng=LeerYValidar(99,200);		
	}
	
	prom=(float)(acum)/contAcum;
	
	printf("\nCantidad de números ingresados entre 100 y 500: %d \nCantidad de números pares ingresados entre 500 y 1200: %d \nPromedio de números ingresados entre 1200 y 2000: %.2f ",cont,contPares,prom);
	
	return 0;
}

//Definición de funciones

int EstaDentroDelRango (int nro, int LI, int LS){
	
	int ran;
	
    if ( nro < LI || nro > LS ){
    	ran=0;
	}  	       
  	else
	{
  		ran=1;
	}
	
	return ran;
}

/***************************************************************************/

int LeerYValidar (int LI, int LS){
	
  int nro;
  int band = 0;
  do{
  	  if (band == 0){
  	  	printf("\nIngrese números enteros comprendidos entre 100 y 2000: ");
  	  	band = 1;
  	  }
  	  else{
  	  		printf("\nIngresar nuevamente: ");
		}  	  
		  
	  scanf ("%d", &nro);
	  
    }while (EstaDentroDelRango ( nro, LI, LS)== 0);

  return nro;
}
