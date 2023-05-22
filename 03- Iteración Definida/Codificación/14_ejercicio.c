/*Realizar un programa que:
a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente
por 1 y por sí mismo)
b. Contar y mostrar la cantidad de primos encontrados.*/

#include <stdio.h>

int main(){
	int cont = 0;
	int esprimo,i,j;
			
	for(i=2;i<=100;i++){
		esprimo=1; //supongo que es primo 
		for(j=2;j<=i*0.5;j++){
			if(i%j==0){
				esprimo = 0;  //entonces no es primo porque tiene más de un divisor
			}
		}
		
		if(esprimo==1){
			cont++;
		}
	}
	
	printf("Cantidad de primos encontrados: %d",cont);
	
	return 0;
}
