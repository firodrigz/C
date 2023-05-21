/*Ingresar 3 valores reales y:
a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
b. Si los tres son iguales informar “TRES IGUALES .
c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”.*/

#include <stdio.h>
#include <locale.h>

int main(){	
	int v1,v2,v3;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese 3 valores: ");
	scanf("%d%d%d",&v1,&v2,&v3);
	
	if((v1==v2)&&(v2==v3)){
		printf("TRES IGUALES");		
	}
	else{
		if((v1>v3)&&(v2>v3)){
			printf("MAYORES AL TERCERO");	
		}
		else{
			printf("ALGUNO ES MENOR");
		}		
	}
	return 0;
	
}
