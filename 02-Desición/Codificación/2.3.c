/*Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos
es igual a la suma de los otros dos. */

#include <stdio.h>
#include <locale.h>

int main(){
	int n1,n2,n3,suma1,suma2,suma3;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingese 3 números: \n");
	scanf("%d%d%d",&n1,&n2,&n3);
	
	suma1= n2+n3;
	suma2= n1+n3;
	suma3= n1+n2;
	
	if(n1==suma1){
		printf("El primer número es igual a la suma de los otros dos");
	}
	else {
		if(n2==suma2){
			printf("El segundo número es igual a la suma de los otros dos");
		}
		else{
			if(n3==suma3){
				printf("El tercer número es igual a la suma de los otros dos");
			}
		}
	}
	
	return 0;
}
