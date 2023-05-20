/*Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el 50% 
son tarros de 1Lt, el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de 1Lt., 4Lts. 
Y 20 Lts*/

#include <stdio.h>

int main(){
	int cantotal,lts_1,lts_4,lts_20;
	 	
	printf("Ingrese cantidad de total de tarros de pintura que existe en un depósito de una pinturería: ");
	scanf("%d",&cantotal);
	
	lts_1 = cantotal*50/100;
	lts_4 = cantotal*30/100;
	lts_20 = cantotal*20/100;
	
	printf("Cant de tarros de 1Lt: %d \nCant de tarros de 4Lts: %d \nCant de tarros de 20Lts: %d",lts_1,lts_4,lts_20);
	
	return 0;	
}
