/*Confeccionar un programa que pueda determinar de 3 n�meros enteros que se ingresan si alguno de ellos
es igual a la suma de los otros dos. */

#include <stdio.h>
#include <locale.h>

int main(){
	int n1,n2,n3,suma1,suma2,suma3;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingese 3 n�meros: \n");
	scanf("%d%d%d",&n1,&n2,&n3);
	
	suma1= n2+n3;
	suma2= n1+n3;
	suma3= n1+n2;
	
	if(n1==suma1){
		printf("El primer n�mero es igual a la suma de los otros dos");
	}
	else {
		if(n2==suma2){
			printf("El segundo n�mero es igual a la suma de los otros dos");
		}
		else{
			if(n3==suma3){
				printf("El tercer n�mero es igual a la suma de los otros dos");
			}
		}
	}
	
	return 0;
}
