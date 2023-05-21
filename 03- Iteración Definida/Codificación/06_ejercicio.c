 /*Se ingresan 50 números enteros. Determinar el promedio de los números pares.*/
 
#include <stdio.h>
#include <locale.h>

int main(){
	int acum,cont = 0;
	int nro,i;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=10;i++){
		printf("\nPosición: %d \nIngrese un número: ",i);
		scanf("%d",&nro);
		
		if((nro%2)==0){
			acum+=nro;
			cont++;
		}
	}
	
	if(cont==0){  //Utilizo cont como bandera y divisor
		printf("No se puede hacer un promedio, ya que no se ingresaron números pares");
	}
	else{
		printf("\n\nPromedio de la suma de los números pares ingresados: %.2f",(float)acum/cont);
	}
		
	return 0;
} 
