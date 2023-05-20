/*Confeccionar un programa que solicite e ingrese 3 valores reales positivos, mayores que cero y determine
e informe si forman o no tri�ngulo. Para ello utilizar el teorema de la desigualdad del tri�ngulo que establece
que la suma de las longitudes de cualesquiera de dos lados de un tri�ngulo es mayor que la longitud del
tercer lado.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int valor_1,valor_2,valor_3;
		
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese 3 valores reales positivos, mayores que cero: \n");
	scanf("%d%d%d",&valor_1,&valor_2,&valor_3);
	
	if(((valor_1+valor_2)>valor_3)&&((valor_1+valor_3)>valor_2)&&((valor_2+valor_3)>valor_1)){
		printf("Es tri�ngulo");
	}
	else{
		printf("No cumple con el teorema de desigualdad, por lo tanto no es tri�ngulo");
	}		
	return 0;
}
