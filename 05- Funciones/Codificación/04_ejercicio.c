/*Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una función
que valide dicho ingreso. Calcular:
a. Cuántos números son primos.
b. Cantidad de números pares.
c. Promedio de los números impares.

Utilizar las siguientes funciones:
- Resto: recibe por parámetro el Dividendo y el Divisor; Retorna el resto.
- EsPar: recibe por parámetro un número; Retorna 1 si es Par, 0 si es Impar; Invoca a la función Resto.
- EsPrimo: recibe por parámetro un número; Retorna 1 si es primo, 0 si no es primo; Invoca a la
función Resto. (un número es primero si solo es divisible por 1 y por sí mismo).
- Promedio: recibe por parámetro la suma y el contador; Retorna el promedio si contador > 0 sino
Retorna 0.*/

#include <stdio.h>

int validarIngreso(int,int,int);
int resto(int,int);
int esPrimo(int);
int esPar(int);
float promedio(int,int);


int main(){
	
	int contprimos = 0, contpares = 0, contimpares = 0, acum = 0;
	int nro,primo,par;
	float prom;
	
	nro=validarIngreso(1,50,-10);
	
	while(nro!=-10){
		
		if(esPrimo(nro)==1){
			contprimos++;
		}
		
		if(esPar(nro)==1){
			contpares++;
		}
		else{
			acum+=nro;
			contimpares++;			
		}	
		
		nro=validarIngreso(1,50,-10);
	}
	
	prom=promedio(acum,contimpares);
	
	printf("\nCantidad de nros primos: %d", contprimos);
	
	printf("\nCantidad de nros pares: %d", contpares);
	
	if(prom==0){
		printf("\nNo se ingresaron nros impares");
	}
	else{
		printf("\nEl promedio de nros impares es: %.2f",prom);
	}
		
	return 0;
		
}


int validarIngreso(int LI, int LS, int FN){
	int band=0;
	int nro;
	
	do{
		if(band==0){
			printf("\n\nIngrese valores positivos entre 1 y 50 (finaliza con -10): ");
			band++;
		}
		else{
			printf("\nIntente nuevamente: ");
		}		
		scanf("%d",&nro);		
		
	}while((nro<LI||nro>LS)&&nro!=FN);
	
	return nro;	
}

int resto(int dividendo, int divisor){
	int resto;
	
	resto=dividendo%divisor;
	
	return resto; 
}

int esPar(int N){
	
	int espar;
	
	if(resto(N,2)==0){
		espar=1;
	}
	else{
		espar=0;
	}
	
	return espar; //retorna 1 si es par, 0 si no es par
	
}

int esPrimo(int N){
	
	int i;
	int esprimo=1; //supongo que es primo 
	
		for(i=2;i<=N*0.5;i++){
			if(resto(N,i)==0){
				esprimo = 0;  //entonces no es primo porque tiene más de un divisor
			}
		}
		
		return esprimo;	 //retorna 1 si es primo, 0 si no es primo
}

float promedio(int suma,int cont){
	float prom;
	
	if(cont==0){
		prom = 0;
	}
	else{
		prom=(float)(suma)/cont;
	}
	return prom;	
}
		
