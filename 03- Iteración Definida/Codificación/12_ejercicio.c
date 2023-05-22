/*Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres
valores seguidos) de valores positivos y cuantas de negativos hay.*/

#include <stdio.h>
#include <locale.h>

int main(){
	int cneg = 0 , ctneg = 0;
	int cpos = 0 , ctpos = 0;
	int i,temp;
	
	setlocale(LC_ALL,"spanish");
	
	for(i=1;i<=18;i++){
		printf("Ingrese temperatura diferente de 0: ");
		scanf("%d",&temp);
		
		if(temp>0){
			cneg=0;
			cpos++;
			if(cpos>2){
				ctpos++;
				cpos=0;
			}
		}
		else{
			cpos=0;
			cneg++;
			if(cneg>2){
				ctneg++;
				cneg=0;
			}
		}
	}
	
	printf("Se ingresaron %d ternas positivas y %d ternas negativas",ctpos,ctneg);
	
	
	return 0;
}



