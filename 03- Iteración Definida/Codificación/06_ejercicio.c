 /*Se ingresan 50 n�meros enteros. Determinar el promedio de los n�meros pares.*/
 
#include <stdio.h>
#include <locale.h>

int main(){
	int acum,cont = 0;
	int nro,i;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=10;i++){
		printf("\nPosici�n: %d \nIngrese un n�mero: ",i);
		scanf("%d",&nro);
		
		if((nro%2)==0){
			acum+=nro;
			cont++;
		}
	}
	
	if(cont==0){  //Utilizo cont como bandera y divisor
		printf("No se puede hacer un promedio, ya que no se ingresaron n�meros pares");
	}
	else{
		printf("\n\nPromedio de la suma de los n�meros pares ingresados: %.2f",(float)acum/cont);
	}
		
	return 0;
} 
