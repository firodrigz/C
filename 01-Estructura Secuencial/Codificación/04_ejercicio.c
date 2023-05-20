/*Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas, pulgadas, cms. y mts. 
NOTA: 1 pie = 12 pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.*/

#include <stdio.h>

int main(){
	
	float pies,pulgadas,yardas,cms,mts;
	
	printf("Ingrese medida en pies: ");
	scanf("%f",&pies);
	
	pulgadas = pies * 12;
	yardas = pies / 3;
	cms = pulgadas * 2.54;
	mts = cms / 100;
	
	printf("Conversión pie- \nPulgadas: %.2f\nYardas: %.2f\nCentímetros: %.2f\nMetros: %.2f",pulgadas,yardas,cms,mts);		
	
	return 0;
	
}
