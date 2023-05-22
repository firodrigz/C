/*Confeccionar un programa que me permita calcular y mostrar una cantidad de números primos que se
solicita por la pantalla. Los números se calculan a partir del 2. Ejemplo: Si ingreso 6, genero los números: 2 –
3 - 5 - 7 - 11 - 13. El algoritmo para el cálculo de si un número es primo o no, debe estar optimizado para que
si encuentra un divisor no seguir buscando ya que se sabe que no es primo.*/

#include <stdio.h>
#include <locale.h>

int main(){	
	int esprimo,i,j,limite;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese límite: ");
	scanf("%d",&limite);
	
	while(limite>=2){
		int cont = 0; //contador interno
		
		for(i=2;i<=100;i++){
		esprimo=1; //supongo que es primo 
		for(j=2;j<=i*0.5;j++){
			if(i%j==0){
				esprimo = 0;	//entonces no es primo porque tiene más de un divisor
			}
			break; //para que no siga buscando
		}	
			
		if(esprimo==1){
			cont++;	
			if(cont<=limite){
				printf("%d\t",i);
				}			
			}		
		}	
		
		printf("\n\nIngrese límite: ");
		scanf("%d",&limite);
		
	}	
	return 0;
}
