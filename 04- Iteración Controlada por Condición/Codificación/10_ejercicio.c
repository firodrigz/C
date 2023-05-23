/*En un proceso de control se evalúan valores de temperatura, finalizando cuando de ingresa un valor
ficticio de temperatura -50. Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso.*/

#include <stdio.h>
#include <locale.h>

int main(){
	
	int cont=0;
	int tMax,tMin,pMax,pMin,temp;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese valor de temperatura: ");
	scanf("%d",&temp);
	
	while(temp!=-50){
		cont++;   
	    
	     if (cont == 1)
	     {
	       tMax = temp;
		   tMin = temp;
		   pMax = cont;
		   pMin = cont;
	     }
	    else
	       if (temp > tMax){
	       		tMax = temp;
	           	pMax = cont;
		   }
	           
	       else
		      if (temp < tMin)
		         {
		           tMin = temp;
				   pMin = cont;
		         }
		         
		printf("Ingrese valor de temperatura: ");
		scanf("%d",&temp);		
	}
	   
	printf("\nLa temperatura mayor: %d ",tMax);
	printf("\nLa temperatura menor: %d ",tMin);
	printf("\nLa posicion de la temperatura mayor: %d ",pMax);
	printf("\nLa posicion de la temperatura menor: %d ",pMin);	
	
	return 0;
}
